//Class to execute Multinomial Logistic Regression on a dataset
//Will Kudela

#include "dataset.h"
#include <iostream>
#include <string>
#include "Eigen/Dense"
#include <map>

using namespace std;
using Eigen::MatrixXd;
using Eigen::VectorXd;

class multiNomLogReg
{
	public:
		multiNomLogReg(string, int);
		void test();	
	private:
		void learnData(node);
		void addToMatrix(VectorXd, MatrixXd &);
		void calculateBetas();
		void checkMats();
		dataset dat;
		int m; //number of explanatory variables
		int k; //number of categories
		int curr; //current key
		vector<MatrixXd> betas; //collection of k m by 1 matrices of weights for explanatory variables
		vector<MatrixXd> trainer; //training data w/ indexes denoting classification number and matrices filled with explanatory variables
		map<string, int> ref; //maps class identifier string to a number
};
