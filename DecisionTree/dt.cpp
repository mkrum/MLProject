//implementation for dt
//Marco Bruscia

#include "dt.h"
#include "Tree.h"
#include <string>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

dt::dt(string,int):data(string s, int i)
{
	indexOfLearn = i;
}

void dt::createTree()
{
	int i=0;
	int b = getData().columns()-1;
	int count = 1,index = 0;
	//Tree("newTree") newTree;
	
	while (b>0)
	{
		vector<double> stats;
		for(int j=0;j<getData.tlength();j++)
		{
			stats.push_back(getData().get(j).getData(i));
		}
		
		for(int k=0;k<count;k++)
		{
			getTree().buildNode(stats);
			if (b==1)
			{
				setVector();
			}
		}
		b--;
		count=count*2;
		if (i+1 == getIndexOfLearn()) i+=2;
		else i+=1;
	}
}

double assignTreeProb(vector<double>vals, TreeNode a, int i) //test values by giving them the best guess available
{
	if(vals[i] <= a.getData())
	{	
		if (a.getLeftChild() != NULL)
			getValFromTree(vals,a.getLeftChild(),i+1);
		else
			return a.getMostPopularResult();
	}
	else
	{	
		if (a.getRightChild() != NULL)
			getValFromTRee(vals,a.getRightChild(),i+1);
		else
			return a.getMostPopularResult();
	}
}

void dt::setMapVal(vector<double> vals, TreeNode a, int i, double actual) //assign values to map at bottom nodes (set i to 0, vals equal all attributes for one node, and TreeNode to first)
{
	
	if(vals[i] <= a.getData())
	{	
		if (a.getLeftChild() != NULL)
			setMap(vals,a.getLeftChild(),i+1);
		else
			a.getMap()[actual]++;
	}
	else
	{	
		if (a.getRightChild() != NULL)
			setMap(vals,a.getRightChild(),i+1);
		else
			a.getMap()[actual]++;
	}
}


