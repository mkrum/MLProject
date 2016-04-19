//Header for the Markov Logic Network Class
//Michael Krumdick

#ifndef MLN_H
#define MLN_H

#include "dataset.h"
#include "insight.h"
#include <string>
#include <iostream>
#include <vector>
#include <map>

using std::string;
using std::vector;

class mln {
    public:
        mln(std::string, int);
        void test();
    private:
        dataset data;
        void debug();
        void updateKB(vector<insight>);
        void learnWeights(node);
        void evolve();
        vector<string> objects;
        std::map< string, vector<insight> > kb;
        vector<vector<insight> > knowledge; //information that is being tested 
        std::map< string, double > lowerBound;

};

#endif
