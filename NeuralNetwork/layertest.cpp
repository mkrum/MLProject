//Luke Duane
//Layer test program
//Makes sure compute works. Should give me a vector 


#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>
#include "dataset.h"
#include "layer.h"
using namespace std;

int main(){
    cout << "LAYER TEST PROGRAM: SIMULATION OF THE FIRST STEP OF FEED FORWARD" << endl;
    vector<double> inputs;
    vector<double> outputs;
    inputs.push_back(.2);
    inputs.push_back(.4);
    inputs.push_back(.07);
    inputs.push_back(.88);
    Layer layer1(inputs);
    outputs=layer1.computeLayer();
    for(int i=0; i<outputs.size(); i++){
        cout << outputs[i] << endl;
    }

}

