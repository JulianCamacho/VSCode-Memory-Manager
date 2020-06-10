//
// Created by julian_camacho on 9/6/20.
//

#ifndef VSCODE_MEMORY_MANAGER_STOPPABLE_H
#define VSCODE_MEMORY_MANAGER_STOPPABLE_H


#include <iostream>
#include <thread>
#include <chrono>
#include <future>
using namespace std;

/**
 * Stoppable Clase para el thread del Garbage Collector
 */
class Stoppable {
    std::promise<void> exitSignal;
    std::future<void> futureObj;

public:
    Stoppable() : futureObj(exitSignal.get_future()){}

    Stoppable(Stoppable && obj) : exitSignal(std::move(obj.exitSignal)), futureObj(std::move(obj.futureObj)){}

    Stoppable & operator=(Stoppable && obj);

    // Task need to provide definition  for this function
    // It will be called by thread function
    virtual void run() = 0;

    // Thread function to be executed by thread
    void operator()();

    //Checks if thread is requested to stop
    bool stopRequested();
    // Request the thread to stop by setting value in promise object
    void stop();
};


#endif //VSCODE_MEMORY_MANAGER_STOPPABLE_H
