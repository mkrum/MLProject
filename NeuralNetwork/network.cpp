//network.cpp
//Luke Duane

#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>
#include <string>
#include "network.h"
using namespace std;

//constructor
NeuralNetwork::NeuralNetwork(string file, int index, vector<double> Inputs, double Answer): data(file, index), neuron(index-1){
    inputs=Inputs;
    answer=Answer;
    train();
}

//takes in a node and then trains the network by feeding forward and then backpropagating
void NeuralNetwork::train(){
    feedForward();
    for(int i=0; i<200; i++){
        neuron.backPropagate(answer);
    }
    cout << neuron.getOutput() << endl;
}

//calls on neuron feed forward and sends inputs
void NeuralNetwork::feedForward(){
    neuron.feedForward(inputs);
}



