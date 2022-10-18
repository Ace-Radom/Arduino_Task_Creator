/**
 * ===============================================
 * ===============================================
 * *\src\filepath.cpp
 * ===============================================
 * ===============================================
 * 
 * start time 2022.10.18
 */

#include<filepath.h>

/**
 * \brief judge if this path is a relative path
 * \param _path the path of a file or folder
 * \return bool, true for this path is a relative path, false for it's not
 */
bool path::is_relative_path( PATH_t _path ){
    if ( ( ( _path[0] >= 'a' && _path[0] <= 'z' ) || ( _path[0] >= 'A' && _path[0] <= 'Z' ) ) && _path[1] == ':' )
    {
        return false;
        // this path is begin with a Latin script and the second letter is ':'
        // that means that this path is a full path
    }
    return true;
}

/**
 * \brief change relative path to a full path
 * \param _path a relative path
 * \return full path (add \c __cwd__ path at the front)
 */
PATH_t path::_fullpath( PATH_t _path )
{
    PATH_t _ans( clinfo::__cwd__ );
    _ans.append( "\\" ).append( _path );
    return _ans;
}

/**
 * \brief get the permission this user has on this file
 * \param _path file path
 * \param _fp write permission to this fp struct
 */
void path::get_file_permission( PATH_t _path , fp &_fp ){
    ( access( _path.c_str() , F_EXISTENCE )          == 0 ) ? _fp.existence = true
                                                            : _fp.existence = false;
    ( access( _path.c_str() , F_EXECUTE_PERMISSION ) == 0 ) ? _fp.execute_permission = true
                                                            : _fp.execute_permission = false;
    ( access( _path.c_str() , F_WRITE_PERMISSION )   == 0 ) ? _fp.write_permission = true
                                                            : _fp.write_permission = false;
    ( access( _path.c_str() , F_READ_PERMISSION )    == 0 ) ? _fp.read_permission = true
                                                            : _fp.read_permission = false;

    /**
     * access function in @a io.h
     * \code int access(const char *_Filename, int _AccessMode)
     * when the user has this permission, returns 0
     */
    return;
}