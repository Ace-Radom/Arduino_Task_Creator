/**
 * ===============================================
 * ===============================================
 * *\include\collectinfo.h
 * ===============================================
 * ===============================================
 * 
 * \brief collect infos, including time, current working directory, system infos
 * \def \c namespace \c clinfo
 *      \def \c __ltn__ local time now
 *      \def \c __cwd__ current working dirctory for Arduino_Task.exe
 *      \def \c __NOW__ system time now
 *      \def \c __ui_language__ system ui language
 *      \def \c void \c Print_SystemInfo print system infos @a OSRead.ps1 got
 * 
 * start time: 2022.10.06
 * 
 * 2022.10.11 finished with \c __ltn__ 
 *                          \c __cwd__ 
 *                          \c __NOW__ 
 *                          \c __ui_language__
 *                          \c void \c Print_SystemInfo
 * 2022.10.12 add \c extern before all vars in \c namespace \c clinfo
 *            move \c __ltn__ 
 *                 \c __cwd__ 
 *                 \c __NOW__ 
 *                 \c __ui_language__ defs to @a collectinfo.cpp
 */

#ifndef _COLLECTINFO_H_
#define _COLLECTINFO_H_

#include<direct.h>
#include<time.h>
#include<stdint.h>
#include<windows.h>
#include<winnls.h>
//#include<cstdio>

#define zh_CN 0x0804 // if system ui language is chinese symplified, __ui_language__ will be same as this number

namespace clinfo{

    extern char* __cwd__; // current working dirctory

    extern time_t __NOW__; // system time now
    extern tm *__ltn__; // local time now
    extern LANGID __ui_language__; // get system ui language

/**
 * \brief unused struct \c clinfo_ltn_sort
 * used to prepare one struct type for saving sorted local time but end up to be unused
 * \code
    struct clinfo_ltn_sort{
        uint16_t YEAR;
        uint16_t MONTH;
        uint16_t DAY;
        uint16_t HOUR;
        uint16_t MIN;
        uint16_t SEC;
    }__ltns__;
 *  \endcode
 */

    /**
     * \brief Print System infos (CPU, Operating system, Physic RAM, Powershell edition), requires Powershell scripts
     * \return none, but print the infos @a OSRead.ps1 got
     */
    void Print_SystemInfo();

    void preprocess();
    
} // namespace clinfo


#endif