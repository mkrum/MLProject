//Simple testing function for dataset 

#include <iostream>
#include "dataset.h"
#include <string>
#include <algorithm>
using namespace std;
int main() {
    dataset iris("iris.csv", 5);
    /*for(int i = 0; i < iris.length(); i++){
        std::cout << iris.iget()->getData(0) << std::endl;
    }*/
    
    cout << iris.get(0).getData(0) << endl;
    cout << iris.get(0).getData(3) << endl;
}
