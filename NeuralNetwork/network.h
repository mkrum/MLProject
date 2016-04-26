//class for the network for an Artificial Neural Network
//Luke Duane

#include "dataset.h"
#include "layer.h"
#include <iostream>
#include <vector>
#include <map>
using namespace std;


class NeuralNetwork{
    public:
        NeuralNetwork(string, int, vector<double>, double); //constructor 
        NeuralNetwork(vector<double>, double);
        void feedForward(); //sends info through network
        void train(node); //function to train for a node
        Neuron neuron; //neuron for the network
    private:
        void getData(node); //gets data from the node
        void createMap();
        double answer; //answer that comes from data
        dataset data; //dataset object
        vector<double> inputs; //inputs vector, gets updated with each node
        map<string, double> answers;
        vector<double> answerCenterPoints;
};
