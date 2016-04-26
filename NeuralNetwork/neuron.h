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
        //Neuron(vector<double>, int); //inputs comes from the vector of nodes, int is how many different classifications there are
        double getOutput() { return output; }
        //void trainData(vector<double>);
        double sigmoid(double); //returns the result of the sigmoid function
        void backPropagate(double, vector<double>); //back propagates 
        double summate(vector<double>); //look at .cpp
        vector<double> getWeights();
        double sigmoidDerivative(double); //returns the derivative of the sigmoid function
        void calculateOutputGradients(double);
        void calculateHiddenGradients(Neuron);
        double getGradient() { return gradient; }
        void updateWeights(Neuron n, vector<Neuron>);
        vector<double> weights; //vector of all the weights
        //vector<double> dweights;
        double dweight;
    private:
        //void createMap();
        //map<double, double> answers;
        //double numTargets;
        int numWeights; //number of weights
        void setWeights(int); //sets all the weights
        double getRandomWeight(); //returns a random weight
        vector<double> inputs; //inputs vector; gets saved in the summate function
        //int type;
        void printWeights(); //prints all the weights
        double output;
        void setOutput(double op) { output=op; }
        double gradient;
        double calcDOW(Neuron);
};




