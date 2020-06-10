//
// Created by julian_camacho on 9/6/20.
//

#include "VSPtr.h"
#include "GarbageCollector.h"
#include "CountVSPtrs.h"
#include "UUID.h"
#include "library.h"

template<class T> GarbageCollector* VSPtr<T>::sharedGC = sharedGC->getInstance();
template<class T> CountVSPtrs* VSPtr<T>::sharedCount = sharedCount->getInstance();

/**
 * getRefCount devuelve el conteo de referencias de un VSPtr
 * @tparam T
 * @return número de referencias
 */
template <class T>
int VSPtr<T>::getRefCount() const {
    return refCount;
}

/**
 * New función para instanciar un VSPtr e incluirlo en el Garbage Collector
 * @tparam T
 * @return nuevo VSPtr
 */
template <class T>
VSPtr<T> VSPtr<T>::New(){
    auto* newPtr = new VSPtr<T>(new T());
    sharedGC->generalList.push_back(newPtr);
    cout << "Created VSPtr: " << newPtr  << endl;
    newPtr->type = typeid(*newPtr->ptr).name();
    sharedCount->incrementTotalCount();
    newPtr->objNumber = sharedCount->getTotalCount();
    newPtr->id = UUID::generateUUID();
    newPtr->refCount++;
    VSPtr<T> storePtr = *newPtr;
    return storePtr;
}

/**
 * updateList Actualiza los datos del VSPtr contenidos en el Garbage Collector
 * @tparam T
 */
template <class T>
void VSPtr<T>::updateList(){
    for(int i = 0; i < sharedGC->dirList.size(); i++){
        if(sharedGC->dirList[i] == reinterpret_cast<void**>(&ptr)){
            sharedGC->addressList[i] = reinterpret_cast<void**>(ptr);
            sharedGC->valueList[i] = to_string(*ptr);
            sharedGC->idList[i] = id;
            return;
        }
    }
    sharedGC->dirList.push_back(reinterpret_cast<void**>(&ptr));
    sharedGC->addressList.push_back(reinterpret_cast<void**>(ptr));
    sharedGC->valueList.push_back(to_string(*ptr));
    sharedGC->refCountList.push_back(refCount);
    sharedGC->idList.push_back(id);
    sharedGC->typeList.push_back(type);
    sharedGC->objectNo.push_back(objNumber);
    getGCPointers();
}

/**
 * updateRefCount Actualiza el conteo de referencias del VSPtr a quien están apuntando ahora
 * @tparam T
 * @param other El VSPtr a la derecha del igual
 * @param index Posición en el Garbage Collector
 */
template <class T>
void VSPtr<T>::updateRefCount(VSPtr<T>& other, int index){
    sharedGC->refCountList[index] = other.getRefCount();
}

/**
 * Sobrecarga del operador *
 * @tparam T
 * @return donde apunta el pointer interno
 */
template<class T>
T &VSPtr<T>::operator*() {
    return *ptr;
}

/**
 * Sobrecarga del operador ->
 * @tparam T
 * @return la dirección de memoria que almacena el pointer
 */
template<class T>
T *VSPtr<T>::operator->() {
    return ptr;
}

/**
 * Sobrecarga del operador &
 * @tparam T
 * @return el valor de a lo que apunta el pointer
 */
template<class T>
T VSPtr<T>::operator&() {
    return *ptr;
}

/**
 * Sobrecarga del operador = para un tipo primitivo
 * @tparam T
 * @param newValue
 * @return
 */
template<class T>
VSPtr<T>& VSPtr<T>::operator=(T newValue) {
    *ptr = newValue;
    type = typeid(*ptr).name();
    updateList();
}

/**
 * Sobrecarga del operador = para otro VSPtr
 * @tparam T
 * @param other
 * @return
 */
template<class T>
VSPtr<T>& VSPtr<T>::operator =(VSPtr& other){
    if (refCount == 1){
        delete ptr;
    }
    ptr = other.ptr;
    id = other.id;
    other.refCount++;
    updateList();
    updateRefCount(other, other.objNumber);
    return *this;
}

/**
 * Destructor de VSPtr
 * @tparam T
 */
template<class T>
VSPtr<T>::~VSPtr() {
    if (refCount <= 0){
        cout << &ptr <<" Ref count is " << refCount << " ... Destroyed VSPtr! "<< endl;
        sharedGC->executeGC();
        sharedGC->displayGC();
    }
}

/**
 * Constructor de VSPtr
 * @tparam T
 * @param p
 */
template<class T>
VSPtr<T>::VSPtr(T *p) {
    ptr = p;
}


template class VSPtr<bool>;
template class VSPtr<int>;
template class VSPtr<short int>;
template class VSPtr<unsigned short>;
template class VSPtr<unsigned int>;
template class VSPtr<long>;
template class VSPtr<long long int>;
template class VSPtr<unsigned long long int>;
template class VSPtr<float>;
template class VSPtr<double>;
template class VSPtr<long double>;
template class VSPtr<char>;