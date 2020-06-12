//
// Created by julian_camacho on 6/5/20.
//

#ifndef PRUEBA3_GARBAGECOLLECTOR_H
#define PRUEBA3_GARBAGECOLLECTOR_H
#include <iostream>
#include <vector>
#include "Stoppable.h"
#include "VSPtr.h"

using namespace std;

class SuperVSPtr;

class GarbageCollector : public Stoppable{
    static GarbageCollector *instance;
    // Private constructor so that no objects can be created.
    GarbageCollector() = default;

public:
    vector<SuperVSPtr*> generalList;
    vector<void**> dirList;
    vector<void**> addressList;
    vector<string> valueList;
    vector<int> refCountList;
    vector<string> idList;
    vector<string> typeList;
    vector<int> objectNo;

    void displayGC();
    void executeGC();
    static GarbageCollector *getInstance();

    void run() override;
};


#endif //PRUEBA3_GARBAGECOLLECTOR_H
