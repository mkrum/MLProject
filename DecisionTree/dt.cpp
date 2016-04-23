//implementation for dt
//Marco Bruscia

#include "dt.h"
#include "Tree.h"
#include <string>
#include <iostream>
using namespace std;

dt::dt(string,int):data(string s, int i){}

void dt::createTree()
{
	int i=getNumAttributes();
	int b = getData().columns()
	int count = 1,index = 0;
	Tree("newTree") newTree;
	
	while (b>0)
	{
		vector<double> stats;
		for(int j=0;j<data.tlength();j++)
		{
			stats.push_back(getData().get(j).getData(i));
		}
		
		for(int k=0;k<count;k++)
		{
			newTree.buildNode(stats);
		}
		b--;
		count=count*2;
		if (i+1 == getIndexOfLearn() i+=2;
		else i+=1;
	}
}
/*
void assignTreeProb()
{

}*/
