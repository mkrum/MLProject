//test program for the mln

#include "mln.h"
#include <utility>
using namespace std;
int main() {
    mln net2 = mln("../datasets/breastcancer.csv", 2);
    net2.tweaking();
}

