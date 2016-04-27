//test program for the mln

#include "mln.h"
#include <utility>
using namespace std;
int main() {
    mln net2 = mln("../datasets/credit.csv", 16);
    net2.tweaking();
}

