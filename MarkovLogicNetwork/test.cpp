//test program for the mln

#include "mln.h"

int main() {
//    mln net = mln("breastcancer.csv", 2);
    net.learn();
    net.test();
}

