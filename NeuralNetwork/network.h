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
        //NeuralNetwork(vector<double>);
        double feedForward();
        void train();
        Layer getHiddenLayer();
    private:
        double answer;
        void backPropagate();
        Layer hiddenlayer;
        dataset data; 
        vector<double> inputs; //temporary, just for testing REMOVE
        Neuron outputNeuron;
        double error;
};
