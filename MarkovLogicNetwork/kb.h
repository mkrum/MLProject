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
        kb(vector<string>, int);                        //base constructor, takes in all the objects and the index of the classifer
        friend std::ostream& operator<<(std::ostream &, const kb); 
        void update(vector<insight*>, string);          //Updates teh values saved in the knowledge base
        void generate(int, string, vector<insight*>&);  //Generates new logic equations for the knowledge base
        insight mutate(insight, insight);               //Mates two insights toghter to form a new one/generates a compelete new one
        void classify(node);                            //Uses the knowledge base to classify a node
        double rate() const;                            //returns the success rate
    private:
        std::map<string, vector<insight*>> base;        //the actual base
        std::default_random_engine generator;           
        std::map<string, double> lower;                 //saves the lowest values for each base
        void findDef();                                 //Finds the default value
        int size;
        vector<string> classes;
        void insert(insight*, string);
        int successes;
        int trials;
        string def;

};  

#endif
