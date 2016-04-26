//test.cpp file for the multinomial logistic regression algorithm
//Will Kudela

#include "multiNomLogReg.h"

int main()
{
	//Test Constructor
	multiNomLogReg mnlr("breastcancer.csv", 2);
	mnlr.exec();
	mnlr = multiNomLogReg("iris.csv", 5);
	mnlr.exec();
}
