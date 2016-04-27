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
vector<double> multiNomLogReg::exec()
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
	
		//Learn the data
		dat.learn(std::bind(&multiNomLogReg::learnData, this, std::placeholders::_1), 1);
	
		//Create the data matrices
		createMats();

		//Calculate the betas
		calculateBetas();

		//Test the betas
		dat.test(std::bind(&multiNomLogReg::predict, this, std::placeholders::_1));

		//Check the fucking results
		
	vector<double> successVector(2);
	successVector.at(0) = checkResults();
	successVector.at(1) = float( clock () - begin_time ) /  CLOCKS_PER_SEC;
	return successVector;
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
		trainerTmp.push_back(v);
		yData.push_back(ref[n.getIdent()]);
	}	
	else
	{
		//Make an entry into the trainer vector based on reference id
		vector<double> vect = n.dataVector();
		vect.insert(vect.begin(), 1);
		RowVectorXd v = RowVectorXd::Map(vect.data(), vect.size());
		trainerTmp.push_back(v);
		yData.push_back(ref[n.getIdent()]);
	}
	
}
void multiNomLogReg::calculateBetas()
{
	for(int i = 0; i < k; i++)
	{
		MatrixXd a = trainer; 							//renaming variable for readability
		betas[i] = (a.transpose() * a).inverse() * a.transpose() * y; 		//(X'X)^-1 * X'i (Formula for beta vector)
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
int multiNomLogReg::predict(node n)
{
	vector<double> vect = n.dataVector();
	vect.insert(vect.begin(), 1);
	RowVectorXd v = RowVectorXd::Map(vect.data(), vect.size());
	int pred = 1;
	double d = betas[0].transpose().row(0).dot(v);
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
		results.push_back(1);
	}
	else
	{
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
	return sum / results.size();
}





