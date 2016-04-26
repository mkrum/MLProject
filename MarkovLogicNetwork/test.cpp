//test program for the mln

#include "mln.h"
#include <utility>
using namespace std;
int main() {
    mln net = mln("credit.csv", 16);
    vector<double> test = net.execute();
    cout << "time: " << test[0] << " rate: " << test[1] << endl;
}

