//class for the network for an Artificial Neural Network
//Luke Duane

#include "dataset.h"
#include "layer.h"
#include <iostream>
#include <vector>
using namespace std;


class NeuralNetwork{
    public:
        NeuralNetwork(string, int, vector<double>); //remove vector later
        //NeuralNetwork(vector<double>);
        double feedForward();
        void train();
    private:
        void backPropogate();
        Layer hiddenlayer;
        dataset data; 
        vector<double> inputs; //temporary, just for testing REMOVE
        Neuron outputNeuron;
};
