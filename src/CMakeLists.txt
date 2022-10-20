# ===============================================
# ===============================================
# *\src\CMakeLists.txt
# ===============================================
# ===============================================

add_subdirectory(py)
# link .\src\py

set(src ${PROJECT_SOURCE_DIR}/src/cmdlib.cpp ${PROJECT_SOURCE_DIR}/src/collectinfo.cpp ${PROJECT_SOURCE_DIR}/src/artask.cpp ${PROJECT_SOURCE_DIR}/src/filepath.cpp)
# set src

message(STATUS "src list: " ${src})
# show src list

set(SRC_LIST ${src} PARENT_SCOPE)
# set SRC_LIST = src and as a global variable, in order to link these src files in .\CMakeLists.txt