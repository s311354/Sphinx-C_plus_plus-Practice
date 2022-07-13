cmake_minimum_required(VERSION 3.5)
project(LEETCODE_PRACTICE_PROJECT VERSION 0.0.1)

add_definitions(-std=c++11)
add_definitions(-Werror) # stop compile on warning
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D_GLIBCXX_DEBUG")

add_subdirectory(src)
add_subdirectory(examples)
add_subdirectory(tests)
