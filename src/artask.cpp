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
 */
ARTask::ARTask(){
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

#pragma endregion private_function