1)createp dt object
2)split dataset (maybe put this in constructor?)
3)call createTree()
4)for each node in the dataset, run it through setMapVal
5)test remaining nodes on assignTreeProb
6)check to see if node was correct
7)print out percent correct

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
	dt("iris.csv",5) dtree;
	dtree.split();
	dtree.createTree();
	for(int i=0;i<dtree.getData().tlength();i++)
	{
		vector<double> vals;
		for(int j=0;j<dtree.getData().columns();j++)
		{
			if(j != dTree.getIndexOfLearn())
				vals.push_back(getData().get(i).getData(j)
		}
		setMapVal(vals,dtree.getTree().getFirst(),0);
	}
	vector<double> testStats;
	for(int i=0;i<dtree.getData().tlength();i++)
		testStats.push_back()(assignTreeProb())//fill dis here
	
	
}
