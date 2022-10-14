/**
 * ===============================================
 * ===============================================
 * *\include\artask.h
 * ===============================================
 * ===============================================
 * 
 * \brief main library for Arduino_Task_Creator_Project
 * \def \c class \c ARTast the main class for Arduino_Task
 * 
 * start time: 2022.10.11
 */

#ifndef _ARTASK_H_
#define _ARTASK_H_

#include<string>

class ARTast{
    public:
        
        void change_board();
        void change_serial_port();

    private:

        std::string arduino_board;
        std::string serial_port;

}; // class ARTast

#endif