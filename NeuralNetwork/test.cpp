//Luke Duane 
//test file


#include <iostream>
#include <vector>
#include <cstdlib>
#include "neuron.h"
using namespace std;

int main(){
    int cols=5;
    vector<double> temp;
    temp.push_back(.75);
    temp.push_back(.37);
    temp.push_back(.29);
    temp.push_back(0.2);
    temp.push_back(3);
    Neuron a(temp, 3);
}







