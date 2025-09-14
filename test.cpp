#include <iostream>
#include "calc.hpp"
#include <cassert>
int main() {
    addString("257*233+6v790-12");
    addString("61247833212+*9^3");
    assert(input()==14107);
    cout<< "test successful";
    return 0;
}