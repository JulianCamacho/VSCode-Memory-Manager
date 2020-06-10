#include "library.h"

#include <iostream>

#include "library.h"
#include "GarbageCollector.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "../json.hpp"

using json = nlohmann::json;

void getGCPointers(){

    //Obtener lista de punteros con los datos respectivos

    GarbageCollector* gc = GarbageCollector::getInstance();

    cout << "gc memory: " << &gc << "--" << gc << endl;

    vector<SuperVSPtr*> _generalList = gc->generalList;
    vector<void**> _addressList = gc-> addressList;
    vector<string> _valueList = gc->valueList;
    vector<int> _refCountList =  gc->refCountList;
    vector<string> _idList = gc-> idList;
    vector<string> _typeList = gc->typeList;
    vector<int> _objectNo = gc->objectNo;

    //Crear objeto json
    json j;
    //Meter los vectores que se  puedan, con datos primitivos
    j["valueList"] = _valueList;
    j["refCountList"] = _refCountList;
    j["idList"] = _idList;
    j["typeList"] = _typeList;
    j["objNo"] = _objectNo;

    //Pasar dir vs pointer a string y guardarlo en json
    j["generalList"] = dirToString(_generalList);
    j["addressList"] = dirToString2(_addressList);

    cout << "_refCountListsize: " << _refCountList.size() << endl;

    printf("%s \n", "____________________________________________________________________________________________________________________");
    printf("%s %62s %51s \n", "|", "VSCode Memory Manager", "|");
    printf("%s \n", "____________________________________________________________________________________________________________________");

    if (!_addressList.empty()){

        printf("%s %s %s %s %s %15s %2s %8s %4s %8s %3s %s %s %19s %18s \n", "|", "No.", "|", "Ref.", "|", "VSPtr Address", "|", "Value", "|", "Value Address", "|", "Data Type", "|", "ID ", "|");
        printf("%s \n", "____________________________________________________________________________________________________________________");
        for (int i = 0; i < _addressList.size(); i++){
            printf("%s %2i %2s %3i %2s %13p %3s %10s %2s %5p %2s %5s %5s %s %s\n", "|", _objectNo[i], "|", _refCountList[i], "|", _generalList[i], "|", _valueList[i].c_str(), "|", _addressList[i], "|", _typeList[i].c_str(), "|", _idList[i].c_str(), "|");

        }
        printf("%s \n", "____________________________________________________________________________________________________________________");
    }

    //hacer algo con los datos

    string n = j.dump();

    cout << n << endl;

    createJsonFile(n);

};

//Pasa las direcciones de memoria a un vector con strings para poder pasarlo al json
vector<string> dirToString(vector<SuperVSPtr*> dirList){

    vector<string> newdirlist;


    for(int i = 0; i < dirList.size(); i++) {

        //convierte dirmem a string
        const void *address = static_cast<const void *>(dirList[i]);
        std::stringstream ss;
        ss << address;
        std::string name = ss.str();

        newdirlist.push_back(name);
    }

    return newdirlist;
}

vector<string> dirToString2(vector<void**> dirList){

    vector<string> newdirlist;


    for(int i = 0; i < dirList.size(); i++) {

        //convierte dirmem a string
        const void *address = static_cast<const void *>(dirList[i]);
        std::stringstream ss;
        ss << address;
        std::string name = ss.str();

        newdirlist.push_back(name);
    }

    return newdirlist;
}

void createJsonFile(string json){

    ofstream file;
    cout << "Crea json" << endl;
    file.open("./GCPointers.json", ios::out);
    file << json;
    file.close();

}
