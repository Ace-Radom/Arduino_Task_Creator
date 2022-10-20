# ===============================================
# ===============================================
# *\src\py\CMakeLists.txt
# ===============================================
# ===============================================

execute_process(COMMAND pyinstaller -F com_serial.py
                WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/src/py)