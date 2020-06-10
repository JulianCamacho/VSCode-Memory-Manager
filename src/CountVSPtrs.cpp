//
// Created by julian_camacho on 9/6/20.
//

#include "CountVSPtrs.h"

CountVSPtrs* CountVSPtrs::instance = CountVSPtrs::getInstance();

/**
 * getInstance
 * @return la instancia del singleton
 */
CountVSPtrs* CountVSPtrs::getInstance() {
    if (!instance)
        instance = new CountVSPtrs;
    return instance;
}

/**
 * incrementTotalCount Procedimiento para aumentar la cuenta total en uno
 */
void CountVSPtrs::incrementTotalCount(){
    totalCount++;
}

/**
 * getTotalCount
 * @return el total de VSPtrs creados
 */
int CountVSPtrs::getTotalCount(){
    return totalCount;
}
