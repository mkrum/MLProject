//Luke Duane
//layer.cpp


#include <iostream>
#include <cstdlib>
#include <vector>
#include "layer.h"
using namespace std;

Layer::Layer(vector<double> Inputs){
    inputs=Inputs;
    for(int i=0; i<inputs.size(); i++){
        Neuron tmp(inputs.size());
        neurons.push_back(tmp);
    }
}

vector<double> Layer::getOutputs(){
    return outputs;   
}

vector<double> Layer::computeLayer(){
    outputs.clear();
    for(int i=0; i<neurons.size(); i++){
        outputs.push_back(neurons[i].summate(inputs));
    }
    return outputs;
}










