//class for the network for an Artificial Neural Network
//Luke Duane

#include "dataset.h"
#include "layer.h"
#include <iostream>
#include <vector>
using namespace std;


class NeuralNetwork{
    public:
        NeuralNetwork(string, int, vector<double>, double); //constructor 
        NeuralNetwork(vector<double>, double);
        void feedForward(); //sends info through network
        void train(); //function to train for a node
        Neuron neuron; //neuron for the network
    private:
        double answer; //answer that comes from data
        dataset data; //dataset object
        vector<double> inputs; //temporary, just for testing REMOVE
};
