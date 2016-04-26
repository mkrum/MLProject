//network.cpp
//Luke Duane

#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>
#include <string>
#include "network.h"
using namespace std;

NeuralNetwork::NeuralNetwork(string file, int index, vector<double> Inputs, double Answer): data(file, index), hiddenlayer(Inputs), outputNeuron(hiddenlayer.computeLayer().size()){ //remove inputs vector later
//NeuralNetwork::NeuralNetwork(vector<double> Inputs): hiddenlayer(Inputs), outputNeuron(hiddenlayer.computeLayer().size()){
    inputs=Inputs;
    answer=Answer;
//    data(file, index);
}

void NeuralNetwork::train(){

}

Layer NeuralNetwork::getHiddenLayer(){
    return hiddenlayer;
}

void NeuralNetwork::backPropagate(){
    //Calculating the overall error over the whole network
    error=0;

    //Calculating output layer gradients

    //Calculate hidden layer gradients

    //Go from output layer to hidden layer and update connection weights


}



double NeuralNetwork::feedForward(){
    return outputNeuron.summate(hiddenlayer.getOutputs());
}

