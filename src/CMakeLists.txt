# ===============================================
# ===============================================
# *\src\CMakeLists.txt
# ===============================================
# ===============================================

include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/lib/jsoncpp)
# link .\lib and .\include

set(src ${PROJECT_SOURCE_DIR}/src/cmdlib.cpp ${PROJECT_SOURCE_DIR}/src/collectinfo.cpp)

set(SRC_LIST ${src} PARENT_SCOPE)
# set "SRC_LIST" as a global variable, in order to link these src files in .\CMakeLists.txt