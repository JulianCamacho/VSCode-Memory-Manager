//
// Created by julian_camacho on 9/6/20.
//

#include "GarbageCollector.h"

GarbageCollector* GarbageCollector::instance = nullptr;

GarbageCollector* GarbageCollector::getInstance() {
    if (!instance)
        instance = new GarbageCollector;
    return instance;
}
