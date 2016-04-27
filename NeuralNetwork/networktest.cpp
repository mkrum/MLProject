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
    NeuralNetwork network2("../datasets/breastcancer.csv", 2);
    network2.execute();
    cout << network2.getPercentage() << network2.getDuration()<< endl;
    NeuralNetwork network3("../datasets/credit.csv", 16);
    network3.execute();
    cout << network3.getPercentage() << network3.getDuration()<< endl;
    NeuralNetwork network4("../datasets/iris.csv", 5);
    network4.execute();
    cout << network4.getPercentage() << network4.getDuration()<< endl;
    return 0;
}
