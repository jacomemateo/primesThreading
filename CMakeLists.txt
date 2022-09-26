cmake_minimum_required(VERSION 3.00)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "-std=c++11")

project(primes)

add_executable( prime_normal
    src/prime_normal.cc
)

add_executable( prime_miller
   src/prime_miller.cc
)