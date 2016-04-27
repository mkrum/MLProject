//insight class, this will hold the various logic statements needed for the mln class
//Michael Krumdick

#ifndef INSIGHT_H
#define INSIGHT_H

#include "node.h"
#include <vector>
#include <random>
#include <functional>
#include <string>
#include <iostream>
#include <deque>

using std::string;
using std::vector;
using std::ostream;
    
class insight {
    friend class kb;
    public:
        insight(int, string);                               //base constructor, starts with a single column for a column
        void check(node);                                   //Call this for learning, generates weights by checking against practice data
        double weight() const;                              //Weight getter
        string ident() const;                               //Identifier getter
        int column() const;                                 //number of columns 
        int size() const;
        bool evaluate(node n);                              //evaluates if the statement is true for the input node
        friend ostream& operator<<(ostream &, insight);     //output overload
        void reset();                                       //resets the nodes data counters to zero
    private:
        int attempts;
        int successes;
        int failures;
        int length;
        int verif;
        int ocur;
        vector<int> order;
        vector<double> constants;
        vector<std::function<bool(double, double)>> comparisions;
        vector<std::function<bool(bool, bool)>> connectors;
        vector<int> compOrder;
        vector<int> connectOrder;
        string identifier;
        void vectorInit();
};

#endif
