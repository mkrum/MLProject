//Information node class, stores the information 
//Michael Krumdick
#ifndef NODE_H
#define NODE_H

#include <string>
#include <vector>

class node {
    public: 
        node(std::string identifier, std::vector<double> data, std::vector<std::string> binates);
        node*  next();
        void setNext(node *);
        double getData(int);
        std::string getBinate(int);
        std::string getIdent();
    private:
        std::string identifier;
        std::vector<double> data;
        std::vector<std::string> binates;
        node * nextNode;
};

        


#endif
