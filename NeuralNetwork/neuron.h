//Luke Duane
//neuron.h

#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>
#include "dataset.h"
using namespace std;


class Neuron{
    public:
        Neuron(vector<double>); //inputs comes from the vector of nodes
        void setOutput(double);
        double getOutput();
        void trainData(vector<double>);
        double sigmoid(double);
        void backPropogate(double error);
    private:
        double summate();
        int numWeights;
        void setWeights();
        vector<double> weights;
        double getRandomWeight(); //returns a random weight
        vector<double> inputs;
};




