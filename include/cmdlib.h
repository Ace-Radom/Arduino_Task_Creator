/**
 * ===============================================
 * ===============================================
 * *\include\cmdlib.h
 * ===============================================
 * ===============================================
 * 
 * \brief give back commands expressions (show help by -?), connect @a cmdlib.json
 * \def \c namespace \c cmdlib
 *      \def \c __cwd_cmdlib__
 * 
 * start time: 2022.10.06
 * 
 * 2022.10.11 change \c Json::Value name from \c cmdlib \c rJson because of appeared errors in @a mingw32-make (same name)
 */

#ifndef _CMDLIB_H_
#define _CMDLIB_H_

#include<jsoncpp>
#include<direct.h>

#ifdef __cwd_cmdlib__

    #pragma message( "__cwd_cmdlib__ has already been defined as " __cwd_cmdlib__ )

#endif

Json::Value rJson;
Json::Reader reader;
std::fstream RWJson; // read and write .json (cmdlib.json)

namespace cmdlib{
    char* __cwd_cmdlib__;

    void show_help();

} // namespace cmdlib

#endif