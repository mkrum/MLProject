//implemenation of the mln class
//Michael Krumdick

#include "mln.h"
#include <iostream>

#define INSIGHTS 10 //this determines the initial number of random insights, tweaked to perfection

using std::string;
using std::cout;
using std::endl;

mln::mln(string file, int index):data(file, index), objects(data.classes()) {
    for(int i = 0; i < objects.size(); i++){
        for(int j = 0; j < data.columns(); j++){
            vector<insight> temp;
            for(int z = 0; z < INSIGHTS; z++){
                insight insert(data.columns(), objects[i]);
                temp.push_back(insert);
            }
            knowledge.push_back(temp);
            lowerBound[objects[i]] = 0;
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

void mln::updateKB(vector<insight> newInfo){
    string ident = newInfo[0].ident();
    vector<insight> base = kb[ident];
    for(auto add : newInfo){
        double tweight = add.weight();
        if(tweight <= lowerBound[ident]){
            break;
        }
        for(int i = 0; i < base.size(); i++){
            if(tweight > base[i].weight()){
                base.insert(base.begin() + i, add);
                if(base.size() > 10){
                    base.pop_back();
                }
                if(i == base.size() - 1){
                    lowerBound[ident] = tweight;
                }
                break;
            }
        }
    }
}

void mln::debug(){
    for(auto item : kb){
        cout << item.second.size() << " " <<  item.first << endl;
    }
}

void mln::evolve(){
    for(auto &know : knowledge){
        vector<insight> nextGen;
        std::map<double, int> compare;
        vector<double> values;
        for(int i = 0; i < know.size(); i++){
            values.push_back(know[i].weight());
            compare[know[i].weight()] = i;
        }
        std::sort(values.begin(), values.end(), std::greater<double>());
        int survivors = values.size()/10;
        for(int z = 0; z < know.size(); z++){
            for(int i = 0; i < survivors; i++){
                insight temp = know[compare[values[i]]];
                nextGen.push_back(temp);
                for(int j = 0; j < INSIGHTS; j++){
                    insight mutate(data.columns(), temp.ident());
                    nextGen.push_back(mutate);
                }
            }
        }
        updateKB(nextGen);
        know = nextGen;
    }
}

void mln::test(){
    for(int i = 0; i < 2; i++){
        data.learn(std::bind(&mln::learnWeights, this, std::placeholders::_1));
        evolve();
    }
    debug();
}
