//
// Created by julian_camacho on 9/6/20.
//

#include "GarbageCollector.h"

GarbageCollector* GarbageCollector::instance = nullptr;

/**
 * getInstance Función para retornar la instancia del singleton
 * @return
 */
GarbageCollector* GarbageCollector::getInstance() {
    if (!instance)
        instance = new GarbageCollector;
    return instance;
}

/**
 * displayGC Procedimiento para desplegar visualmente el contenido del Garbage Collector
 */
void GarbageCollector::displayGC(){
//    printf("%s \n", "____________________________________________________________________________________________________________________");
//    printf("%s %62s %51s \n", "|", "VSCode Memory Manager", "|");
//    printf("%s \n", "____________________________________________________________________________________________________________________");
//    if (!dirList.empty()){
//        printf("%s %s %s %s %s %15s %2s %8s %4s %8s %3s %s %s %19s %18s \n", "|", "No.", "|", "Ref.", "|", "VSPtr Address", "|", "Value", "|", "Value Address", "|", "Data Type", "|", "ID ", "|");
//        printf("%s \n", "____________________________________________________________________________________________________________________");
//        for (int i = 0; i < dirList.size(); i++){
//            printf("%s %2i %2s %3i %2s %13p %3s %10s %2s %5p %2s %5s %5s %s %s\n", "|", objectNo[i], "|", refCountList[i], "|", generalList[i], "|", valueList[i].c_str(), "|", addressList[i], "|", typeList[i].c_str(), "|", idList[i].c_str(), "|");
//        }
//        printf("%s \n", "____________________________________________________________________________________________________________________");
//    }
}

/**
 * executeGC Procedimiento para liberar la memoria de los VSPtr con conteo en cero
 */
void GarbageCollector::executeGC(){
    cout << "Garbage Collector working" << endl;
    if (!dirList.empty()){
        for (int i = 0; i < dirList.size(); i++){
            if (refCountList[i] == 0){
                delete(generalList[i]);
                cout << "Destroying..: " << dirList[i] << endl;
                dirList.erase(dirList.begin()+i);
                addressList.erase(addressList.begin()+i);
                refCountList.erase(refCountList.begin()+i);
                valueList.erase(valueList.begin()+i);
                idList.erase(idList.begin()+i);
                typeList.erase(typeList.begin()+i);
            }
        }
    }
}


/**
 * run Procedimiento que ejecuta el thread del Garbage Collector
 */
void GarbageCollector::run() {
    cout << "Garbage Collector Thread Running" << endl;
    //Creamos el garbage collector
    this_thread::sleep_for (chrono::seconds(1/2));
    while (!stopRequested()) {
        GarbageCollector::displayGC();
        this_thread::sleep_for(chrono::seconds(1));
        GarbageCollector::displayGC();
        this_thread::sleep_for(chrono::seconds(1));
    }
    GarbageCollector::executeGC();
    GarbageCollector::displayGC();
}