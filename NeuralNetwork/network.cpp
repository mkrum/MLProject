//network.cpp
//Luke Duane

#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>
#include <string>
#include "network.h"
using namespace std;

//constructor
NeuralNetwork::NeuralNetwork(string file, int index, vector<double> Inputs, double Answer):data(file, index), neuron(index-1){
//    inputs=Inputs;
//    answer=Answer;
    createMap();
    learnWeights();
}

//takes in a node and then trains the network by feeding forward and then backpropagating
void NeuralNetwork::train(node n){
    inputs=n.dataVector();
    feedForward();
    for(int i=0; i<200; i++){
        neuron.backPropagate(answers[n.getIdent()]);
    }
}

void NeuralNetwork::learnWeights(){
    neuron.printWeights();
    data.learn(std::bind(&NeuralNetwork::train, this, std::placeholders::_1), 1);
    //data.learn(std::bind(&NeuralNetwork::train, this, std::placeholders::_1), 1);
    neuron.printWeights();
}

void NeuralNetwork::createMap(){
    vector<string> classifications=data.classes();
    double i, j;
    double numClasses=double(classifications.size());
    for(i=1, j=1/(numClasses*2); i<=numClasses; i++, j+=1/numClasses){
        answers[classifications[i-1]]=j;
        answerCenterPoints.push_back(j);
    }

    for(auto it = answers.cbegin(); it != answers.cend(); ++it)
    {
        cout << it->first << " " << it->second << " " << endl;
    }
    
}

//calls on neuron feed forward and sends inputs
void NeuralNetwork::feedForward(){
    neuron.feedForward(inputs);
}



