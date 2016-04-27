

//Marco Bruscia

#include "dt.h"
#include "Tree.h"
#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <locale>
using namespace std;

int main()
{
	cout << "tryna fam?" << endl;
	
	int numCorrect = 0;
	double percentCorrect;
	string actual;
	dt dtree("breastcancer.csv",2);
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
		dtree.setMapVal(vals,root,0,actual,1);
		
	}
	map <string,double> yeboy = dtree.getTree().getFirst().getLeftChild()->getRightChild()->getLeftChild()->getMap();
	
	map <string,double>::iterator it = yeboy.begin();
	//if(it != yeboy.end())
	//	cout << it->first << " " << it->second << endl;
	cout << "ya boy" << endl;
	
	vector<string> testStats;
	int sizeOfTest = dtree.getData().tlength();
	root = dtree.getTree().getFirst();
	for(int i=sizeOfTest*4;i<sizeOfTest*5;i++)
	{
		vector<double> stats;
		for(int j=0;j<dtree.getData().columns();j++)
		{
			//if(j != dtree.getIndexOfLearn())
			stats.push_back(dtree.getData().get(i).getData(j));
		}
		cout << dtree.assignTreeProb(stats,root,0) << endl;
		testStats.push_back(dtree.assignTreeProb(stats, root,0));
		
	}
	cout << "dildo" << endl;
	for(int i=sizeOfTest*4;i<sizeOfTest*5;i++)
	{
		if(dtree.getData().get(i).getIdent() == testStats[i-sizeOfTest*4])
			numCorrect++;
	
	}
	
	percentCorrect = numCorrect/double(dtree.getData().tlength());
	cout << percentCorrect << endl;
	
	return 0;
	
}

