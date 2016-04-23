//Luke Duane
//neuron.cpp


#include <iostream>
#include <cstdlib>
#include <vector>
#include "neuron.h"
using namespace std;

Neuron::Neuron(vector<double> inputs){
    srand(time(NULL));
    trainData(inputs);
    numWeights=inputs.size();
    setWeights();
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





