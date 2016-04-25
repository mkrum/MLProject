#include "multiNomLogReg.h"

using namespace std;
using Eigen::MatrixXd;
using Eigen::RowVectorXd;

multiNomLogReg::multiNomLogReg(string d, int n): dat(d, n)
{
	m = dat.columns();
	k = dat.classes().size();
	betas = vector<MatrixXd>(k);
	trainer = vector<MatrixXd>(k);
	curr = 1;
	probsTmp = vector<double>(k);
	
	//Learn the fucking data
	dat.learn(std::bind(&multiNomLogReg::learnData, this, std::placeholders::_1), 1);
	
	//Create the fucking Matrices
	createMats();

	//Look at the fucking data
	checkMats();

	//Calculate the fucking betas
	calculateBetas();
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
		trainer.at(ref[n.getIdent()] -1) = MatrixXd(1,m+1);
		//Get explanatory variables and add 1 to the front
		vector<double> vect = n.dataVector();
		vect.insert(vect.begin(), 1);
		//Create a vector and add it to the matrix
		//VectorXd v(vect.data());
		RowVectorXd v = RowVectorXd::Map(vect.data(), vect.size());
		//addToMatrix(v.transpose(), trainer.at(ref[n.getIdent()] -1));
		cout << "Row vector to add: " << v << endl;
		//trainer.at(ref[n.getIdent()] -1).row(0) = v;
		//addToMatrix(v, trainer.at(ref[n.getIdent()] -1));
		trainerTmp.resize(trainerTmp.size() + 1);
		trainerTmp.at(ref[n.getIdent()] -1).push_back(v);
	}	
	else
	{
		//Make an entry into the trainer vector based on reference id
		vector<double> vect = n.dataVector();
		vect.insert(vect.begin(), 1);
		//VectorXd v(vect.data());
		RowVectorXd v = RowVectorXd::Map(vect.data(), vect.size());
		//addToMatrix(v.transpose(), trainer.at(ref[n.getIdent()] -1));
		int r = trainer.at(ref[n.getIdent()] -1).rows();
		trainer.at(ref[n.getIdent()] -1).resize(r+1, m+1);
		cout << "Row vector to add to row " << r << " : " << v << endl;
		//trainer.at(ref[n.getIdent()] -1).row(r) = v;
		//addToMatrix(v, trainer.at(ref[n.getIdent()] -1));
		trainerTmp.at(ref[n.getIdent()] -1).push_back(v);
	}
	
}
void multiNomLogReg::calculateBetas()
{
	for(int i = 0; i < k; i++)
	{
		MatrixXd a = trainer[i]; 						//renaming variable for readability
		MatrixXd y = MatrixXd::Constant(trainer[i].rows(), 1, i+1);
		//betas[i] = (a * a.transpose()).inverse() * a.transpose() * i; 		//(X'X)^-1 * X'i (Formula for beta vector)
		cout << "Beta Vector: " << endl << (a.transpose() * a).inverse() * a.transpose() * y << endl;
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
	for(int i = 0; i < k; i++)
	{
		//find identifier from reference map
		for(map<string, int>::iterator it = ref.begin(); it != ref.end(); it++)
		{
			if(it->second == i)
			{
				ident = it->first;
				break;
			}
		}
		
		cout << "Data Matrix for identifier: " << ident << endl << trainer[i] << endl;
	}
}
void multiNomLogReg::createMats()
{
	for(int i = 0; i < trainerTmp.size(); i++)
	{
		trainer.at(i) = MatrixXd(trainerTmp.at(i).size(), m + 1);
		for(int j = 0; j < trainerTmp.at(i).size(); j++)
		{
			trainer.at(i).row(j) = trainerTmp.at(i).at(j);
		}
	}
}
int multiNomLogReg::predict(node)
{
	vector<double> vect = n.dataVector();
	vect.insert(vect.begin(), 1);
	RowVectorXd v = RowVectorXd::Map(vect.data(), vect.size());
	double sum = 0;	
	
	for(int i = k; i > 0; i--)
	{
		sum = 0;
		if(i == k)
		{
			for(int j = 1; j < k; j++)
			{
				sum += exp(betas[j-1].dot(v));
			}
			probsTmp[i] = 1.0 / (1.0 + sum);
		}
		else
		{
			for(int j = 1; j < k; j++)
			{
				sum += exp(betas[j-1].dot(v));
			}
			probs[i] = exp(betas[i]
		}
	}
}






