cmake_minimum_required(VERSION 3.16)
project(c_leetcode_solutions)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_C_STANDARD 11)

#Cmake最低版本要求
CMAKE_MINIMUM_REQUIRED(VERSION 3.16) 

set(TOP_SOURCE_DIR ${CMAKE_SOURCE_DIR})

#允许gdb调试
set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -O0 -Wall -g -ggdb")
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")
#添加C++11支持及其他选项
set(CMAKE_CXX_FLAGS "-std=c++0x ${CMAKE_CXX_FLAGS} -g -ftest-coverage -fprofile-arcs -Wno-deprecated")
 
add_subdirectory(array)
add_subdirectory(binary-search)
add_subdirectory(design)
add_subdirectory(greedy)
add_subdirectory(linked-list)
add_subdirectory(stack)
add_subdirectory(tree)
add_subdirectory(backtracking)
add_subdirectory(divide-and-conquer)
add_subdirectory(dynamic-programming)
add_subdirectory(hash-table)
add_subdirectory(math)         
add_subdirectory(strings)
add_subdirectory(two-pointers)

SET(CMAKE_INSTALL_PREFIX ${TOP_SOURCE_DIR}/output)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)
