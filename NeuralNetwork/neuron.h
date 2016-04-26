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
        void setOutput(double);
        double getOutput();
        //void trainData(vector<double>);
        double sigmoid(double); //returns the result of the sigmoid function
        void backPropagate(double, vector<double>); //back propagates 
        double summate(vector<double>); //look at .cpp
        vector<double> getWeights();
    private:
        //void createMap();
        //map<double, double> answers;
        //double numTargets;
        int numWeights; //number of weights
        void setWeights(int); //sets all the weights
        vector<double> weights; //vector of all the weights
        double getRandomWeight(); //returns a random weight
        vector<double> inputs; //inputs vector; gets saved in the summate function
        //int type;
        void printWeights(); //prints all the weights
        vector<double> dweights;
};




