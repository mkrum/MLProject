//Node implementation
#include "node.h"

node::node(){
    identifier = NULL;
    data = NULL;
    binates = NULL;
    nextNode = NULL;
}

void node::setData(std::string* inIdent, std::vector<double>* inData, std::vector<std::string>* inBin) {
    identifier = inIdent;
    data = inData;
    binates = inBin;
}

node& node::operator=(const node & copy){
    std::string* tindent = new std::string(copy.getIdent());
    std::vector<double>* dat = new std::vector<double>(copy.dataVector());
    std::vector<std::string>* bin = new std::vector<std::string>(copy.binatesVector());
    data = dat;
    identifier = tindent;
    binates = bin;
    return *this;
}

std::vector<double> node::dataVector() const{
    return *data;
}

std::vector<std::string> node::binatesVector() const{
    return *binates;
}

node* node::next() {
    return nextNode;
}

void node::setNext(node * inNext) {
    nextNode = inNext;
}

double node::getData(int i) const{
    std::vector<double> tData = *data;
    return tData[i];
}

std::string node::getBinate(int i) const{
    std::vector<std::string> tBin = *binates;
    return tBin[i];
}


std::string node::getIdent() const{
    return *identifier;
}
