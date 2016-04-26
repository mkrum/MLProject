//test program for the mln

#include "mln.h"
#include <utility>
using namespace std;
int main() {
 //  mln("letterrec.csv", 1);
    mln net = mln("credit.csv", 16);
    map<string, vector<double>> test;
    test = net.execute();
    for(auto elem : test){  
        cout << "time: " << elem.first << " rate: " << elem.second[0];
    }
}

