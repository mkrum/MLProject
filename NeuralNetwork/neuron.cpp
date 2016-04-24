//Luke Duane
//neuron.cpp


#include <iostream>
#include <cstdlib>
#include <vector>
#include "neuron.h"
using namespace std;

Neuron::Neuron(vector<double> Inputs, int classifications){
    for(int i=0; i<Inputs.size()-1; i++){
        inputs.push_back(Inputs[i]);
        
    }
    numTargets=classifications;
    createMap();
    srand(time(NULL));
    trainData(inputs);
    numWeights=inputs.size();
    setWeights();
    summate();
}

void Neuron::createMap(){
    double j=0;
    int i=0;
    double k=1/(numTargets*2);
    cout << "k" << k << endl;
    for(i=0,j=1/(numTargets*2); i<numTargets; i++,j+=1/(numTargets)){
        answers[i]=j;    
        cout << j;
        cout << answers[i] << endl;
    }
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
    double output=summate();
    //double delta=output*(1-output)*(targetValue-output);
    
}



