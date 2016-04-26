//Luke Duane
//neuron.cpp


#include <iostream>
#include <cstdlib>
#include <vector>
#include "neuron.h"
#include <random>
#include <chrono>
using namespace std;

Neuron::Neuron(int numWeights){
    /*
    for(int i=0; i<Inputs.size()-1; i++){
        inputs.push_back(Inputs[i]); 
    }
    */
//    numTargets=classifications;
//    type=Inputs[Inputs.size()-1];
//    createMap();
//    numWeights=inputs.size();
    setWeights(numWeights);
//    summate();
//    trainData(inputs);
//    cout << "ANSWER: " << summate() << endl;
}

Neuron::~Neuron(){

}

/*
void Neuron::createMap(){
    double j=0;
    double i=0;
    double k=1/(numTargets*2);
    for(i=1,j=1/(numTargets*2); i<=numTargets; i++,j+=1/(numTargets)){
        answers[i]=j;    
    }
}
*/

/*
void Neuron::trainData(vector<double> inputs){
    cout << "training data" << endl;
    printWeights();
    for(int i=0; i<5000; i++)
        backPropagate();
    printWeights();
}
*/

double Neuron::getRandomWeight(){
    unsigned seed=chrono::system_clock::now().time_since_epoch().count();
    default_random_engine generator (seed);
    uniform_real_distribution<double> distribution(0.0, 1.0);
    return distribution(generator);
}

double Neuron::sigmoid(double value){
    return (1.0/(1.0+exp(-value)));
}

double Neuron::sigmoidDerivative(double value){
    return sigmoid(value)*(1-sigmoid(value));
}

void Neuron::setWeights(int numWeights){
    for(int i=0; i<numWeights; i++){
        weights.push_back(getRandomWeight());
    }
}

//I summate from the layer and that works, but what about when I want to summate from the backpropagate function? idk
double Neuron::summate(vector<double> Inputs){
//    inputs=Inputs;
    double total=0;
    for(int i=0; i<weights.size(); i++){
        total+=weights[i]*Inputs[i];
    }
    return sigmoid(total);
}

void Neuron::printWeights(){
    cout << "below are the weights" << endl;
    for(auto i : weights)
        cout << i << endl;
}

//double check that these are the parameters that you want
void Neuron::backPropagate(double error, vector<double> Inputs){
    dweights.clear();
    double step=.10;
    double output=summate(Inputs);
    double delta=output*(1.0-output)*(error-output);
    for(int i=0; i<inputs.size(); i++){
        dweights.push_back(step*delta*Inputs[i]);
        weights[i]+=dweights[i];
    }
}

vector<double> Neuron::getWeights(){
    return weights;
}

