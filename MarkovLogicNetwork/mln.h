//Header for the Markov Logic Network Class
//Michael Krumdick

#ifndef MLN_H
#define MLN_H

#include "dataset.h"
#include <string>
#include <iostream>

class mln {
    public:
        mln(std::string, int);
    private:
        dataset data;
};

#endif
