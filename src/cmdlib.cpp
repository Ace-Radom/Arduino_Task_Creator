/**
 * ===============================================
 * ===============================================
 * *\src\cmdlib.cpp
 * ===============================================
 * ===============================================
 * 
 * start time 2022.10.11
 * 
 * 2022.10.11 finish function \c setw_print_help and tested (passed)
 * 2022.10.12 finish function \c show_help and tested (passed)
 */

#include<cmdlib.h>

/**
 * \brief show help page in shell
 */
void cmdlib::show_help(){
    Json::Value cmdlib_json; // save data read from cmdlib.json
    Json::Reader rJson; // json reader
    std::ifstream rfile; // read file
    
    std::string cmdlib_json_path( clinfo::__exepath__ ); // get cmdlib.json path (begin with Arduino_Task.exe path)

    switch ( clinfo::__ui_language__ ){  // switch system ui language
        case zh_CN:
            cmdlib_json_path.erase( cmdlib_json_path.rfind( "\\bin" ) ).append( "\\json\\cmdlib_zhCN.json" );
            // point to .\json\cmdlib_zhCN.json

//          cmdlib_json_path.erase( cmdlib_json_path.rfind( "\\bin" ) ).append( "\\json\\cmdlib_en.json" );
            // this is a debug line for testing .\json\cmdlib_en.json

            break;
    
        default:
            cmdlib_json_path.erase( cmdlib_json_path.rfind( "\\bin" ) ).append( "\\json\\cmdlib_en.json" );
            // point to .\json\cmdlib_en.json
            break;
    }
    // delete "\\bin" in __cwd__, add .json path to point to cmdlib.json in different languages

#pragma region print_help

    rfile.open( cmdlib_json_path.c_str() , std::ios::in );
    rJson.parse( rfile , cmdlib_json , 0 );
    // open cmdlib.json

    rfile.close();
    // release rfile

#define _option_ 0
#define _expression_ 1

    setw_print_help( cmdlib_json["no_option"][_option_].asString() , cmdlib_json["no_option"][_expression_].asString() );
    setw_print_help( cmdlib_json["-?"][_option_].asString() , cmdlib_json["-?"][_expression_].asString() );
    setw_print_help( cmdlib_json["-v"][_option_].asString() , cmdlib_json["-v"][_expression_].asString() );
    setw_print_help( cmdlib_json["-u"][_option_].asString() , cmdlib_json["-u"][_expression_].asString() );
    setw_print_help( cmdlib_json["-t"][_option_].asString() , cmdlib_json["-t"][_expression_].asString() );
    setw_print_help( cmdlib_json["-b"][_option_].asString() , cmdlib_json["-b"][_expression_].asString() );
    setw_print_help( cmdlib_json["-p"][_option_].asString() , cmdlib_json["-p"][_expression_].asString() );
    // print all options' comment

#undef _option_
#undef _expression_

    cmdlib_json.clear();
    // release cmdlib_json

#pragma endregion print_help

    return;
}

void cmdlib::setw_print_help( std::string __option , std::string __expression ){
    std::cout << "  " << std::left << std::setw( 12 ) << __option;
    std::cout                                                     << __expression << std::endl;
    return;
}