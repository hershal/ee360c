cmake_minimum_required(VERSION 2.8.7)

# For clang
# set (CMAKE_CXX_FLAGS "-std=c++1y -stdlib=libc++")

# For gcc
set (CMAKE_CXX_FLAGS "-std=c++11 -O3")

# For gcc, static binary
# set (CMAKE_CXX_FLAGS "-std=c++11 -static")

project (lab3)
set (lab3-src file_importer.cpp fragment_assembler.cpp lab3.cpp program_options.cpp)
add_executable (lab3 ${lab3-src})

find_package (Boost COMPONENTS program_options filesystem system REQUIRED)
include_directories (${Boost_INCLUDE_DIR})
target_link_libraries (lab3 ${Boost_LIBRARIES})