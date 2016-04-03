//Simple testing function for dataset 

#include <iostream>
#include "dataset.h"
#include <string>

int main() {
    dataset iris("iris.csv", 1);
    iris.shuffle();
    for(int i = 0; i < iris.length(); i++){
       node temp = iris.iget();
       for(int j = 0; j < temp.size(); j++){
            std::cout << temp[j] << " ";
       }
       std::cout << std::endl;
    }
}
