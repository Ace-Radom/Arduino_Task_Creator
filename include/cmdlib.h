/**
 * ===============================================
 * ===============================================
 * *\include\cmdlib.h
 * ===============================================
 * ===============================================
 * 
 * \brief give back commands expressions (show help by -?), connect @a cmdlib.json
 * \def \c namespace \c cmdlib
 *      \def \c void \c show_help show help page in shell
 *      \def \c void \c setw_print_help print options and expressions in help page in order
 * 
 * start time: 2022.10.06
 * 
 * 2022.10.12 move \c Json::Value \c codlib_json 
 *                 \c Json::Reader \c rJson 
 *                 \c std::ifstream \c rfile to \c show_help function in @a cmdlib.cpp
 * 2022.10.13 new \include gflags lib (in @a gflags.h for analysising options)
 *            new \def gflags options, defined in @a cmdlib.cpp region \c gflags_def
 *                                     declared in @a cmdlib.h region \c gflags_dec
 */

#ifndef _CMDLIB_H_
#define _CMDLIB_H_

#include<iostream>
#include<iomanip>
#include<direct.h>
#include<string>
#include<fstream>

#include<json/json.h>
#include<gflags/gflags.h>
#include<collectinfo.h>

/*
#ifdef __cwd_cmdlib__

    #pragma message( "__cwd_cmdlib__ has already been defined as " __cwd_cmdlib__ )

#endif
 */

#pragma region gflags_dec

DECLARE_bool( h );
DECLARE_string( v );
DECLARE_string( u );
DECLARE_string( t );
DECLARE_string( b );
DECLARE_string( p );

#pragma endregion gflags_dec

namespace cmdlib{

    void show_help();
    void setw_print_help( std::string , std::string );

} // namespace cmdlib

#endif