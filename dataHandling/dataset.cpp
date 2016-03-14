//Implementation for the dataset class
//Michael Krumdick
#include "dataset.h"
#include <iostream>
dataset::dataset(std::string file, int col) {
    std::cout << "here" << std::endl;
    readCsv reader(file);
    head = *reader.read(col);
    node * tmp = &head;
    while(head.next() != NULL){
        std::cout << tmp->getIdent() << std::endl;
        tmp = tmp->next();
    }
    current = head;
    len = reader.getLength();
}

node dataset::get(int index){
    node ret = head;
    int i = 0;
    while(i < index && ret.next() != NULL){
        i++;
        ret = *ret.next();
    }
    return ret;
}

node dataset::iget(){
    if(current.next() != NULL){
        node tmp;
        tmp = current;
        current = *current.next();
        return tmp;
    } else {
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
    node tmp = head;
    for(int i = 0; i < len; i++){
        deck[i] = &tmp;
        tmp = *tmp.next();
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
        

