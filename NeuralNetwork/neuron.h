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
        Neuron(int); //constructor that takes in the amount of weights
        ~Neuron();
        //GET SET FUNCTIONS
        double getOutput() { return output; }
        void setOutput(double op) { output=op; } //sets the output
        vector<double> getWeights() const { return weights; }
        vector<double> getDWeights() const { return dweights; }
        //FUNCTIONS USED IN THE NETWORK
        void feedForward(vector<double>);
        void backPropagate(double);
        void printWeights(); //prints all the weights
    private:
        //PRIVATE DATA OF THE NEURON
        vector<double> weights; //vector of all the weights
        vector<double> dweights;
        vector<double> inputs; //inputs vector; gets saved in the summate function
        int numWeights; //number of weights
        double output; //output of the neuron 
        //PRIVATE FUNCTIONS OF THE NEURON
        void setWeights(int); //sets all the weights
        double getRandomWeight(); //returns a random weight
        //MATH FUNCTIONS
        double sigmoid(double); //returns the result of the sigmoid function
        double summate(vector<double>); //look at .cpp
};




