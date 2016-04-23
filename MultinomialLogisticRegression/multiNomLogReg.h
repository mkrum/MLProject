//Class to execute Multinomial Logistic Regression on a dataset
//Will Kudela

#include "dataset.h"
#include <iostream>
#include <string>
#include <armadillo>

using namespace arma;
using namespace std;

class multiNomLogReg
{
	public:
		
	private:
		int m; //number of explanatory variables
		int k; //number of categories
		mat beta; //m by k matrix of weights for explanatory variables
		vector<mat> trainer; //training data w/ indexes denoting classification number and matrices filled with explanatory variables 
};
