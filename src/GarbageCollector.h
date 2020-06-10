//
// Created by julian_camacho on 9/6/20.
//

#ifndef VSCODE_MEMORY_MANAGER_GARBAGECOLLECTOR_H
#define VSCODE_MEMORY_MANAGER_GARBAGECOLLECTOR_H
#include <iostream>
#include <vector>
#include "Stoppable.h"
#include "VSPtr.h"

using namespace std;

class SuperVSPtr;

/**
 * Clase Garbage Collector
 */
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


#endif //VSCODE_MEMORY_MANAGER_GARBAGECOLLECTOR_H
