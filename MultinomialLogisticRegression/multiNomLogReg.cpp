#include "multiNomLogReg.h"

using namespace std;
using Eigen::MatrixXd;
using Eigen::RowVectorXd;
using namespace Eigen;

multiNomLogReg::multiNomLogReg(string d, int n): dat(d, n)
{
	file = d;
	col = n;
}
double multiNomLogReg::exec()
{
	const clock_t begin_time = clock();
	double success = 0;
		dat = dataset(file, col);
		m = dat.columns();
		k = dat.classes().size();
		betas = vector<MatrixXd>(k);
		yData = vector<int>(0);
		trainerTmp = vector<RowVectorXd>(0);
		results = vector<int>(0);	

		curr = 1;
	
		//Learn the fucking data
		dat.learn(std::bind(&multiNomLogReg::learnData, this, std::placeholders::_1), 1);
	
		//Create the fucking Matrices
		createMats();

		//Look at the fucking data
		//checkMats();

		//Calculate the fucking betas
		calculateBetas();

		//Test the fucking betas
		dat.test(std::bind(&multiNomLogReg::predict, this, std::placeholders::_1));

		//Check the fucking results
		
		success = checkResults();
	cout << "Success rate on dataset " << file << ": " << success << "%" << endl;
	cout << "Time Ran: " << float( clock () - begin_time ) /  CLOCKS_PER_SEC << endl;
	return success;
}
/*
Takes data from nodes and places them into the trainer vector of class matrices
Also fills out the reference dictionary of string identifiers and their numerical values
I think this might work
*/
void multiNomLogReg::learnData(node n)
{
	//Check if identifier is in the reference
	if(ref.find(n.getIdent()) == ref.end())
	{
		//if it isn't then add it and give it a value
		ref[n.getIdent()] = curr++;
		vector<double> vect = n.dataVector();
		vect.insert(vect.begin(), 1);
		RowVectorXd v = RowVectorXd::Map(vect.data(), vect.size());
		//cout << "Vector to be added to trainerTmp: " << v << endl;
		trainerTmp.push_back(v);
		yData.push_back(ref[n.getIdent()]);
	}	
	else
	{
		//Make an entry into the trainer vector based on reference id
		vector<double> vect = n.dataVector();
		vect.insert(vect.begin(), 1);
		RowVectorXd v = RowVectorXd::Map(vect.data(), vect.size());
		//cout << "Vector to be added to trainerTmp: " << v << endl;
		trainerTmp.push_back(v);
		yData.push_back(ref[n.getIdent()]);
	}
	
}
void multiNomLogReg::splitMats()
{
	splitX = vector<vector<RowVectorXd>>(ref.size());
	splitY = vector<vector<int>>(ref.size());
	for(int i = 0; i < trainerTmp.size(); i++)
	{
		splitX.at(yData.at(i)-1).push_back(trainerTmp.at(i));
		splitY.at(yData.at(i)-1).push_back(yData.at(i));
	}
}
void multiNomLogReg::calculateBetas()
{
	for(int i = 0; i < k; i++)
	{
		MatrixXd a = trainer; 						//renaming variable for readability
		betas[i] = (a.transpose() * a).inverse() * a.transpose() * y; 		//(X'X)^-1 * X'i (Formula for beta vector)
		//cout << "Beta Vector: " << endl << betas[i] << endl;
		//betas[i] = a.jacobiSvd(ComputeThinU | ComputeThinV).solve(y); 		//(X'X)^-1 * X'i (Formula for beta vector)
	


	}
}
void multiNomLogReg::calculateSplitBetas()
{
	for(int i = 0; i < ref.size(); i++)
	{
		MatrixXd a = returnTrainer.at(i);
		MatrixXd yNew = MatrixXd::Constant(returnY.at(i).rows(), 1, i+1 + 0.1);
		betas[i] = MatrixXd(m+1, 1);
		betas[i] = (a.transpose() * a).inverse() * a.transpose() * yNew;
		//cout << "Beta Vector: " << endl << betas[i] << endl;
	}
}
void multiNomLogReg::addToMatrix(RowVectorXd v, MatrixXd & m)
{
	MatrixXd B(m.rows() + 1, m.cols());
	B << 	m,
		v;
	m = B;
}
void multiNomLogReg::checkMats()
{
	string ident;
	cout << "X matrix (" << trainer.rows() << " X " << trainer.cols() << "): " << endl << trainer << endl;
	cout << "Y matrix (" << y.rows() << " X " << y.cols() << "): " << endl << y << endl;
}
void multiNomLogReg::checkReturns()
{
	for(int i = 0; i < ref.size(); i++)
	{
		cout << "X matrix: " << returnTrainer.at(i) << endl;
		cout << "Y matrix: " << returnY.at(i) << endl;
	}
}
void multiNomLogReg::createMats()
{
	trainer = MatrixXd(trainerTmp.size(), m + 1);
	for(int i = 0; i < trainerTmp.size(); i++)
	{
		trainer.row(i) = trainerTmp.at(i);
	}
	vector<double> modYData(yData.begin(), yData.end());
	y = VectorXd::Map(modYData.data(), modYData.size());
}
void multiNomLogReg::createReturns()
{
	returnTrainer = vector<MatrixXd>(splitX.size());
	returnY = vector<MatrixXd>(splitX.size());
	cout << splitX.size() << endl;
	for(int i = 0; i < ref.size(); i++)
	{
		returnTrainer.at(i) = MatrixXd(splitX.at(i).size(), m + 1);
		returnY.at(i) = MatrixXd(splitY.at(i).size(), 1);
		for(int j = 0; j < splitX.at(i).size(); j++)
		{
			returnTrainer.at(i).row(j) = splitX.at(i).at(j);
			returnY.at(i)(j,0) = (double) splitY.at(i).at(j);
		}
	}
}
int multiNomLogReg::predict(node n)
{
	vector<double> vect = n.dataVector();
	vect.insert(vect.begin(), 1);
	RowVectorXd v = RowVectorXd::Map(vect.data(), vect.size());
	int pred = 1;
	/*double max = 0;
	for(int l = 0; l < probsTmp.size(); l++)
	{
		if(probsTmp[l] > max)
		{
			max = probsTmp[l];
			pred = l+1;
		}
	}*/
	double d = betas[0].transpose().row(0).dot(v);
	//cout << "Dot Product is: " << d << endl;
	for(int i = 1; i <= ref.size(); i++)
	{
		if(abs(d - i) < 0.5 )
			pred = i;
	}
	string ident;
	for(map<string, int>::iterator it = ref.begin(); it != ref.end(); it++)
	{
		if(it->second == pred)
		{
			ident = it->first;
			break;
		}
	}
	if(ident == n.getIdent())
	{
		//cout << "Correct" << endl;
		results.push_back(1);
	}
	else
	{
		//cout << "Incorrect, guessed " << ident << ", but correct anser was " << n.getIdent() << endl;
		results.push_back(0);
	}
}
double multiNomLogReg::checkResults()
{
	double sum = 0;
	for(int i = 0; i < results.size(); i++)
	{
		sum += results.at(i);
	}
	//cout << "Algorithm Veracity: " << sum / results.size() * 100 << "%" << endl;
	return sum / results.size() * 100;
}





