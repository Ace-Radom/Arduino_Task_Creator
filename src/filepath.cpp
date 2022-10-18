#include<filepath.h>

/**
 * \brief judge if this path is a relative path
 * \param _path the path of a file or folder
 * \return bool, true for this path is a relative path, false for it's not
 */
bool path::is_relative_path( std::string _path ){
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
std::string path::_fullpath( std::string _path )
{
    std::string _ans( clinfo::__cwd__ );
    _ans.append( "\\" ).append( _path );
    return _ans;
}