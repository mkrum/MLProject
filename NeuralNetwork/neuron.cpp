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
    type=Inputs[Inputs.size()-1];
    createMap();
    srand(time(NULL));
    numWeights=inputs.size();
    setWeights();
    summate();
    trainData(inputs);
    cout << "ANSWER: " << summate() << endl;
}

void Neuron::createMap(){
    double j=0;
    double i=0;
    double k=1/(numTargets*2);
    for(i=1,j=1/(numTargets*2); i<=numTargets; i++,j+=1/(numTargets)){
        answers[i]=j;    
    }
}

void Neuron::trainData(vector<double> inputs){
    cout << "training data" << endl;
    printWeights();
    for(int i=0; i<5000; i++)
        backPropogate();
    printWeights();
}

double Neuron::getRandomWeight(){
    return rand()/double(RAND_MAX);
}

double Neuron::sigmoid(double value){
    return (1.0/(1.0+exp(-value)));
}

void Neuron::setWeights(){
    for(int i=0; i<numWeights; i++){
        weights.push_back(getRandomWeight());
    }
}

double Neuron::summate(){
    double total=0;
    for(int i=0; i<weights.size(); i++){
        total+=weights[i]*inputs[i];
    }
    return sigmoid(total);
}

void Neuron::printWeights(){
    cout << "below are the weights" << endl;
    for(auto i : weights)
        cout << i << endl;
}

void Neuron::backPropogate(){
    double dweight;
    double step=.10;
    double output=summate();
    double delta=output*(1.0-output)*(answers[type]-output);
    for(int i=0; i<inputs.size(); i++){
        dweight=step*delta*inputs[i];
        weights[i]+=dweight;
    }
}



