//
// Created by julian_camacho on 6/5/20.
//

#ifndef PRUEBA3_COUNTVSPTRS_H
#define PRUEBA3_COUNTVSPTRS_H


class CountVSPtrs {
    static CountVSPtrs *instance;
    CountVSPtrs()= default;

public:
    int totalCount = -1;

    static CountVSPtrs *getInstance();
    void incrementTotalCount();
    int getTotalCount();
};

#endif //PRUEBA3_COUNTVSPTRS_H
