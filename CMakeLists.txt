cmake_minimum_required(VERSION 3.16)
project(VSCode_Memory_Manager)

set(CMAKE_CXX_STANDARD 14)

find_package (Threads)
add_library(VSCode_Memory_Manager SHARED json.hpp src/library.cpp src/library.h src/VSPtr.cpp src/VSPtr.h src/GarbageCollector.cpp src/GarbageCollector.h src/UUID.cpp src/UUID.h src/CountVSPtrs.cpp src/CountVSPtrs.h src/Stoppable.cpp src/Stoppable.h)
target_link_libraries (VSCode_Memory_Manager ${CMAKE_THREAD_LIBS_INIT})
