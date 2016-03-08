//implmentation of the readCsv class
//Michael Krumdick
#include "readCsv.h"
#include <iostream>
readCsv::readCsv(std::string inFile){
    filename = inFile;
}

std::string readCsv::readLine(std::string line, std::vector<double> &dat, std::vector<std::string> &binates, int col){
    std::stringstream sstream(line);
    std::string part;
    std::vector<std::string> elems;
    std::string identifier;
    int i = 0;
    while(std::getline(sstream, part, ',')){
        i++;
        if(i == col){
            identifier = part;
            continue;
        }
        if(isDouble(part.c_str())){
            dat.push_back(std::stod(part));
        } else {
            binates.push_back(part);
        }
    }
    return identifier;
}

bool readCsv::isDouble(const char* str){
    char* endptr = 0;
    std::strtod(str, &endptr);
    if(*endptr != '\0' || endptr == str)
        return false;
    return true;
}

    

node * readCsv::read(int column){
    std::ifstream myStream;
    myStream.open(filename.c_str());
    if(myStream.is_open()){
        std::string line;
        myStream >> line;
        std::vector<double> tmpData;
        std::vector<std::string> tmpString;
        std::string ident = readLine(line, tmpData, tmpString, column);
        node head(ident, tmpData, tmpString);
        node * headpt = &head;
        node * tmp = &head;
        length = 0;
        while(!myStream.eof()) {
            length++;
            std::string line;
            myStream >> line;
            std::vector<double> tmpData;
            std::vector<std::string> tmpString;
            std::string ident = readLine(line, tmpData, tmpString, column);
            tmp->setNext(new node(ident, tmpData, tmpString));
            tmp = tmp->next();
        }
        myStream.close();
        return headpt;
    }
    return NULL;
}
    
int readCsv::getLength(){
    return length;
}
