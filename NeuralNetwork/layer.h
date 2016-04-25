//Luke Duane
//layer.h


#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>
#include "dataset.h"
#include "neuron.h"
#include <map>
using namespace std;

#define NUMNEURONS 4

class Layer{
    public:
        Layer(vector<double>);
        vector<double> computeLayer(); 
    private:
        vector<Neuron> neurons;
        vector<double> inputs; 
};
