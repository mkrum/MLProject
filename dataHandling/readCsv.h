//CSV Reader class for MLProject
//Michael Krumdick
#ifndef READCSV_H
#define READCSV_H
#include "node.h"

#include <string>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <stdlib.h>

class readCsv {
    public:
        readCsv(std::string);
        node*  read(int col);
        int getLength();
    private:
        std::string readLine(std::string line, std::vector<double> &, std::vector<std::string> &, int col);
        std::string filename; 
        bool isDouble(const char * );
        int length;
};

#endif

