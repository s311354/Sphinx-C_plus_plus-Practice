cmake_minimum_required(VERSION 3.25)
project(SOLUTIONS_INTEGRATION_TEST_PROJECT VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE RelWithDebInfo)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
  DOWNLOAD_EXTRACT_TIMESTAMP true
)
FetchContent_MakeAvailable(googletest)

find_path(SOLUTIONS_INCLUDE_DIRS config.h solutions.h HINTS ${CMAKE_SOURCE_DIR}/include)

message(${SOLUTIONS_INCLUDE_DIRS})

# Specify the configuration file from which the header file will be generated
set(INPUT_FILES_DIR ${CMAKE_SOURCE_DIR}/file)
configure_file("${SOLUTIONS_INCLUDE_DIRS}/config.h.in" "${SOLUTIONS_INCLUDE_DIRS}/config.h")

add_executable(leetcode_integration_test leetcode_integration_test.cc)
target_include_directories(leetcode_integration_test PUBLIC ${SOLUTIONS_INCLUDE_DIRS} ${GTEST_INCLUDE_DIRS})
target_link_libraries(leetcode_integration_test solutions gtest_main pthread)

include(GoogleTest)
gtest_discover_tests(leetcode_integration_test)
