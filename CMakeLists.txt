cmake_minimum_required(VERSION 3.20)
project(Assembler)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release")
endif()

if(CMAKE_BUILD_TYPE STREQUAL "Release")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")
endif()

include(FetchContent)

FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE) 
FetchContent_MakeAvailable(googletest)
enable_testing()

add_executable(
    Assembler
    ${CMAKE_SOURCE_DIR}/src/main.cpp
)

target_link_libraries(
    Assembler
    GTest::gtest_main
)

add_executable(
    AssemblerTests
    ${CMAKE_SOURCE_DIR}/tst/basictest.cpp
)

target_include_directories(
    AssemblerTests PRIVATE
    ${CMAKE_SOURCE_DIR}/src
)

target_link_libraries(
    AssemblerTests
    GTest::gtest_main
)

