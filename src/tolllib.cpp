/**
 * ===============================================
 * ===============================================
 * *\src\tolllib.cpp
 * ===============================================
 * ===============================================
 * 
 * start time 2022.10.12
 * 
 * 2022.10.12 finish function \c change_TCHAR_to_string but hasn't been tested yet
 * 
 */

#include<tolllib.h>

/**
 * \brief change \c TCHAR* to \c string
 * 
 * \param __tchar the \c TCHAR array needs to be changed
 * 
 * \return a string, changed from the \c TCHAR array
 */
std::string change_TCHAR_to_string( TCHAR *__tchar ){ // from https://blog.csdn.net/dongzhe8/article/details/53286444
    int iLen = WideCharToMultiByte( CP_ACP , 0 , __tchar , -1 , NULL , 0 , NULL , NULL );
    char *chRtn = new char[iLen*sizeof( char )];
    WideCharToMultiByte( CP_ACP , 0 , __tchar , -1 , chRtn , iLen , NULL , NULL );
    std::string __ans( chRtn );
    return __ans;
}