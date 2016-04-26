//test program for the mln

#include "mln.h"
#include <utility>
using namespace std;
int main() {
    mln net2 = mln("../datasets/iris.csv", 5);
    net2.tweaking();
}

