//Class to execute Multinomial Logistic Regression on a dataset
//Will Kudela

#include "dataset.h"
#include "node.h"
#include <iostream>
#include <string>
#include "Eigen/Dense"
#include <map>
#include <cmath>

using namespace std;
using Eigen::MatrixXd;
using Eigen::RowVectorXd;

class multiNomLogReg
{
	public:
		multiNomLogReg(string, int);
		void test();	
	private:
		void learnData(node);
		void addToMatrix(RowVectorXd, MatrixXd &);
		void calculateBetas();
		void createMats();
		void checkMats();
		int predict(node);
		dataset dat;
		int m; //number of explanatory variables
		int k; //number of categories
		int curr; //current key
		vector<MatrixXd> betas; //collection of k m by 1 matrices of weights for explanatory variables
		vector<vector<RowVectorXd>> trainerTmp;
		vector<MatrixXd> trainer; //training data w/ indexes denoting classification number and matrices filled with explanatory variables
		map<string, int> ref; //maps class identifier string to a number
		vector<double> probsTmp;
};
