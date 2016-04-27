//Simple testing function for dataset 

#include <iostream>
#include "dataset.h"
#include <string>
#include <algorithm>
using namespace std;
int main() {
    dataset iris("iris.csv", 5);
    iris.learn([](node n){cout << n.getIdent() << endl;}, 4);
    cout << "*" << endl;
    iris.test([](node n){cout << n.getIdent() << endl;});
    cout << "*" << endl;
    iris.test([](node n){cout << n.getIdent() << endl;});



}
