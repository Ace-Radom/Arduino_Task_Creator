/**
 * ===============================================
 * ===============================================
 * *\include\artask.h
 * ===============================================
 * ===============================================
 * 
 * \brief main library for Arduino_Task_Creator_Project
 * \def \c STATUS_t   = \c bool
 * \def \c _verify_   = \c 0x00
 * \def \c _upload_   = \c 0x01
 * \def \c _SET_      = \c true
 * \def \c _NOT_SET_  = \c false
 * \def \c _USING_    = \c true
 * \def \c _NOT_USING = \c false
 * \def \c class \c ARTask the main class for Arduino_Task
 *      \c pubilc:
 *          \def \c ARTask create one ARTask class and pre-set
 *          \def \c void \c change_board change board type of arduino
 *          \def \c void \c change_serial_port change serial port to connect to arduino board
 *          \def \c void \c read_taskfile read datas in taskfile
 *          \def \c void \c start send command to @a arduino_debug
 *      \c private:
 *          \def \c void \c pre_set pre-set all vars in class
 *          \def \c arduino_board board type of arduino
 *          \def \c serial_port serial port to connect to arduino board
 *          \def \c void \c make_command write command from taskfile to \c command
 *          \def \c command the command needs to be sended to @a arduino_debug
 *          \def \c is_help_triggered judge if needs to show help. if typing in @a -h @a -? or not typing in any option, show help page and this will be \c _USING_
 *          \def \c is_using_taskfile judge if is using task file or not
 *          \def \c is_board_set judge if arduino board is set
 *          \def \c is_serial_port_set judge if serial port is set
 *          \def \c is_arduino_file_set judge if arduino program file is set
 *          \def \c is_verify_or_upload judge to use which command (status as \c _verify_ or \c _upload_ which defed here)
 *          \def \c arduino_file_path arduino program file path
 *          \def \c taskfile_path task file path
 * 
 * start time: 2022.10.11
 * 
 * 2022.10.18 change var \c is_file_set name to \c is_arduino_file_set due to missunderstanding
 *            move \c PATH_t to @a collectinfo.h
 */

#ifndef _ARTASK_H_
#define _ARTASK_H_

#include<string>
#include<collectinfo.h>
#include<filepath.h>

#define _verify_ 0x00
#define _upload_ 0x01

#define _NOT_SET_ false
#define _SET_ true

#define _NOT_USING_ false
#define _USING_ true

typedef bool STATUS_t;

class ARTask{
    public:
        ARTask();
        
        void change_board( std::string );
        void change_serial_port( std::string );
        void set_taskfile( PATH_t );
        void set_arduino_file( PATH_t );
        void set_verify_or_upload( STATUS_t );

        void read_taskfile( PATH_t );

        void start();

    private:
        void pre_set();

        std::string arduino_board;
        std::string serial_port;

        void make_command();

        std::string command;

#pragma region status

        STATUS_t is_help_triggered;
        STATUS_t is_using_taskfile;
        STATUS_t is_board_set;
        STATUS_t is_serial_port_set;
        STATUS_t is_arduino_file_set;
        STATUS_t is_verify_or_upload;

#pragma endregion status

        PATH_t arduino_file_path;
        PATH_t taskfile_path;

}; // class ARTast

#endif