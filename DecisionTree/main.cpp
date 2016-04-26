#ifndef MAIN_H_
#define MAIN_H_

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
	for(int i=0;i<dtree.getData().tlength();i++)
	{
		vector<double> vals;
		for(int j=0;j<dtree.getData().columns();j++)
		{
			if(j != dtree.getIndexOfLearn())
				vals.push_back(dtree.getData().get(i).getData(j));
		}
		actual = dtree.getData().get(i).getData(5);
		actual = "tuddy";
		dtree.setMapVal(vals,dtree.getTree().getFirst(),0,actual);
	}

	/*	
	vector<double> testStats;
	for(int i=0;i<dtree.getData().tlength();i++)
	{
		vector<double> stats;
		for(int j=0;j<dtree.getData().columns();j++)
		{
			if(j != dtree.getIndexOfLearn())
				stats.push_back(getData().get(i).getData(j)
		}
		testStats.push_back(assignTreeProb(stats, dtree.getTree().getFirst(),0))
	}
	for(int i=0;i<dtree.getData().tlength();i++)
	{
		if(getData().get(i).getData(dtree.getIndexOfLearn()) == testStats[i])
			numCorrect++;
	
	}
	
	percentCorrect = numCorrect/double(dtree.getData().tlength());
	cout << percentCorrect << endl;
	*/
	return 0;
}
#endif
