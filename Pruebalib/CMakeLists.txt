cmake_minimum_required(VERSION 3.15)
project(Pruebalib)

set(CMAKE_CXX_STANDARD 14)

add_executable(Pruebalib main.cpp)
target_link_libraries(Pruebalib ${CMAKE_SOURCE_DIR}/VSPlib/libPrueba3.so)