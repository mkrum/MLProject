//Simple testing function for dataset 

#include <iostream>
#include "dataset.h"
#include <string>

int main() {
    dataset iris("iris.csv", 5);
    for(int i = 0; i < iris.length(); i++){
        std::cout << iris.iget()->getIdent();
    }
}
