include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/lib)

set(src ${PROJECT_SOURCE_DIR}/src/cmdlib.cpp ${PROJECT_SOURCE_DIR}/src/collectinfo.cpp)

set(SRC_LIST ${src} PARENT_SCOPE)