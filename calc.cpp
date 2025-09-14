#include <iostream>
#include <string>
#include "calc.hpp"
using namespace std;

void again(){
    string string;
    string.clear();
    cin >> string;
if(string == "done"|| string == "Done"){
    return;}
    else{
        addString(string);
        again();
    }
}

int main () {
    cout<< "please input some strings type done when you are finished";
    again();
    cout<<input();

}
