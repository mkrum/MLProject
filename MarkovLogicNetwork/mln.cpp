//implemenation of the mln class
//Michael Krumdick

#include "mln.h"
#include <iostream>

#define INSIGHTS 10 //this determines the initial number of random insights, tweaked to perfection

using std::string;
using std::cout;
using std::endl;

mln::mln(string file, int index):data(file, index), objects(data.classes()){
    for(int i = 0; i < objects.size(); i++){
        for(int j = 0; j < data.columns(); j++){
            vector<insight> temp;
            for(int z = 0; z < INSIGHTS; z++){
                insight insert(data.columns(), objects[i]);
                temp.push_back(insert);
            }
            knowledge.push_back(temp);
        }
    }   
}

void mln::learnWeights(node n){
    for(auto objects : knowledge){
        for(auto &in : objects){
            in.check(n); 
        }
    }
}

void mln::debug(){
    for(int i = 0; i < knowledge.size(); i++){
        for(int j = 0; j < knowledge[i].size(); j++){
            cout << knowledge[i][j].weight() << " ";
            knowledge[i][j].print();
        }
    }
}

void mln::evolve(){
    vector<vector<insight> > nextGen;
    std::map<double, int> compare;
    vector<vector<double> > values;
    for(int i = 0; i < knowledge.size(); i++){
        vector<double> valTemp;
        for(int j = 0; j < knowledge.size(); j++){
            valTemp.push_back(knowledge[i][j].weight());
            compare[knowledge[i][j].weight()] = i;
        }
        values.push_back(valTemp);
    }
    for(auto &val : values){
        std::sort(val.begin(), val.end(), std::greater<double>());
    }
    int survivors = values[0].size()/10;
    for(int z = 0; z < knowledge.size(); z++){
        vector<insight> nextGenTemp;
        for(int i = 0; i < survivors; i++){
            insight temp(data.columns(), "test");// = knowledge[z][compare[values[z][i]]];
            nextGenTemp.push_back(temp);
            for(int j = 0; j < 10; j++){
                insight mutate(data.columns(), temp.ident());
                nextGenTemp.push_back(mutate);
            }
            nextGen.push_back(nextGenTemp);
        }
    }
    knowledge = nextGen;
}  

void mln::test(){
    debug();
    for(int i = 0; i < 1; i++){
        data.learn(std::bind(&mln::learnWeights, this, std::placeholders::_1));
        std::cout << i << std::endl;
        evolve();
    }
    debug();
}

