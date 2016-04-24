//Header for decision tree
//Marco Bruscia

#ifndef DT_H
#define DT_H

#include "dataset.h"
#include <string>
#include <iostream>
using namespace std;

class dt {
    public:
        dt(string, int);
        int getPrediction();
        double getOdds();
        int getHighestAttribute();
        void createTree();
        void traverseTree();
        dataset getData(){return data;};
        int getIndexOfLearn(){return indexofLearn;};
        Tree getTree(){return newTree;};
    private:
        dataset data;
        Tree newTree;
        int pred;
        int numAttributes;
        double predOdds;
        int indexOfLearn;
};

#endif
