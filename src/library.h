#ifndef VSCODE_MEMORY_MANAGER_LIBRARY_H
#define VSCODE_MEMORY_MANAGER_LIBRARY_H

#include <string>
#include <vector>
#include "VSPtr.h"

using namespace std;

vector<string> dirToString(vector<SuperVSPtr *>);
vector<string> dirToString2(vector<void **>);
void createJsonFile(string);

extern "C" {
void getGCPointers();
}

#endif //VSCODE_MEMORY_MANAGER_LIBRARY_H
