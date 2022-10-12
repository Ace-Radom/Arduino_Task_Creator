/**
 * ===============================================
 * ===============================================
 * *\include\tolllib.h
 * ===============================================
 * ===============================================
 * 
 * \brief include all functions which do have their own features, but do not belong to any namespace or class
 * \def \c void \c change_TCHAR_to_string change \c TCHAR* to \c string
 * 
 * start time: 2022.10.12
 * 
 */

#ifndef _TOLLLIB_H_
#define _TOLLLIB_H_

#include<tchar.h>
#include<string>
#include<stringapiset.h>

std::string change_TCHAR_to_string( TCHAR* );

#endif