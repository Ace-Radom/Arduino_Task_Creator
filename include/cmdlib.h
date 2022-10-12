/**
 * ===============================================
 * ===============================================
 * *\include\cmdlib.h
 * ===============================================
 * ===============================================
 * 
 * \brief give back commands expressions (show help by -?), connect @a cmdlib.json
 * \def \c namespace \c cmdlib
 * 
 * start time: 2022.10.06
 * 
 * 2022.10.11 change \c Json::Value name from \c cmdlib \c cmdlib_json because of appeared errors in @a mingw32-make (same name)
 */

#ifndef _CMDLIB_H_
#define _CMDLIB_H_

#include<iostream>
#include<iomanip>
#include<direct.h>
#include<string>
#include<fstream>

#include<json/json.h>
#include<collectinfo.h>

/*
#ifdef __cwd_cmdlib__

    #pragma message( "__cwd_cmdlib__ has already been defined as " __cwd_cmdlib__ )

#endif
 */

namespace cmdlib{

    void show_help();
    void setw_print_help( std::string , std::string );

} // namespace cmdlib

#endif