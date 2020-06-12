//
// Created by julian_camacho on 6/5/20.
//

#ifndef PRUEBA3_STOPPABLE_H
#define PRUEBA3_STOPPABLE_H
#include <iostream>
#include <thread>
#include <chrono>
#include <future>
using namespace std;


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


#endif //PRUEBA3_STOPPABLE_H
