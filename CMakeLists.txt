cmake_minimum_required(VERSION 3.00)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "-std=c++11")

project(primesThreading)

add_executable(
    primeN.o
    src/primeN.cpp
)

add_executable(
   primeT.o
   src/primeT.cpp
)

target_link_libraries(primeT.o pthread)