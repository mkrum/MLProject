//Luke Duane
//neuron.h

#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>
using namespace std;

struct Connection{
    double weight;
    double deltaWeight;
};

class Neuron{
    public:
        Neuron();
        double getRandomWeight();
    private:
        double output;
        vector<Connection> outputWeights;
};




