//A class to hold togther both the node and the readCsv class. 
//Michael Krumdick
#ifndef DATASET_H
#define DATASET_H

#include "node.h"
#include "readCsv.h"
#include <string>

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
        int fyrand(int);
        node* head;
        node* current;
        node* end;
        int len;
};

#endif 
