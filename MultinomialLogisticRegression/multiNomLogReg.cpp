#include "multiNomLogReg.h"

using namespace std;
using Eigen::MatrixXd;
using Eigen::VectorXd;

multiNomLogReg::multiNomLogReg(string d)
{
	dat = dataset(d, 8) //need to figure out column specifically
	m = d.columns();
	k = d.classes().size();
	betas = vector<MatrixXd>(k);
	trainer = vector<MatrixXd>(k);
	curr = 0;
}
void multiNomLogReg::learnData(node n)
{
	//Check if identifier is in the reference
	if(ref.find(n.getIdent()) == ref.end())
	{
		//if it isn't then add it and give it a value
		ref[n.getIdent()] = curr++;
		trainer.at([ref[n.getIdent()]]) = new MatrixXd(1,m+1)
		//Get explanatory variables and add 1 to the front
		vector<double> vect = *n.dataVector();
		vect.insert(vect.begin(), 1);
		//Create a vector and add it to the matrix
		VectorXd v(vect.data());
		trainer.at(ref[n.getIdent()]) << v;
	}	
	else
	{
		//Make an entry into the trainer vector based on reference id
		vector<double vect = *n.dataVector();
		vect.insert(vect.begin(), 1);
		VectorXd v(vect.data());
		addToMatrix(v, trainer.at(ref[n.getIdent()]));
	}
	
}
void multiNomLogReg::addToMatrix(VectorXd v, MatrixXd & m)
{
	MatrixXd B(m.rows() + 1, m.cols());
	B << 	m,
		v;
	m = B;
}
