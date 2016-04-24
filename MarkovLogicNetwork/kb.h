//Knowledge Base Class, this is going to hold all of the information neatly
//Michael Krumdick

#ifndef KB_H
#define KB_H

#include "insight.h"
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <random>
#include <functional>

using std::string;
using std::vector;

class kb{
    public:
        kb(vector<string>, int);
        friend std::ostream& operator<<(std::ostream &, const kb); 
        void update(vector<insight*>, string);
        void generate(int, string, vector<insight*>&);
        insight mutate(insight, insight);
        void classify(node);
        double rate() const;
    private:
        std::map<string, vector<insight*>> base;
        std::default_random_engine generator;
        std::map<string, double> lower;
        void findDef();
        int size;
        vector<string> classes;
        void insert(insight*, string);
        int successes;
        int trials;
        string def;

};  

#endif
