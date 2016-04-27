//Luke Duane
//neuron.h

#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>
#include <map>
using namespace std;


class Neuron{
    public:
        Neuron();
        ~Neuron();
        //GET SET FUNCTIONS
        double getOutput() { return output; }
        void setOutput(double op) { output=op; } //sets the output
        //FUNCTIONS USED IN THE NETWORK
        void feedForward(vector<double>);
        void backPropagate(double);
        void printWeights(); //prints all the weights
        void setWeights(int); //sets all the weights
        void takeInputs(vector<double>);
    private:
        //PRIVATE DATA OF THE NEURON
        vector<double> weights; //vector of all the weights
        vector<double> dweights;
        vector<double> inputs; //inputs vector; gets saved in the summate function
        vector<double> getWeights() const { return weights; }
        vector<double> getDWeights() const { return dweights; }
        int numWeights; //number of weights
        double output; //output of the neuron 
        //PRIVATE FUNCTIONS OF THE NEURON
        double getRandomWeight(); //returns a random weight
        //MATH FUNCTIONS
        double sigmoid(double); //returns the result of the sigmoid function
        double summate(vector<double>); //look at .cpp
};




