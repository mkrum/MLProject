//Luke Duane
//neuron.h

#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

struct Connection{
    double weight;
    double deltaWeight;
};

class Neuron{
    public:
        Neuron();
    private:
        double output;
        vector<Connection> outputWeights;
        double getRandomWeight();
};




