//test program for the mln

#include "mln.h"

int main() {
 //   mln net = mln("breastcancer.csv", 2);
    mln net = mln("iris.csv", 5);
    net.learn();
    net.test();
}

