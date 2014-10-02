cmake_minimum_required(VERSION 3.0)
set (CMAKE_CXX_FLAGS "-std=c++1y -stdlib=libc++")

add_subdirectory (src src-bin)
add_subdirectory (doc doc-bin)