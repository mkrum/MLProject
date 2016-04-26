//class for the network for an Artificial Neural Network
//Luke Duane

#include "dataset.h"
#include "layer.h"
#include <iostream>
#include <vector>
using namespace std;


class NeuralNetwork{
    public:
        NeuralNetwork(string, int, vector<double>, double); //remove vector later
        NeuralNetwork(vector<double>, double);
        void feedForward();
        void train();
        Neuron neuron;
        void backPropagate();
    private:
        double answer;
        dataset data; 
        vector<double> inputs; //temporary, just for testing REMOVE
        double error;
};
