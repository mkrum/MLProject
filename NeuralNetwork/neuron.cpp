//Luke Duane
//neuron.cpp


#include <iostream>
#include <cstdlib>
#include <vector>
#include "neuron.h"
using namespace std;

Neuron::Neuron(){

}

double Neuron::getRandomWeight(){
    return rand()/double(RAND_MAX);
}




