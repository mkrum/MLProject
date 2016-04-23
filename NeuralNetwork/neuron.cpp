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




