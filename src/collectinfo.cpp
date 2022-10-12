/**
 * ===============================================
 * ===============================================
 * *\src\collectinfo.cpp
 * ===============================================
 * ===============================================
 * 
 * start time: 2022.10.11
 * 
 * 2022.10.11 finish function \c Print_SystemInfo (may need to re-write)
 */

#include"collectinfo.h"

/*
void clinfo::Print_SystemInfo(){
    system( "powershell .\\src\\OSRead.ps1" ); // run powershell script
    return;
}
*/

char* clinfo::__cwd__ = getcwd( NULL , 0 );
char* clinfo::__exepath__ = _pgmptr;

time_t clinfo::__NOW__ = time( 0 );
tm* clinfo::__ltn__ = localtime( &__NOW__ );
LANGID clinfo::__ui_language__ = GetUserDefaultUILanguage();
