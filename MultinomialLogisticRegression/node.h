//Information node class, stores the information 
//Michael Krumdick
#ifndef NODE_H
#define NODE_H

#include <string>
#include <vector>

class node {
    public: 
        node(); //constructor
        void setData(std::string* , std::vector<double>* , std::vector<std::string>* );
        node& operator=(const node &); //overloaded operator to create a node
        double& operator[](int);
        node* next(); //brings you to next node
        void setNext(node *); //send a node, makes it the next node
        double getData(int) const; //takes from data sets
        std::string getBinate(int) const; //
        std::string getIdent() const; //returns identifer
        std::vector<double> dataVector() const;
        std::vector<std::string> binatesVector() const;
        void addToData(double);
        double size() const;
    private:
        std::string* identifier;
        node* nextNode;
        std::vector<double>* data;
        std::vector<std::string>* binates;
};

        


#endif
