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

void NeuralNetwork::execute(){
    const clock_t begin=clock();
    neuron.setWeights(data.columns());
    createMap();
    learnWeights();
    testData();
    duration=double(clock()-begin)/CLOCKS_PER_SEC;
    percentage=calculatePercentage();
}

//takes in a node and then trains the network by feeding forward and then backpropagating
void NeuralNetwork::train(node n){
    neuron.takeInputs(n.dataVector());
    feedForward(n.dataVector());
    for(int i=0; i<10; i++){
        neuron.backPropagate(answers[n.getIdent()]);
    }
}

void NeuralNetwork::learnWeights(){
    data.learn(std::bind(&NeuralNetwork::train, this, std::placeholders::_1), 20);
}

void NeuralNetwork::testData(){
    data.test(std::bind(&NeuralNetwork::testNode, this, std::placeholders::_1));
}

void NeuralNetwork::createMap(){
    vector<string> classifications=data.classes();
    double i, j;
    double numClasses=double(classifications.size());
    for(i=1, j=1/(numClasses*2); i<=numClasses; i++, j+=1/numClasses){
        answers[classifications[i-1]]=j;
        answerCenterPoints.push_back(j);
    }

    
}

void NeuralNetwork::printMap(){
    for(auto it = answers.cbegin(); it != answers.cend(); ++it)
    {
        cout << it->first << " " << it->second << " " << endl;
    }
}

//calls on neuron feed forward and sends inputs
void NeuralNetwork::feedForward(vector<double> Inputs){
    neuron.feedForward(Inputs);
}

void NeuralNetwork::testNode(node n){
    feedForward(n.dataVector());
    double result=neuron.getOutput();
    vector<double> difference;
    for(int i=0; i<answerCenterPoints.size(); i++){
        difference.push_back(abs(result-answerCenterPoints[i]));
    }
    int answerIndex=min_element(difference.begin(), difference.end())-difference.begin();
    if(answerCenterPoints[answerIndex]==answers[n.getIdent()])
        successes.push_back(1);
    else
        successes.push_back(0);
}

double NeuralNetwork::calculatePercentage(){
    int numSuccess;
    for(int i=0; i<successes.size(); i++){
        if(successes[i])
            numSuccess++;
    }
    return double(numSuccess)/double(successes.size());
}


