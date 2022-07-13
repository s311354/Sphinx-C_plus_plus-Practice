cmake_minimum_required(VERSION 3.5)
project(SOLUTIONS_LIB VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_BUILD_TYPE RelWithDebInfo)

FIND_PACKAGE(Boost)
IF (Boost_FOUND)
    INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})
    ADD_DEFINITIONS( "-DHAS_BOOST" )
ENDIF()

set(SOURCE_FILES solutions.cc)
find_path(SOLUTIONS_INCLUDE_DIRS solutions.h HINTS ${CMAKE_SOURCE_DIR}/include)

add_library(solutions SHARED ${SOURCE_FILES})
target_include_directories(solutions PUBLIC ${SOLUTIONS_INCLUDE_DIRS})
