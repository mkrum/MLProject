//network.cpp
//Luke Duane

#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>
#include <string>
#include "network.h"
using namespace std;

//NeuralNetwork::NeuralNetwork(string file, int index, vector<double> Inputs, double Answer): data(file, index), hiddenlayer(Inputs), outputNeuron(hiddenlayer.computeLayer().size()){ //remove inputs vector later
NeuralNetwork::NeuralNetwork(vector<double> Inputs, double Answer): hiddenlayer(Inputs), outputNeuron(hiddenlayer.computeLayer().size()){
    cout << "1";
    inputs=Inputs;
    answer=Answer;
//    data(file, index);
    cout << "2";
}

void NeuralNetwork::train(){

}

Layer NeuralNetwork::getHiddenLayer(){
    return hiddenlayer;
}

void NeuralNetwork::backPropagate(){
    //Calculating the overall error over the whole network
    error=0;
    double delta=answer-outputNeuron.getOutput();
    error=delta;
    
    //Calculating output layer gradients
    outputNeuron.calculateOutputGradients(answer);

    //Calculate hidden layer gradients
    for(int i=0; i<hiddenlayer.getNeurons().size(); i++){
        hiddenlayer.getNeurons()[i].calculateHiddenGradients(outputNeuron);
    }

    //Go from output layer to hidden layer and update connection weights
    outputNeuron.updateWeights(outputNeuron, hiddenlayer.getNeurons()); //change weights of output layer
    /*
    for(int i=0; i<hiddenlayer.getNeurons().size(); i++){
        hiddenlayer.getNeurons()[i].updateWeights(hiddenlayer.getNeurons()[i],);
    }
    */


}



double NeuralNetwork::feedForward(){
    return outputNeuron.summate(hiddenlayer.getOutputs());
}

