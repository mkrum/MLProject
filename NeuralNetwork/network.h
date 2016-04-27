//class for the network for an Artificial Neural Network
//Luke Duane


#include <functional>
#include "dataset.h"
#include "neuron.h"
#include <iostream>
#include <vector>
#include <map>
using namespace std;


class NeuralNetwork{
    public:
        //CONSTRUCTOR
        NeuralNetwork(string, int); //constructor 
        //PUBLIC FUNCTION TO RUN
        void execute(); //runs the algorithm on the file
        //GET AND SET FUNCTIONS
        double getPercentage() { return percentage; }
        double getDuration() { return duration; }
    private:

        Neuron neuron; //neuron for the network
        double percentage; //successes/trials
        double duration; //how long it takes to execute
        void feedForward(vector<double>); //sends info through network
        void train(node); //function to train for a node
        void learnWeights();
        void getData(node); //gets data from the node
        void createMap();
        double calculatePercentage();
        void printMap(); //prints keys and values of answers map
        double answer; //answer that comes from data
        dataset data; //dataset object
        vector<double> inputs; //inputs vector, gets updated with each node
        map<string, double> answers;
        vector<double> answerCenterPoints;
        vector<int> successes;
        void testNode(node);
        void testData();
};
