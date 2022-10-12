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
 */

#include<cmdlib.h>

/**
 * \brief show help page in shell
 */
void cmdlib::show_help(){

    Json::Value cmdlib_json; // save data read from cmdlib.json
    Json::Reader rJson; // json reader
    std::ifstream rfile; // read file (cmdlib.json)
    
    std::string cmdlib_json_path( clinfo::__cwd__ ); // get cmdlib.json path (begin with Arduino_Task.exe path)
    cmdlib_json_path.erase( cmdlib_json_path.rfind( "\\bin" ) ).append( "\\json\\cmdlib.json" );
    // delete "\\bin" in __cwd__, add "\\json\\cmdlib.json" to point to cmdlib.json
    
    rfile.open( cmdlib_json_path.c_str() , std::ios::in );
    rJson.parse( rfile , cmdlib_json , 0 );
    // open cmdlib.json

    rfile.close();
    // release rfile

#pragma region print_help

#define _option_ 0
#define _expression_ 1

    std::string language_tag; // save the language-tag of the help page
    // it depends on system ui language (if it's zh_CN then will show chinese expression)

    if ( clinfo::__ui_language__ == zh_CN ) // is using zh_CN as system ui language
    {
        language_tag = "Chinese_Expressions"; // it's the tag of the array includes all chinese expressions
    }
    else
    {
        language_tag = "English_Expressions"; // it's the tag of the array includes all english expressions
    }


#undef _option_
#undef _expression_

#pragma endregion print_help

}

void cmdlib::setw_print_help( std::string __option , std::string __expression ){
    std::cout << "  " << std::left << std::setw( 12 ) << __option;
    std::cout                                                     << __expression << std::endl;
    return;
}