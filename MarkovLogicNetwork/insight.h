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

using std::string;
using std::vector;
using std::ostream;
    
class insight {
    public:
        insight(int, string);  //base constructor, starts with a single column for a column
        insight(int, int, string); //constructor for an insight that compares two columns
        insight(const insight &, const insight &);  //mating, two parents
        bool check(node);
        double weight() const;
        string ident() const;
        int column() const;
        friend ostream& operator<<(ostream &, const insight); 
    private:
        int attempts;
        int successes;
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
