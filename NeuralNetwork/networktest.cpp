//networktest.cpp
//Luke Duane
//testing feed forward implementation in Neural Network


#include <iostream>
#include <vector>
#include <cstdlib>
#include "network.h"
using namespace std;

int main(){
    NeuralNetwork network1("../datasets/wine.csv", 1);
    network1.execute();
    cout << network1.getPercentage() << network1.getDuration()<< endl;
    return 0;
}
