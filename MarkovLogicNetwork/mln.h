//Header for the Markov Logic Network Class
//Michael Krumdick

#ifndef MLN_H
#define MLN_H

#include "dataset.h"
#include "insight.h"
#include "kb.h"
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <ctime>
#include <utility>
#include <thread>

using std::string;
using std::cout;
using std::endl;
using std::vector;


class mln {
    public:
        mln(std::string, int);
        vector<double> execute();
        void learn();
        double test();
        void example();
        void tweaking();
    private:
        dataset data;
        kb dkb; //dynamic knowledge base
        int num;
        void debug();
        void learnWeights(node);
        void learnVec(vector<insight*>, node);
        void evolve();
        void classify(node);
        vector<string> objects;
        vector<vector<insight*> > knowledge; //information that is being tested 

};

#endif
