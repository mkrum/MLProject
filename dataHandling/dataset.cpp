//Implementation for the dataset class
//Michael Krumdick
#include "dataset.h"

dataset::dataset(std::string file, int col) {
    readCsv reader(file);
    head = reader.read(col);
    length = reader.getLength();
}

node dataset::get(int index){
    node * ret = head;
    int i = 0;
    while(i < index && ret->next() != NULL){
        ret = ret->next();
    }
    return *ret;
}

node dataset::iget(){
    if(current->next() != NULL){
        node * tmp = current;
        current = current->next();
        return *current;
    } else {
        return NULL;
    }
}

void dataset::reset() {
    current = head;
}
//inspired by a similar function that I used for my CSinglePerceptron project
//(https://github.com/mkrum/CSinglePerceptron.git)
//Fisher-Yates Shuffle
void dataset::shuffle(){
    node * deck[length];
    node * tmp = head;
    for(int i = 0; i < length; i++){
        deck[i] = tmp;
        tmp = tmp->next;
    }
    for(int j = length - 1; j > 1; j--){
        int z = fyrand(j + 1);
        swap(deck[j - 1], deck[j], deck[z - 1], deck[z]);
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

void dataset::swap(node * preval1, node * val1, node * preval2, node * val2) {
    preval1->setNext(val2);
    preval2->setNext(val1);
    node * temp = val1->next();
    val1->setNext(val2->next());
    val2->setNext(temp);
}


        

