//implemenation of the mln class
//Michael Krumdick

#include "mln.h"
#include <iostream>

#define INSIGHTS 30 //this determines the initial number of random insights, tweaked to perfection

using std::string;
using std::cout;
using std::endl;

mln::mln(string file, int index):data(file, index), objects(data.classes()), dkb(data.classes(), 10) {
    for(int i = 0; i < objects.size(); i++){
        for(int j = 0; j < data.columns(); j++){
            vector<insight*> temp;
            for(int z = 0; z < INSIGHTS; z++){
                insight *insert = new insight(data.columns() - 1, objects[i]);
                temp.push_back(insert);
            }
            knowledge.push_back(temp);
        }
    }   
}

void mln::learnWeights(node n){
    for(auto &objects : knowledge){
        for(auto &in : objects){
            in->check(n); 
        }
    }
}

void mln::debug(){
    cout << dkb;
}

void mln::evolve(){
    for(auto &know : knowledge){
        dkb.update(know, know[0]->ident());
        dkb.generate(INSIGHTS, know[0]->ident(), know);
    }
}

void mln::learn(){
    for(int i = 0; i < 100; i++){
        data.learn(std::bind(&mln::learnWeights, this, std::placeholders::_1), 1);
        evolve();
    }
    debug();
}

void mln::classify(node n){
    dkb.classify(n);
}

void mln::test(){
    data.test(std::bind(&mln::classify, this, std::placeholders::_1));
    cout << dkb.rate() << endl;
}

