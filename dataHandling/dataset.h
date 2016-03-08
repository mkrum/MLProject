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
        node iget();
        void reset();
        void shuffle();
    private:
        void swap(node *, node *, node *, node*);
        int fyrand(int);
        node * head;
        node * current;
        int length;
};

#endif 
