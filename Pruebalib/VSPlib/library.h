//
// Created by jose on 8/5/20.
//

#ifndef DYNAMICLIB_MASTER_LIBRARY_H
#define DYNAMICLIB_MASTER_LIBRARY_H

#include <string>
#include <vector>
#include "VSPtr.h"

using namespace std;

extern "C" {
string getGCPointers();
vector<string> dirToString(vector<SuperVSPtr *>);
vector<string> dirToString2(vector<void **>);
}

#endif //DYNAMICLIB_MASTER_LIBRARY_H
