cmake_minimum_required(VERSION 3.16)
project(c_leetcode_solutions)

set(CMAKE_CXX_STANDARD 14)

#Cmake最低版本要求
CMAKE_MINIMUM_REQUIRED(VERSION 2.6) 
 
#项目名称
PROJECT(mmseg CXX)
 
#允许gdb调试
set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")
#添加C++11支持及其他选项
set(CMAKE_CXX_FLAGS "-std=c++0x ${CMAKE_CXX_FLAGS} -g -ftest-coverage -fprofile-arcs -Wno-deprecated")
 
# 头文件目录
#include_directories("路径")
# 例如
#include_directories(
# ${PROJECT_SOURCE_DIR}
# ${PROJECT_SOURCE_DIR}/include
# ${EIGEN3_INCLUDE_DIR})
 
#添加C++11编译选项,但是只有CMAKE 3.1支持
#target_compile_features(mmseg PRIVATE cxx_range_for)
 
#添加链接库
#target_link_libraries(mmseg Dict)
 
# 需要链接额外的动态库时：
# target_link_libraries(${PROJECT_NAME}
# /usr/lib/i386-linux-gnu/libboost_system.so)


add_subdirectory(array)
add_subdirectory(binary-search)
add_subdirectory(design)
add_subdirectory(greedy)
add_subdirectory(linked-list)
add_subdirectory(stack)
add_subdirectory(tree)
add_subdirectory(backtracking)
add_subdirectory(divide-and-conquer)
add_subdirectory(ynamic-programming)
add_subdirectory(hash-table)
add_subdirectory(math)         
add_subdirectory(strings)
add_subdirectory(two-pointers)

SET(CMAKE_INSTALL_PREFIX ../output)
