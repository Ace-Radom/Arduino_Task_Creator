/**
 * ===============================================
 * ===============================================
 * *\src\artask.cpp
 * ===============================================
 * ===============================================
 * 
 * start time: 2022.10.18
 */

#include<artask.h>

#pragma region public_function

/**
 * \brief create one ARTask class
 * \param _no_use truly, exactly, 100% useless
 */
ARTask::ARTask( STATUS_t _no_use ){
    pre_set();
    return;
}

/**
 * \brief change the arduino board type
 * \param _board_type the arduino board type (e.g. arduino:avr:uno)
 */
void ARTask::change_board( std::string _board_type ){
    arduino_board = _board_type;
    is_board_set = _SET_;
    return;
}

/**
 * \brief change serial port in use to connect arduino
 * \param _port the serial port in use
 */
void ARTask::change_serial_port( std::string _port ){
    serial_port = _port;
    is_serial_port_set = _SET_;
    return;
}
/**
 * \brief set taskfile path in \c ARTask class
 * \param _path the path of the taskfile
 */
void ARTask::set_taskfile( PATH_t _path ){
    if ( path::is_relative_path( _path ) )
    {
        taskfile_path = path::_fullpath( _path );
        is_using_taskfile = _USING_;
        return;
    }
    taskfile_path = _path;
    is_using_taskfile = _USING_;
    return;
}

/**
 * \brief set arduino program file path in \c ARTask class
 * \param _path the path of the arduino program
 */
void ARTask::set_arduino_file( PATH_t _path ){
    if ( path::is_relative_path( _path ) )
    {
        arduino_file_path = path::_fullpath( _path );
        is_arduino_file_set = _SET_;
        return;
    }
    arduino_file_path = _path;
    is_arduino_file_set = _SET_;
    return;
}

/**
 * \brief set program mode (verify or upload)
 * \param _option \c _verify_ or \c _upload_
 */
void ARTask::set_verify_or_upload( STATUS_t _option ){
    is_verify_or_upload = _option;
    return;
}

/**
 * \brief read board type, serial port, arduino program file path from taskfile,
 * \brief only read when these data aren't set by type-in options
 * \param _path taskfile path
 */
void ARTask::read_taskfile(){
    if ( !is_using_taskfile )
    {
        return;
        // here needs to be completed with the status not set a taskfile but function be triggered
    }

    rwFile.open( taskfile_path.c_str() , std::ios::in );
    rJson.parse( rwFile , artask_json , 0 );

    rwFile.close();

#pragma region read_taskfile

    if ( !is_board_set && artask_json.isMember( "arduino_board" ) ) // read board type
    {
        if ( !artask_json["arduino_board"].asString().empty() ) // this key isn't empty
        {
            is_board_set = _SET_;
            arduino_board = artask_json["arduino_board"].asString();
        }
    }

    if ( !is_serial_port_set && artask_json.isMember( "port" ) ) // read serial port
    {
        if ( !artask_json["port"].asString().empty() ) // this key isn't empty
        {
            is_serial_port_set = _SET_;
            serial_port = artask_json["port"].asString();
        }
    }

    if ( !is_arduino_file_set && artask_json.isMember( "arduino_file" ) ) // read arduino program
    {
        if ( !artask_json["arduino_file"].asString().empty() ) // this key isn't empty
        {
            is_arduino_file_set = _SET_;
            arduino_file_path = artask_json["arduino_file"].asString();
        }
    }

#pragma endregion read_taskfile

    artask_json.clear();
    return;

}

/**
 * \brief start sending command
 */
void ARTask::start(){
    if ( is_using_taskfile )
    {
        read_taskfile();
    }

    if ( is_board_set            == _SET_ &&  // check if all settings making commands needs is ready, including Arduino board
         is_serial_port_set      == _SET_ &&  //                                                                 serial port connects to Arduino board
         is_arduino_file_set     == _SET_ &&  //                                                                 Arduino program file (.ino)
         is_verify_or_upload_set == _SET_ )   //                                                                 program mode (verify or upload)
    {
        
        make_command();
        std::cout << command << std::endl;

        //system( command.c_str() );
        return;
    }

#pragma region error-occurs

    if ( !is_board_set )
    {
        std::cout << "Arduino Board type not set"   << std::endl
                  << "You can use \"-b\" to set it" << std::endl;
    }

    if ( !is_serial_port_set )
    {
        std::cout << "Serial port not set"                                                          << std::endl
                  << "You can use \"-p\" to set it"                                                 << std::endl
                  << "Maybe try \"-device\" to see which serial port does your Arduino connect to?" << std::endl;
    }

    if ( !is_arduino_file_set )
    {
        std::cout << "Arduino program file not set"                                   << std::endl
                  << "Add Arduino program file path after \"-v\" or \"-u\" to set it" << std::endl;
    }

    if ( !is_verify_or_upload_set )
    {
        std::cout << "Program work mode not set (verify or upload)" << std::endl
                  << "Add \"-v\" or \"-u\" option to set it"        << std::endl;
    }

#pragma endregion error-occurs

    return;
}

void ARTask::test(){
    write_atccreatetasktemp_json();
}

#pragma endregion public_function

#pragma region private_function

/**
 * \brief pre-set all vars in class
 */
void ARTask::pre_set(){
    arduino_board.clear();
    serial_port.clear();
    arduino_file_path.clear();
    taskfile_path.clear();

    is_help_triggered   = _NOT_USING_;
    is_using_taskfile   = _USING_; // in 1.0 there must set one task file
    is_board_set        = _NOT_SET_;
    is_serial_port_set  = _NOT_SET_;
    is_arduino_file_set = _NOT_SET_;
    is_verify_or_upload = _NOT_SET_;
}

/**
 * \brief write Arduino_Task_Creator Task create temp json
 */
void ARTask::write_atccreatetasktemp_json(){
    rwFile.open( taskfile_path.c_str() , std::ios::in );
    rJson.parse( rwFile , artask_json , 0 );

    rwFile.close();

    Json::Value atc_createtask_temp;
    Json::StyledStreamWriter sw; // json file writer

    std::string program_work_mode;
    
    switch ( is_verify_or_upload ){
        case _verify_:
            program_work_mode = "verify_args";
            break;
        
        case _upload_:
            program_work_mode = "upload_args";
            break;
    }
    // judge if is using verify or upload

    atc_createtask_temp["label"] = artask_json["label"];
    atc_createtask_temp["comand_mode"] = artask_json["commands"]["command_mode"];
    atc_createtask_temp["args"].append( artask_json["commands"][program_work_mode] );
    atc_createtask_temp["compiler"] = artask_json["compiler"];
    atc_createtask_temp["compilerTag"] = artask_json["compilerTag"];
    atc_createtask_temp["arduino_board"] =  Json::Value( arduino_board );
    atc_createtask_temp["port"] = Json::Value( serial_port );
    atc_createtask_temp["arduino_file"] = Json::Value( arduino_file_path );
    // write all datas making command needs to atc_createtask_temp


    rwFile.open( "atc_createtask_temp.json" , std::ios::out | std::ios::app );

//  sw.write( std::cout , atc_createtast_temp );
    // debug line

    sw.write( rwFile , atc_createtask_temp );
    // write atc_createtask_temp.json

    artask_json.clear();
    atc_createtask_temp.clear();
    return;
}

/**
 * 
 */
void ARTask::make_command(){

}

#pragma endregion private_function

std::string delete_jsontag_sign( std::string origin_tag ){
    return origin_tag.substr( 2 , origin_tag.length() - 3 );
}