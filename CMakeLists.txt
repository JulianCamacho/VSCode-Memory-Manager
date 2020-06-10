cmake_minimum_required(VERSION 3.16)
project(VSCode_Memory_Manager)

set(CMAKE_CXX_STANDARD 14)

add_library(VSCode_Memory_Manager SHARED library.cpp library.h src/VSPtr.cpp src/VSPtr.h src/GarbageCollector.cpp src/GarbageCollector.h src/UUID.cpp src/UUID.h)