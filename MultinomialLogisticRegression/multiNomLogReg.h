//Class to execute Multinomial Logistic Regression on a dataset
//Will Kudela

#include "dataset.h"
#include "node.h"
#include <iostream>
#include <string>
#include "Eigen/Dense"
#include <map>
#include <cmath>
#include <ctime>

using namespace std;
using Eigen::MatrixXd;
using Eigen::RowVectorXd;
using namespace Eigen;

class multiNomLogReg
{
	public:
		multiNomLogReg(string, int);
		vector<double> exec();	
	private:
		void learnData(node);
		void addToMatrix(RowVectorXd, MatrixXd &);
		void calculateBetas();
		void calculateSplitBetas();
		void splitMats();
		void createReturns();
		void createMats();
		void checkReturns();
		void checkMats();
		int predict(node);
		double checkResults();
		dataset dat;
		string file;
		int col;
		int m; //number of explanatory variables
		int k; //number of categories
		int curr; //current key
		vector<MatrixXd> betas; //collection of k m by 1 matrices of weights for explanatory variables
		vector<RowVectorXd> trainerTmp;															//M O D I F I E D ! ! ! !
		vector<vector<RowVectorXd>> splitX;		
		vector<int> yData;
		vector<vector<int>> splitY;
		VectorXd y;																	//New variable
		MatrixXd trainer; //training data w/ indexes denoting classification number and matrices filled with explanatory variables			//Now just one matrix
		map<string, int> ref; //maps class identifier string to a number
		vector<double> probsTmp;
		vector<int> results;
		vector<MatrixXd> returnTrainer;
		vector<MatrixXd> returnY;
};
