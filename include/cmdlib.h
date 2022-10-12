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
 * 2022.10.12 move \c Json::Value \c codlib_json 
 *                 \c Json::Reader \c rJson 
 *                 \c std::ifstream \c rfile to \c show_help function in @a cmdlib.cpp
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