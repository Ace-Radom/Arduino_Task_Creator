/**
 * ===============================================
 * ===============================================
 * *\include\artask.h
 * ===============================================
 * ===============================================
 * 
 * \brief main library for Arduino_Task_Creator_Project
 * \def \c STATUS = \c bool
 * \def \c PATH   = \c std::string
 * \def \c class \c ARTast the main class for Arduino_Task
 * 
 * start time: 2022.10.11
 */

#ifndef _ARTASK_H_
#define _ARTASK_H_

#include<string>

typedef bool STATUS;
typedef std::string PATH;

#define _verify_ 0x00
#define _upload_ 0x01

class ARTast{
    public:
        ARTast();
        
        void change_board();
        void change_serial_port();

    private:
        void pre_set();

        std::string arduino_board;
        std::string serial_port;

#pragma region status

        STATUS is_help_triggered;
        STATUS is_using_taskfile;
        STATUS is_board_set;
        STATUS is_serial_port_set;
        STATUS is_file_set;
        STATUS is_verify_or_upload;

#pragma endregion status

}; // class ARTast

#endif