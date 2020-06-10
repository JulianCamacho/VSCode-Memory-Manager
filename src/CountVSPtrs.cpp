//
// Created by julian_camacho on 9/6/20.
//

#include "CountVSPtrs.h"

CountVSPtrs* CountVSPtrs::instance = CountVSPtrs::getInstance();

CountVSPtrs* CountVSPtrs::getInstance() {
    if (!instance)
        instance = new CountVSPtrs;
    return instance;
}

void CountVSPtrs::incrementTotalCount(){
    totalCount++;
}

int CountVSPtrs::getTotalCount(){
    return totalCount;
}
