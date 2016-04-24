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
    temp.push_back(5.1);
    temp.push_back(3.5);
    temp.push_back(1.4);
    temp.push_back(0.2);

    Neuron a(temp);
    cout << a.sigmoid(3) << endl;
}
