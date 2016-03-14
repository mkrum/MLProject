//Node implementation
#include "node.h"

node::node(){
    std::string ident = "empty node";
    std::vector<double> inData;
    std::vector<std::string> bin;
    identifier = ident;
    data = inData;
    binates = bin;
}

node::node(std::string ident, std::vector<double> inData, std::vector<std::string> bin) {
    identifier = ident;
    data = inData;
    binates = bin;
}

node& node::operator=(const node & copy){
    this->identifier = copy.getIdent();
    this->data = copy.dataVector();
    this->binates = copy.binatesVector();
    return *this;
}

std::vector<double> node::dataVector() const{
    return data;
}

std::vector<std::string> node::binatesVector() const{
    return binates;
}

node* node::next() {
    return nextNode;
}

void node::setNext(node * inNext) {
    nextNode = inNext;
}

double node::getData(int i) const{
    return data[i];
}

std::string node::getBinate(int i) const{
    return binates[i];
}

std::string node::getIdent() const{
    return identifier;
}
