cmake_minimum_required(VERSION 3.0)

# For clang
set (CMAKE_CXX_FLAGS "-std=c++1y -stdlib=libc++")

# For gcc
# set (CMAKE_CXX_FLAGS "-std=c++11")

# For gcc, static binary
# set (CMAKE_CXX_FLAGS "-std=c++11 -static")

project (lab3)
set (lab3-src lab3.cpp program_options.cpp node.cpp undirected_graph.cpp file_importer.cpp graph_query.cpp)
add_executable (lab3 ${lab3-src})

find_package (Boost COMPONENTS program_options filesystem system REQUIRED)
include_directories (${Boost_INCLUDE_DIR})
target_link_libraries (lab3 ${Boost_LIBRARIES})