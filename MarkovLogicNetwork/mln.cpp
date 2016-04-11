//implemenation of the mln class
//Michael Krumdick

#include "mln.h"
#include <iostream>

#define INSIGHTS 4 //this determines the initial number of random insights, tweaked to perfection

using std::string;
using std::cout;
using std::endl;

mln::mln(string file, int index):data(file, index), objects(data.classes()){
    for(auto &object : objects){
        for(int j = 0; j < data.columns(); j++){
            for(int z = 0; z < INSIGHTS; z++){
                insight insert(j , object);
                knowledge.push_back(insert);
            }
        }
    }   
}

void mln::learnWeights(node n){
    for(auto &in : knowledge){
        in.check(n); 
    }
}

void mln::debug(){
    for(int i = 0; i < knowledge.size(); i++){
        cout << "*" << knowledge[i].weight() << endl;
    }
}

void mln::test(){
    data.learn(std::bind(&mln::learnWeights, this, std::placeholders::_1),std::bind(&mln::learnWeights, this, std::placeholders::_1), 2);
    debug();
}

