/**
 * ===============================================
 * ===============================================
 * *\src\collectinfo.cpp
 * ===============================================
 * ===============================================
 * 
 * start time: 2022.10.11
 * 
 * 2022.10.11 connect \c void \c Print_SystemInfo to @a .\lib\collectinfo.h
 */

#include"collectinfo.h"

void clinfo::Print_SystemInfo(){
    system( "powershell .\\src\\OSRead.ps1" ); // run powershell script
    return;
}