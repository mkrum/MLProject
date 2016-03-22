//Simple testing function for dataset and to see if shuffle command works
//Marco Bruscia

#include <iostream>
#include "dataset.h"
#include <string>

int main() {
    dataset cred("credit.csv", 15);
    for(int i = 0; i < cred.length(); i++){
        std::cout << cred.iget()->getIdent();
    }
    cred.shuffle();
    std::cout << "shuffling order..." << std::endl;
    for(int i = 0; i < cred.length(); i++){
        std::cout << cred.iget()->getIdent();
    }
}
