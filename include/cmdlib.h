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
 *      \def \c void \c show_serial_device check and show serial device
 *      \def \c void \c show_serial_ports_reg check and show serial ports from Registry
 * 
 * start time: 2022.10.06
 * 
 * 2022.10.12 move \c Json::Value \c codlib_json 
 *                 \c Json::Reader \c rJson 
 *                 \c std::ifstream \c rfile to \c show_help function in @a cmdlib.cpp
 * 2022.10.13 new \include gflags lib (in @a gflags.h for analysising options)
 *            new \def gflags options, defined in @a cmdlib.cpp region \c gflags_def
 *                                     declared in @a cmdlib.h region \c gflags_dec
 * 2022.10.21 new \def device opition
 *            new \def \c void \c show_serial_device check and show serial device
 *            new \def regport opition
 *            new \def \c void \c show_serial_ports_reg check and show serial ports from Registry
 */

#ifndef _CMDLIB_H_
#define _CMDLIB_H_

#include<iostream>
#include<iomanip>
#include<direct.h>
#include<string>
#include<fstream>
#include<windows.h>

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
DECLARE_bool( device );
DECLARE_bool( regport );

static std::string gHelp;
static std::string gVersion;

std::string gPrint_pro_help();
std::string gPrint_version();

#pragma endregion gflags_dec

namespace cmdlib{

    void show_help();
    void setw_print_help( std::string , std::string );

    void show_serial_device();
    void show_serial_port_reg();

} // namespace cmdlib

#endif