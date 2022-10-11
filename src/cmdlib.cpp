/**
 * ===============================================
 * ===============================================
 * *\src\cmdlib.cpp
 * ===============================================
 * ===============================================
 * 
 * start time 2022.10.11
 */

#include<cmdlib.h>

void cmdlib::show_help(){
    std::string cmdlib_json_path( clinfo::__cwd__ ); // get cmdlib.json path (begin with Arduino_Task.exe path)
    cmdlib_json_path.erase( cmdlib_json_path.rfind( "\\bin" ) ).append( "\\json\\cmdlib.json" );
    // delete "\\bin" in __cwd__, add "\\json\\cmdlib.json" to point to cmdlib.json
    
    rfile.open( cmdlib_json_path.c_str() , std::ios::in );
    rJson.parse( rfile , cmdlib_json , 0 );
    // open cmdlib.json

    rfile.close();
    // release rfile


}