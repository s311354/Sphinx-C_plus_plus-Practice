cmake_minimum_required(VERSION 3.25)
project(SOLUTIONS_LIB VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE RelWithDebInfo -pthread)

# boost
set(Boost_USE_STATIC_LIBS ON)
FIND_PACKAGE(Boost)
IF (Boost_FOUND)
    INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIRS})
    ADD_DEFINITIONS( "-DHAS_BOOST" )
ENDIF()

set(SOURCE_FILES solutions.cc arrays.cc twopointers.cc slidingwindows.cc matrix.cc hashmap.cc intervals.cc stack.cc linkedlist.cc graph_general.cc trie.cc backtracking.cc)
find_path(SOLUTIONS_INCLUDE_DIRS solutions.h HINTS ${CMAKE_SOURCE_DIR}/include)

message(${SOLUTIONS_INCLUDE_DIRS})

add_library(solutions SHARED ${SOURCE_FILES})
target_include_directories(solutions PUBLIC ${SOLUTIONS_INCLUDE_DIRS})
