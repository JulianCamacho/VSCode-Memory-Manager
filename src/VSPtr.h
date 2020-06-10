//
// Created by julian_camacho on 9/6/20.
//

#ifndef VSCODE_MEMORY_MANAGER_VSPTR_H
#define VSCODE_MEMORY_MANAGER_VSPTR_H
#include <iostream>
#include "CountVSPtrs.h"
#include "GarbageCollector.h"
using namespace std;

class GarbageCollector;

class SuperVSPtr{
public:
    int objNumber = 0;
    int refCount = 0;
    string id;
    string type;
};

// A generic smart pointer class
template <class T>
class VSPtr : SuperVSPtr{
public:
    static GarbageCollector* sharedGC;
    static CountVSPtrs* sharedCount;
    int objNumber = 0;
    T* ptr = nullptr;
    int refCount = 0;
    string id;
    string type;

    static VSPtr<T> New();

    // Constructor
    explicit VSPtr(T* p = NULL);
    // Destructor
    ~VSPtr();

    // Overloading dereferncing operator
    T& operator * ();

    // Overloding arrow operator so that members of T can be accessed
    // like a pointer (useful if T represents a class or struct or
    // union type)
    T * operator -> ();

    T operator &();

    VSPtr<T>& operator =(T newValue);

    VSPtr<T>& operator =(VSPtr& other);

    void updateList();
    void updateRefCount(VSPtr<T>& other, int index);
    int getRefCount() const;
};


#endif //VSCODE_MEMORY_MANAGER_VSPTR_H
