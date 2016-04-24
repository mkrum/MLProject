//A class to hold togther both the node and the readCsv class. 
//Michael Krumdick
#ifndef DATASET_H
#define DATASET_H

#include "node.h"
#include <string>
#include <cstdlib>
#include <vector>
#include <sstream>
#include <fstream>
#include <map>
#include <set>
#include <algorithm>
#include <time.h>
#include "iterator.h"
#include <functional>



class dataset {
    public:
        dataset(std::string, int); //constructor, enter the file name and the row you want to predict
        node iget();    //"iterative" get, use this when youre going through the learning data
        node tget();    //test get, use this to iterate through the test data
        void learn(std::function<void (node)>, int);
        void learn(std::function<void (node)>, std::function<void ()>, int);
        void test(std::function<void (node)>);
        std::vector<std::string> classes(); //returns the string values for the things you are trying to classify
        int columns();  //returns the number of columns(number of datapoints per object)
        node get(int);
        int tlength();  //length of the test data
   private:
        void reset();   //call this after you iterate
        int length();   //length of the learning data
        void setPercent(double);    //use this to set the percentge for your split
        //int tlength();  //length of the test data
        iterator begin();
        iterator end();
        iterator tbegin();
        iterator tend();
        void read(std::string, int);
        //node get(int);  
        void shuffle(); 
        void split();
        std::string readLine(std::string, std::vector<double>&, std::vector<std::string>&, int);
        void addToList(std::string*, std::vector<double>*, std::vector<std::string>*);
        bool isDouble(const char *);
        void swap(int, int, node*[]);
        void normalize();
        std::map<std::string, double> strings;
        std::vector<std::string> uniqueStrings;
        void addToStrings(std::string);
        void handleStrings();
        int numStrings;
        std::vector<double> maximum;
        std::vector<double> minimum;
        void addToExtrema(std::vector<double>);
        node* head;
        node* current;
        node* last;
        node* learnEnd;
        node* testHead;
        node* testCurrent;
        int len;
        int num;
        double percentage;
        std::set<std::string> identifiers;
};

#endif 
