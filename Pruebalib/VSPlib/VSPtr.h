//
// Created by julian_camacho on 6/5/20.
//

#ifndef PRUEBA3_VSPTR_H
#define PRUEBA3_VSPTR_H

#include "CountVSPtrs.h"
#include "GarbageCollector.h"

class GarbageCollector;

class SuperVSPtr{
public:
    int objNumber = 0;
    int refCount = 0;
    string id;
    string type;
};

// A generic smart pointer class
template <class T>
class VSPtr : SuperVSPtr{
public:
    static GarbageCollector* sharedGC;
    static CountVSPtrs* sharedCount;
    int objNumber = 0;
    T* ptr = nullptr;
    int refCount = 0;
    string id;
    string type;

    static VSPtr<T> New();

    // Constructor
    explicit VSPtr(T* p = NULL);
    // Destructor
    ~VSPtr();

    // Overloading dereferncing operator
    T& operator * ();

    // Overloding arrow operator so that members of T can be accessed
    // like a pointer (useful if T represents a class or struct or
    // union type)
    T * operator -> ();

    T operator &();

    VSPtr<T>& operator =(T newValue);

    VSPtr<T>& operator =(VSPtr& other);

    void updateList();
    void updateRefCount(VSPtr<T>& other, int index);
    int getRefCount() const;
};

/*
 * cmake_minimum_required(VERSION 3.15)
project(Prueba3)

set(CMAKE_CXX_STANDARD 14)

find_package (Threads)
add_executable(Prueba3 main.cpp src/UUID.cpp src/UUID.h src/VSPtr.cpp src/VSPtr.h src/CountVSPtrs.cpp src/CountVSPtrs.h src/GarbageCollector.cpp src/GarbageCollector.h src/Stoppable.cpp src/Stoppable.h)
target_link_libraries (Prueba3 ${CMAKE_THREAD_LIBS_INIT})


 ---------------------------------------------------------

SHARED LIBRARY

 vector<string> dirToString(vector<SuperVSPtr*>);cmake_minimum_required(VERSION 3.15)
project(Prueba3)

set(CMAKE_CXX_STANDARD 14)

find_package (Threads)
add_library(Prueba3 SHARED src/UUID.cpp src/UUID.h src/VSPtr.cpp src/VSPtr.h src/CountVSPtrs.cpp src/CountVSPtrs.h src/GarbageCollector.cpp src/GarbageCollector.h src/Stoppable.cpp src/Stoppable.h)
target_link_libraries (Prueba3 ${CMAKE_THREAD_LIBS_INIT})

  --------------------------------------------


 #include <iostream>
#include <thread>
#include "src/VSPtr.h"
using namespace std;



int main() {
    thread th([&](){ VSPtr<int>::sharedGC->run();});

    VSPtr<bool> myPtr0 = VSPtr<bool>::New();
    VSPtr<int> myPtr1 = VSPtr<int>::New();
    VSPtr<int> myPtr2 = VSPtr<int>::New();
    VSPtr<float> myPtr3 = VSPtr<float>::New();
    VSPtr<long> myPtr4 = VSPtr<long>::New();
    VSPtr<int> myPtr5 = VSPtr<int>::New();
    VSPtr<char> myPtr6 = VSPtr<char>::New();
    VSPtr<double> myPtr7 = VSPtr<double>::New();
    VSPtr<short int> myPtr8 = VSPtr<short int>::New();
    VSPtr<bool> myPtr9;
    VSPtr<short> myPtr10 = VSPtr<short>::New();
    VSPtr<short> myPtr11 = VSPtr<short>::New();

    myPtr0 = true;
    myPtr1 = 99;
    myPtr2 = 80;
    myPtr3 = 6.4;
    myPtr4 = 21474836511;
    myPtr5 = 85;
    myPtr6 = 'j';
    myPtr7 = 35.214;
    myPtr8 = 8;
    //myPtr9 = false;
    myPtr10 = 33;
    myPtr11 = 55;
    myPtr2 = myPtr5;
    myPtr2 = 10;

    int valor = &myPtr1;
    cout << valor << endl;

    //VSPtr<int>::sharedGC->executeGC();
    //VSPtr<int>::sharedGC->displayGC();

    VSPtr<int>::sharedGC->stop();
    th.join();

    return 0;
}
 * */

#endif //PRUEBA3_VSPTR_H
