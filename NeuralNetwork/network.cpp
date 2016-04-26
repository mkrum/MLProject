//network.cpp
//Luke Duane

#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>
#include <string>
#include "network.h"
using namespace std;

NeuralNetwork::NeuralNetwork(string file, int index, vector<double> Inputs): data(file, index), hiddenlayer(Inputs), outputNeuron(hiddenlayer.computeLayer().size()){ //remove inputs vector later
//NeuralNetwork::NeuralNetwork(vector<double> Inputs): hiddenlayer(Inputs), outputNeuron(hiddenlayer.computeLayer().size()){
    inputs=Inputs;
//    data(file, index);
}

void NeuralNetwork::train(){

}

Layer NeuralNetwork::getHiddenLayer(){
    return hiddenlayer;
}

void NeuralNetwork::backPropagate(){
//    double dweight;
//    double step=.1;
//    double output=summate(
}

double NeuralNetwork::feedForward(){
    return outputNeuron.summate(hiddenlayer.getOutputs());
}

