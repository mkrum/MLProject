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

using std::string;
using std::vector;

class mln {
    public:
        mln(std::string, int);
        std::pair<double, double> execute();
        void learn();
        double test();
    private:
        dataset data;
        kb dkb; //dynamic knowledge base
        int num;
        void debug();
        void learnWeights(node);
        void evolve();
        void classify(node);
        vector<string> objects;
        vector<vector<insight*> > knowledge; //information that is being tested 

};

#endif
