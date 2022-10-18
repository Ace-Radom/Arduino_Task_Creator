/**
 * ===============================================
 * ===============================================
 * *\include\filepath.h
 * ===============================================
 * ===============================================
 * 
 * \brief functions for file-path process, such as judge if file / folder exists
 *                                                 see if there are writable or read-only
 * \def \c namespace \c path
 *      \def \c bool \c is_relative_path judge if this path is a relative path
 *      \def \c void \c _fullpath change relative path to a full path
 *      \def \c struct \c fp file permission, save the permission this user has on this file
 *           \def \c existence
 *           \def \c execute_permission
 *           \def \c write_permission
 *           \def \c read_permission
 *      \def \c void \c get_file_permission get the permission this user has on this file
 * 
 * start time 2022.10.18
 */

#ifndef _FILEPATH_H_
#define _FINEPATH_H_

#include<collectinfo.h>
#include<string>
#include<io.h>

#define F_EXISTENCE 0
#define F_EXECUTE_PERMISSION 1
#define F_WRITE_PERMISSION 2
#define F_READ_PERMISSION 4
// 'F' means file here
// access-mode for access function

namespace path{
    bool is_relative_path( PATH_t );
    PATH_t _fullpath( PATH_t );

    struct fp{ // file permission
        bool existence;
        bool execute_permission;
        bool write_permission;
        bool read_permission;
    };

    void get_file_permission( PATH_t , fp & );
}; // namespace path

#endif