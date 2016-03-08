//Node implementation
#include "node.h"

node::node(std::string ident, std::vector<double> inData, std::vector<std::string> bin) {
    identifier = ident;
    data = inData;
    binates = bin;
}

node * node::next() {
    return nextNode;
}

void node::setNext(node * inNext){
    nextNode = inNext;
}

double node::getData(int i) {
    return data[i];
}

std::string node::getBinate(int i){
    return binates[i];
}

std::string node::getIdent(){
    return identifier;
}
