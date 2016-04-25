//Luke Duane
//neuron.h

#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>
#include "dataset.h"
#include <map>
using namespace std;


class Neuron{
    public:
        Neuron(vector<double>, int); //inputs comes from the vector of nodes, int is how many different classifications there are
        void setOutput(double);
        double getOutput();
        void trainData(vector<double>);
        double sigmoid(double);
        void backPropogate();
    private:
        void createMap();
        map<double, double> answers;
        double numTargets;
        double summate();
        int numWeights;
        void setWeights();
        vector<double> weights;
        double getRandomWeight(); //returns a random weight
        vector<double> inputs;
        int type;
        void printWeights();
};




