//Implementation for the dataset class
//Michael Krumdick
#include "dataset.h"
#include <iostream>

dataset::dataset(std::string file, int col) {
    read(file, col);
}

node dataset::get(int index){
    node* ret = head;
    int i = 0;
    while(i < index && ret->next() != NULL){
        i++;
        ret = ret->next();
    }
    return *ret;
}

node* dataset::iget(){
    if(current->next() != NULL){
        node* tmp = current;
        current = current->next();
        return tmp;
    } else{
        return current;
    }
}

void dataset::reset() {
    current = head;
}
//inspired by a similar function that I used for my CSinglePerceptron project
//(https://github.com/mkrum/CSinglePerceptron.git)
//Fisher-Yates Shuffle
void dataset::shuffle(){
    reset();
    node * deck[len];
    node * tmp = head;
    for(int i = 0; i < len; i++){
        deck[i] = tmp;
        tmp = tmp->next();
    }
    for(int j = len - 1; j > 1; j--){
        int z = fyrand(j + 1);
        swap(j, z, deck);
    }
}

int dataset::fyrand(int n){
    srand(time(NULL));
    int limit = RAND_MAX - RAND_MAX % n;
    int num;
    do{
        num = rand();
    }while(num >= limit);
    return num % n + 1;
}

void dataset::swap(int j, int z, node * deck[]){
    deck[j-1]->setNext(deck[z]);
    deck[z-1]->setNext(deck[j]);
    node * temp = deck[j]->next();
    deck[j]->setNext(deck[z]->next());
    deck[z]->setNext(temp);
    temp = deck[z];
    deck[z] = deck[j];
    deck[j] = temp;
}

int dataset::length() {
    return len;
}

std::string dataset::readLine(std::string line, std::vector<double> &dat, std::vector<std::string> &binates, int col){
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
            std::stringstream ss;
            ss << part;
            double dPart;
            ss >> dPart;
            dat.push_back(dPart);
        } else {
            binates.push_back(part);
        }
    }
    return identifier;
}

bool dataset::isDouble(const char* str){
    char* endptr = 0;
    std::strtod(str, &endptr);
    if(*endptr != '\0' || endptr == str)
        return false;
    return true;
}

void dataset::addToList(std::string* ident, std::vector<double>* tmpData, std::vector<std::string>* tmpBin){
    node * tmp = new node;
    tmp->setData(ident, tmpData, tmpBin);
    end->setNext(tmp);
    end = tmp;
}

void dataset::read(std::string filename, int column){
    std::ifstream myStream;
    myStream.open(filename.c_str());
    if(myStream.is_open()){
        std::string line;
        myStream >> line;
        std::vector<double>* tmpData = new std::vector<double>;
        std::vector<std::string>* tmpString = new std::vector<std::string>;
        std::string *ident = new std::string(readLine(line, *tmpData, *tmpString, column));
        head = new node;
        head->setData(ident, tmpData, tmpString);
        end = head;
        current = head;
        len = 0;
        while(!myStream.eof()) {
            len++;
            std::string line;
            myStream >> line;
            std::vector<double>* tmpData = new std::vector<double>;
            std::vector<std::string>* tmpString = new std::vector<std::string>;
            std::string ident = readLine(line, *tmpData, *tmpString, column);
            std::string* ide = new std::string(ident);
            addToList(ide, tmpData, tmpString);
        }
        node * temp = head;
        while (temp->next() != NULL){
            std::cout << temp->getIdent() << std::endl;
            temp = temp->next();
        }
        myStream.close();
    }

}
    
