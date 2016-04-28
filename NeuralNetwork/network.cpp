//network.cpp
//Luke Duane

#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>
#include <string>
#include "network.h"
#include <ctime>
using namespace std;

//constructor
NeuralNetwork::NeuralNetwork(string file, int index):data(file, index),neuron(){
}

//executes the neural network
void NeuralNetwork::execute(){
    const clock_t begin=clock(); //starts the clock
    neuron.setWeights(data.columns()); //sets the weights on the neuron
    createMap(); //creates the map from strings to doubles for the network
    learnWeights(); //learns weights for the network
    testData(); //tests the data
    duration=double(clock()-begin)/CLOCKS_PER_SEC; //how long it takes
    percentage=calculatePercentage(); //calculates the percentage
}

//takes in a node and then trains the network by feeding forward and then backpropagating
void NeuralNetwork::train(node n){
    neuron.takeInputs(n.dataVector()); //sends the vector
    feedForward(n.dataVector()); //feeds forward the input vector
    for(int i=0; i<10; i++){ // goes through and backpropagates 10 times; this can be tuned
        neuron.backPropagate(answers[n.getIdent()]);
    }
}

void NeuralNetwork::learnWeights(){
    //functional programming, sends a node to the function 
    data.learn(std::bind(&NeuralNetwork::train, this, std::placeholders::_1), 20);
}

void NeuralNetwork::testData(){
    //functional programming, sending a node to the function
    data.test(std::bind(&NeuralNetwork::testNode, this, std::placeholders::_1));
}

void NeuralNetwork::createMap(){
    vector<string> classifications=data.classes(); //saves all the answers
    double i, j;
    double numClasses=double(classifications.size()); //number of classes
    for(i=1, j=1/(numClasses*2); i<=numClasses; i++, j+=1/numClasses){ //cycles through and maps out the answers to doubles
        answers[classifications[i-1]]=j; //assigns it
        answerCenterPoints.push_back(j); //adds to the answers vector
    }

    
}

void NeuralNetwork::printMap(){
    //prints map, used for testing purposes
    for(auto it = answers.cbegin(); it != answers.cend(); ++it)
    {
        cout << it->first << " " << it->second << " " << endl;
    }
}

//calls on neuron feed forward and sends inputs
void NeuralNetwork::feedForward(vector<double> Inputs){
    neuron.feedForward(Inputs); //sends inputs to the feed forward function
}

//tests the weights on a certain noide
void NeuralNetwork::testNode(node n){
    feedForward(n.dataVector()); //feeds forward
    double result=neuron.getOutput(); //gets result
    vector<double> difference; //vector to check difference
    for(int i=0; i<answerCenterPoints.size(); i++){ //gets the difference between each different answer and the result
        difference.push_back(abs(result-answerCenterPoints[i]));
    }
    //gets the minimum element   
    int answerIndex=min_element(difference.begin(), difference.end())-difference.begin();
    //checks the answer
    if(answerCenterPoints[answerIndex]==answers[n.getIdent()])
        successes.push_back(1); //successes
    else
        successes.push_back(0); //fail
}

double NeuralNetwork::calculatePercentage(){
    int numSuccess; //counter for successes
    for(int i=0; i<successes.size(); i++){ //loops through the vector
        if(successes[i]) //1 for success, 0 for failure
            numSuccess++;
    }
    return double(numSuccess)/double(successes.size()); //returns percentage
}


