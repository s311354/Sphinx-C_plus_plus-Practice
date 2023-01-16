cmake_minimum_required(VERSION 3.25)
project(SOLUTIONS_EXAMPLE_UNIT VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE RelWithDebInfo)

find_path(SOLUTIONS_INCLUDE_DIRS solutions.h HINTS ${CMAKE_SOURCE_DIR}/include)

message(${SOLUTIONS_INCLUDE_DIRS})

add_executable(unit main.cc)
target_include_directories(unit PUBLIC ${SOLUTIONS_INCLUDE_DIRS})
target_link_libraries(unit solutions)
