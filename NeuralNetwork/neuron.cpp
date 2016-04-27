//Luke Duane
//neuron.cpp


#include <iostream>
#include <cstdlib>
#include <vector>
#include "neuron.h"
#include <random>
#include <chrono>
using namespace std;

//constructor
Neuron::Neuron(int numWeights){
    setWeights(numWeights);
}

//deconstructor
Neuron::~Neuron(){

}

//activation function used
double Neuron::sigmoid(double value){
    return (1.0/(1.0+exp(-value)));
}

//I summate from the layer and that works, but what about when I want to summate from the backpropagate function? idk
double Neuron::summate(vector<double> Inputs){
    inputs=Inputs;
    double total=0;
    for(int i=0; i<weights.size(); i++){
        total+=weights[i]*Inputs[i];
    }
    return sigmoid(total);
}

//function used to print weights during testing
void Neuron::printWeights(){
    cout << "below are the weights" << endl;
    for(auto i : weights)
        cout << i << endl;
}

//backpropagates, changing the weights depending on the answer
void Neuron::backPropagate(double answer){
    dweights.clear();
    double step=.02;
    setOutput(summate(inputs));
    double outputLocal=summate(inputs);
    double delta=getOutput()*(1.0-getOutput())*(answer-getOutput());
    for(int i=0; i<inputs.size(); i++){
        dweights.push_back(step*delta*inputs[i]);
        weights[i]+=dweights[i];
    }
}

//gives weights random numbers
void Neuron::setWeights(int numWeights){
    for(int i=0; i<numWeights; i++){
        weights.push_back(getRandomWeight());
    }
}

//returns a random double between 0 and 1 
double Neuron::getRandomWeight(){
    unsigned seed=chrono::system_clock::now().time_since_epoch().count();
    default_random_engine generator (seed);
    uniform_real_distribution<double> distribution(0.0, 1.0);
    return distribution(generator);
}

//takes in inputs from the network and feeds them forward by summating
void Neuron::feedForward(vector<double> Inputs){
    output=summate(Inputs);
}




