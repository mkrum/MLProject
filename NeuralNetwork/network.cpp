//network.cpp
//Luke Duane

#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>
#include <string>
#include "network.h"
using namespace std;

//NeuralNetwork::NeuralNetwork(string file, int index, vector<double> Inputs){ //remove inputs vector later
NeuralNetwork::NeuralNetwork(vector<double> Inputs): hiddenlayer(Inputs), outputNeuron(hiddenlayer.computeLayer().size()){
    inputs=Inputs;
//    data(file, index);
}

void NeuralNetwork::train(){

}

void NeuralNetwork::backPropogate(){

}

double NeuralNetwork::feedForward(){
    return outputNeuron.summate(hiddenlayer.getOutputs());
}

