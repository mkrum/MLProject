//Class to execute Multinomial Logistic Regression on a dataset
//Will Kudela

#include "dataset.h"
#include <iostream>
#include <string>
#include <Eigen/Dense>

using namespace std;
using Eigen::MatrixXd;

class multiNomLogReg
{
	public:
		
	private:
		int m; //number of explanatory variables
		int k; //number of categories
		MatrixXd beta; //m by k matrix of weights for explanatory variables
		vector<MatrixXd> trainer; //training data w/ indexes denoting classification number and matrices filled with explanatory variables 
};
