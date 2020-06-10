//
// Created by julian_camacho on 9/6/20.
//

#include "Stoppable.h"

// Request the thread to stop by setting value in promise object
void Stoppable::stop(){
    exitSignal.set_value();
}

//Checks if thread is requested to stop
bool Stoppable::stopRequested(){
    // checks if value in future object is available
    return !(futureObj.wait_for(std::chrono::milliseconds(0)) == std::future_status::timeout);
}

// Thread function to be executed by thread
void Stoppable::operator()(){
    run();
}

Stoppable & Stoppable::operator=(Stoppable && obj){
    std::cout << "Move Assignment is called" << std::endl;
    exitSignal = std::move(obj.exitSignal);
    futureObj = std::move(obj.futureObj);
    return *this;
}