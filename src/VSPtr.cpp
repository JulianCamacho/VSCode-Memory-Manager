//
// Created by julian_camacho on 9/6/20.
//

#include "VSPtr.h"

template <class T>
VSPtr<T> VSPtr<T>::New(){
    auto* newPtr = new VSPtr<T>(new T());
    cout << "Created VSPtr: " << newPtr  << endl;
    newPtr->type = typeid(*newPtr->ptr).name();
    newPtr->refCount++;
    VSPtr<T> storePtr = *newPtr;
    return storePtr;
}

template<class T>
T &VSPtr<T>::operator*() {
    return *ptr;
}

template<class T>
T *VSPtr<T>::operator->() {
    return ptr;
}

template<class T>
T VSPtr<T>::operator&() {
    return *ptr;
}