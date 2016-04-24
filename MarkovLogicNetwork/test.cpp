//test program for the mln

#include "mln.h"
#include <utility>
using namespace std;
int main() {
 //  mln("letterrec.csv", 1);
    mln net = mln("credit.csv", 16);
    pair<double, double> test;
    test = net.execute();
    cout << "time: " << test.first << " rate: " << test.second;
}

