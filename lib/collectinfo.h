/**
 * ===============================================
 * ===============================================
 * *\lib\collectinfo.h
 * ===============================================
 * ===============================================
 * 
 * \brief collect infos, including time, current working directory, system infos
 * \def \c namespace \c clinfo
 * \def \c __ltn__ local time now
 * \def \c __cwd__ current working dirctory for Arduino_Task.exe
 * \def \c __NOW__ system time now
 * 
 * start time: 2022.10.06
 */

#ifndef _COLLECTINFO_H_
#define _COLLECTINFO_H_

#include<direct.h>
#include<time.h>
#include<stdint.h>

namespace clinfo{

    char* __cwd__ = getcwd( NULL , 0 ); // current working dirctory

    time_t __NOW__ = time( 0 ); // system time now
    tm *__ltn__ = localtime( &__NOW__ ); // local time now

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
    
} // namespace clinfo


#endif