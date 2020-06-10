//
// Created by julian_camacho on 9/6/20.
//

#ifndef VSCODE_MEMORY_MANAGER_COUNTVSPTRS_H
#define VSCODE_MEMORY_MANAGER_COUNTVSPTRS_H

/**
 * CountVSPtrs Clase que lleva el conteo del total de VSPtrs creados
 */
class CountVSPtrs {
    static CountVSPtrs *instance;
    CountVSPtrs()= default;

public:
    int totalCount = -1;

    static CountVSPtrs *getInstance();
    void incrementTotalCount();
    int getTotalCount();
};


#endif //VSCODE_MEMORY_MANAGER_COUNTVSPTRS_H
