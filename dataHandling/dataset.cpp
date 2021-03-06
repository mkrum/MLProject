//Implementation for the dataset class
//Michael Krumdick
#include "dataset.h"
#include <iostream>

//instanties a dataset from the csv file, col should be the column you want to predict
dataset::dataset(std::string file, int col) {
    percentage = .8;   //default percentage is 80
    read(file, col);
    normalize();
    shuffle();
    shuffle();
    reset();
}
//simple function that will get the node at a certain index i
node dataset::get(int index){
    node* ret = head;
    int i = 0;
    while(i < index && ret->next() != NULL){
        i++;
        ret = ret->next();
    }
    return *ret;
}
//"Iterative get" function, use this when you are getting elements one after another
node dataset::iget(){
    if(current != testHead){
        node* tmp = current;
        current = current->next();
        return *tmp;
    } else{
        return *current;
    }
}
//the test get function
node dataset::tget(){
   if(testCurrent->next() != NULL){
        node* tmp = current;
        current = current->next();
        return *tmp;
    } else{
        return *testCurrent;
    }
}
//resets the current node to the head
void dataset::reset() {
    current = head;
//    shuffle();
    split();
}
//Fisher-Yates Shuffle
//randomizes the data
void dataset::shuffle(){
    srand(time(NULL));
    current = head;
    node * deck[len];
    node * tmp = head;
    for(int i = 0; i < len; i++){
        deck[i] = tmp;
        tmp = tmp->next();
    }
    for(int j = len - 1; j > 0; j--){
        int z = rand() % j + 1;
        swap(j, z, deck);
    }
}


//swap two elements in the list
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
//return the length
int dataset::length() {
    return num;
}
//return the length of the test set
int dataset::tlength() {
    return len - num;
}
//read a single line from the csv document and create a node
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
            identifiers.insert(part);
            continue;
        }
        if(isDouble(part.c_str())){
            std::stringstream ss;
            ss << part;
            double dPart;
            ss >> dPart;
            dat.push_back(dPart);
        } else {
            addToStrings(part);
            binates.push_back(part);
        }
    }
    addToExtrema(dat);
    return identifier;
}
//checks if a string is in the double form
bool dataset::isDouble(const char* str){
    char* lastptr = 0;
    std::strtod(str, &lastptr);
    if(*lastptr != '\0' || lastptr == str)
        return false;
    return true;
}
//adds object to linked list
void dataset::addToList(std::string* ident, std::vector<double>* tmpData, std::vector<std::string>* tmpBin){
    node * tmp = new node;
    tmp->setData(ident, tmpData, tmpBin);
    last->setNext(tmp);
    last = tmp;
}
//the csv reader, creates the linked list
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
        last = head;
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
        myStream.close();
    }

}

void dataset::addToStrings(std::string inStr) {
    if (std::find(uniqueStrings.begin(), uniqueStrings.end(), inStr) == uniqueStrings.end()){
        uniqueStrings.push_back(inStr);
     }
}

void dataset::addToExtrema(std::vector<double> inData){
    if (maximum.size() == 0){
        for(int z = 0; z < inData.size(); z++){
            maximum.push_back(inData[z]);
            minimum.push_back(inData[z]);
        }
    } else {
        for(int z = 0; z < inData.size(); z++){
            if(inData[z] > maximum[z]){
                maximum[z] = inData[z];
            } else if (inData[z] < minimum[z]){
                minimum[z] = inData[z];
            }
        }
    }
}

void dataset::normalize() {
    std::map<std::string, double> convert;
    for(int i = 0; i < uniqueStrings.size(); i++){
        convert[uniqueStrings[i]] = i/(uniqueStrings.size() - 1.0);
    }
    node * temp = head;
    while(temp->next() != NULL){
        std::vector<std::string> bin = temp->binatesVector();
        for(int j = 0; j < bin.size(); j++){
            temp->addToData(convert[bin[j]]);
        }
        for(int z = 0; z < maximum.size(); z++){
            (*temp)[z] = ((*temp)[z] - minimum[z])/(maximum[z] - minimum[z]);
        }
        temp = temp->next();
    }
}

void dataset::split(){
    num = len * percentage;
    node *temp = head;
    for(int i = 0; i < num - 1; i++){
        temp = temp->next();
    }
    learnEnd = temp;
    testHead = temp->next();
    testCurrent = testHead;
}

void dataset::setPercent(double perc){
    percentage = perc;
}

iterator dataset::end() {
    return learnEnd;
}

iterator dataset::begin() {
    return head;
}

iterator dataset::tend() {
    return last;
}

iterator dataset::tbegin() {
    return testHead;
}

void dataset::learn(std::function<void (node)> learn, int tests){
    for(int i = 0; i < tests; i++){
        std::for_each(begin(), end(), learn);
        reset();
    }
}

void dataset::learn(std::function<void (node)> learn){
   std::for_each(begin(), end(), learn);
   reset();
}


void dataset::test(std::function<void (node)> test){
        std::for_each(tbegin(), tend(), test);
        reset();
}


void dataset::learn(std::function<void (node)> learn, std::function<void ()> endFunc, int tests){
    for(int i = 0; i < tests; i++){
        std::for_each(begin(), tend(), learn);
        reset();
        endFunc();
    }
}
std::vector<std::string> dataset::classes(){
    std::vector<std::string> out (identifiers.begin(), identifiers.end());
    return out;
}

int dataset::columns(){
    return head->size();
}

