cmake_minimum_required(VERSION 3.0)
set (CMAKE_CXX_FLAGS "-std=c++1y -stdlib=libc++")

project (lab2)
set (lab2-src lab2.cpp program_options.cpp node.cpp undirected_graph.cpp file_importer.cpp graph_query.cpp)
add_executable (lab2 ${lab2-src})

find_package (Boost COMPONENTS program_options filesystem system REQUIRED)
include_directories (${Boost_INCLUDE_DIR})
target_link_libraries (lab2 ${Boost_LIBRARIES})