//Simple testing function for dataset 

#include <iostream>
#include "dataset.h"
#include <string>
#include <algorithm>

int main() {
    dataset iris("iris.csv", 5);
    iris.learn([](node temp){std::cout << temp.getIdent() << std::endl;}, [](node temp){std::cout << temp.getIdent() << std::endl;}, 2);
}
