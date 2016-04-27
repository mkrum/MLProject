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
    cout << "Percentage: " <<network1.getPercentage() << endl << "Time: " << network1.getDuration()<< endl; 
    NeuralNetwork network2("../datasets/breastcancer.csv", 2);
    network2.execute();
    cout << "Percentage: " <<network2.getPercentage() << endl << "Time: " << network2.getDuration()<< endl; 
    NeuralNetwork network3("../datasets/credit.csv", 16);
    network3.execute();
    cout << "Percentage: " <<network3.getPercentage() << endl << "Time: " << network3.getDuration()<< endl; 
    NeuralNetwork network4("../datasets/iris.csv", 5);
    network4.execute();
    cout << "Percentage: " <<network4.getPercentage() << endl << "Time: " << network4.getDuration()<< endl; 
    return 0;
}
