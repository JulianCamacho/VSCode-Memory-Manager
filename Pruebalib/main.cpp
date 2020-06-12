#include "VSPlib/VSPtr.h"
#include "VSPlib/library.h"
#include <fstream>
#include <iostream>
using namespace std;

int main(){

    VSPtr<bool> myPtr0 = VSPtr<bool>::New();
    VSPtr<int> myPtr1 = VSPtr<int>::New();
    VSPtr<int> myPtr2 = VSPtr<int>::New();
    //VSPtr<bool> myPtr3 = VSPtr<bool>::New();
    //VSPtr<int> myPtr4 = VSPtr<int>::New();

    myPtr0 = true;
    myPtr1 = 99;
    myPtr2 = 827;
    //myPtr3 = false;
    //myPtr4 = 29;

    return 0;
}
