cmake_minimum_required(VERSION 3.0)
set (CMAKE_CXX_FLAGS "-std=c++1y -stdlib=libc++")

set (lab1-src lab1.cpp program_options.cpp)
add_executable (lab1 ${lab1-src})

find_package (Boost COMPONENTS program_options filesystem system REQUIRED)
include_directories (${Boost_INCLUDE_DIR})
target_link_libraries (lab1 ${Boost_LIBRARIES})