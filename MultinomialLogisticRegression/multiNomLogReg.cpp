#include "multiNomLogReg.h"

using namespace std;
using Eigen::MatrixXd;
using Eigen::VectorXd;

multiNomLogReg::multiNomLogReg(string d, int n): dat(d, n)
{
	//dataset data(d, 5); //need to figure out column specifically
	//dat = data;
	m = dat.columns();
	k = dat.classes().size();
	betas = vector<MatrixXd>(k);
	trainer = vector<MatrixXd>(k);
	curr = 0;
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
		trainer.at(ref[n.getIdent()]) = new MatrixXd(1,m+1)
		//Get explanatory variables and add 1 to the front
		vector<double> vect = *n.dataVector();
		vect.insert(vect.begin(), 1);
		//Create a vector and add it to the matrix
		VectorXd v(vect.data());
		addToMatrix(v, trainer.at(ref[n.getIdent()]));
	}	
	else
	{
		//Make an entry into the trainer vector based on reference id
		vector<double> vect = *n.dataVector();
		vect.insert(vect.begin(), 1);
		VectorXd v(vect.data());
		addToMatrix(v, trainer.at(ref[n.getIdent()]));
	}
	
}
void multiNomLogReg::calculateBetas()
{
	for(int i = 0; i < k; i++)
	{
		MatrixXd a = trainer[i]; 						//renaming variable for readability
		betas[i] = (a * a.transpose()).inverse() * a.transpose() * i; 		//(X'X)^-1 * X'i (Formula for beta vector)
	}
}
void multiNomLogReg::addToMatrix(VectorXd v, MatrixXd & m)
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
