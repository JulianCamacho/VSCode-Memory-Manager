//
// Created by julian_camacho on 9/6/20.
//

#ifndef VSCODE_MEMORY_MANAGER_VSPTR_H
#define VSCODE_MEMORY_MANAGER_VSPTR_H
#include <iostream>
using namespace std;

template <class T>
class VSPtr {
    int objNumber = 0;
    T* ptr = nullptr;
    int refCount = 0;
    string id;
    string type;
};


#endif //VSCODE_MEMORY_MANAGER_VSPTR_H
