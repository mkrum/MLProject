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
#include <algorithm>


class dataset {
    public:
        dataset(std::string, int);
        node get(int);
        node* iget();
        void reset();
        void shuffle();
        int length();
    private:
        void read(std::string, int);
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
        node* end;
        int len;
};

#endif 
