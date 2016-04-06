//Simple testing function for dataset 

#include <iostream>
#include "dataset.h"
#include <string>
#include <algorithm>

int main() {
    dataset iris("iris.csv", 5);
    for(int z = 0; z < 2; z++){
        std::cout << "LEARNING" << std::endl;
        for(int i = 0; i < iris.length(); i++){
           node temp = iris.iget();
           for(int j = 0; j < temp.size(); j++){
                std::cout << temp[j] << " ";
           }
           std::cout << std::endl;
        }
        std::cout << "TESTING" << std::endl;
        for(int j = 0; j < iris.tlength(); j++){
            node temp = iris.tget();
            for(int j = 0; j < temp.size(); j++){
                std::cout << temp[j] << " ";
           }
           std::cout << std::endl;
        }
        iris.reset();
    }
    std::for_each(iris.tbegin(), iris.tend(), [](node temp){static int i = 0; std::cout << temp.getIdent() << std::endl;});
}
