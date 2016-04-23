//Luke Duane
//neuron.cpp


#include <iostream>
#include <cstdlib>
#include <vector>
#include "neuron.h"
using namespace std;

Neuron::Neuron(){
    srand(time(NULL));
}

double Neuron::getRandomWeight(){
    return rand()/double(RAND_MAX);
}

void Neuron::setOutput(double num){
    output=num;
}

double Neuron::getOutput(){
    return output;
}




