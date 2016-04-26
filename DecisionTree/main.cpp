

//Marco Bruscia

#include "dt.h"
#include "Tree.h"
#include <string>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main()
{
	cout << "tryna fam?" << endl;
	
	int numCorrect = 0, percentCorrect;
	string actual;
	dt dtree("iris.csv",5);
	cout << dtree.getData().tlength() << endl;
	dtree.createTree();
	cout << "where even" << endl;
	TreeNode<double> root = dtree.getTree().getFirst();
	
	for(int i=0;i<dtree.getData().tlength()*4;i++)
	{
		
		vector<double> vals;
		for(int j=0;j<dtree.getData().columns();j++)
		{
			vals.push_back(dtree.getData().get(i).getData(j));
			//cout << dtree.getData().get(i).getData(j) << endl;
		}
		actual = dtree.getData().get(i).getIdent();
		cout << "wat" << endl;
		dtree.setMapVal(vals,root,0,actual,1);
		cout << "oh" << endl;
		
	}
	//map <string,double>::iterator it = dtree.getTree().getFirst().getRightChild()->getRightChild()->getLeftChild()->getMap().begin();
	cout << dtree.getTree().getFirst().getRightChild()->getRightChild()->getLeftChild()->getData() << endl;
	//cout << it->first << " " << it->second << endl;
	//cout << dtree.getTree().getFirst().getLeftChild()->getRightChild()->getLeftChild().getMap()
	cout << "ya boy" << endl;
	/*
	vector<string> testStats;
	int sizeOfTest = dtree.getData().tlength();
	
	for(int i=sizeOfTest*4;i<sizeOfTest*5;i++)
	{
		vector<double> stats;
		for(int j=0;j<dtree.getData().columns();j++)
		{
			//if(j != dtree.getIndexOfLearn())
			stats.push_back(dtree.getData().get(i).getData(j));
		}
		
		//testStats.push_back(dtree.assignTreeProb(stats, root,0));
		cout << dtree.assignTreeProb(stats,root,0);
	}
	
	for(int i=sizeOfTest*4;i<sizeOfTest*5;i++)
	{
		if(dtree.getData().get(i).getIdent() == testStats[i])
			numCorrect++;
	
	}
	
	percentCorrect = numCorrect/double(dtree.getData().tlength());
	cout << percentCorrect << endl;
	
	return 0;
	*/
}

