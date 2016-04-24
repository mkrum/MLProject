//Luke Duane
//neuron.cpp


#include <iostream>
#include <cstdlib>
#include <vector>
#include "neuron.h"
using namespace std;

Neuron::Neuron(vector<double> Inputs){
    inputs=Inputs; 
    srand(time(NULL));
    trainData(inputs);
    numWeights=inputs.size();
    setWeights();
    summate();
}

void Neuron::trainData(vector<double> inputs){
    cout << "training data" << endl;
}

double Neuron::getRandomWeight(){
    return rand()/double(RAND_MAX);
}

double Neuron::sigmoid(double value){
    return (1.0/(1+exp(-value)));
}

void Neuron::setWeights(){
    for(int i=0; i<numWeights; i++){
        weights.push_back(getRandomWeight());
        cout << weights[i] << endl;
    }
}

double Neuron::summate(){
    double total=0;
    for(int i=0; i<numWeights; i++){
        total+=weights[i]*inputs[i];
    }
    return sigmoid(total);
}

void Neuron::backPropogate(double error){
    double step=.01;

}



