//Information node class, stores the information 
//Michael Krumdick
#ifndef NODE_H
#define NODE_H

#include <string>
#include <vector>

class node {
    public: 
        node();
        node(std::string identifier, std::vector<double> data, std::vector<std::string> binates);
        node& operator=(const node &);
        node* next();
        void setNext(node *);
        double getData(int) const;
        std::string getBinate(int) const;
        std::string getIdent() const;
        std::vector<double> dataVector() const;
        std::vector<std::string> binatesVector() const;
    private:
        std::string identifier;
        std::vector<double> data;
        std::vector<std::string> binates;
        node* nextNode;
};

        


#endif
