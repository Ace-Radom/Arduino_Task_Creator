# ===============================================
# ===============================================
# *\src\py\CMakeLists.txt
# ===============================================
# ===============================================

set(py_src ${PROJECT_SOURCE_DIR}/src/py/com_serial.py ${PROJECT_SOURCE_DIR}/src/py/com_reg.py)
# set py_src

set(PY_SRC_LIST ${py_src} PARENT_SCOPE)
# set PY_SRC_LIST = py_src and as a global variable, in order to message these srcs in .\src\CMakeLists.txt

execute_process(COMMAND pyinstaller -F com_serial.py
                WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/src/py)
# install com_serial.py

execute_process(COMMAND pyinstaller -F com_reg.py
                WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/src/py)
# install com_reg.py