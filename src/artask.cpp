#include<artask.h>

#pragma region public_function

/**
 * \brief create one ARTask class
 */
ARTask::ARTask(){
    pre_set();
    return;
}

#pragma endregion public_function

#pragma region private_function

/**
 * \brief pre-set all vars in class
 */
void ARTask::pre_set(){
    arduino_board.clear();
    serial_port.clear();
    file_path.clear();
    taskfile_path.clear();

    is_help_triggered   = _NOT_USING_;
    is_using_taskfile   = _USING_; // in 1.0 there must set one task file
    is_board_set        = _NOT_SET_;
    is_serial_port_set  = _NOT_SET_;
    is_file_set         = _NOT_SET_;
    is_verify_or_upload = _NOT_SET_;
}

#pragma endregion private_function