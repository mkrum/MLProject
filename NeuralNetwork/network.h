//class for the network for an Artificial Neural Network
//Luke Duane

#include "neuron.h"
#include <iostream>
#include <vector>

using namespace std;


class NeuralNetwork{
    public:
        NeuralNetwork();
        void train();
    private:
        void backPropogate();

};
