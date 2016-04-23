//Luke Duane 
//test file


#include <iostream>
#include <vector>
#include <cstdlib>
#include "neuron.h"
using namespace std;

int main(){
    Neuron a;
    for(int i=0; i<5; i++){
        cout << a.getRandomWeight() << endl;
    }
}
