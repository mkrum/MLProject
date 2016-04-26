//implementation for dt
//Marco Bruscia

#include "dt.h"
#include "Tree.h"
#include "TreeNode.h"
#include <string>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

dt::dt(string s,int i):data(s,i)
{
	indexOfLearn = i;
}

void dt::createTree()
{
	int i=0;
	int b = getData().columns();
	int count = 1,index = 0;
	//Tree("newTree") newTree;
	
	while (b>0)
	{
		vector<double> stats;
		for(int j=0;j<getData().tlength();j++)
		{
			stats.push_back(getData().get(j).getData(i));
		}
		
		for(int k=0;k<count;k++)
		{
			getTree().buildNode(stats);
		}
		b--;
		count=count*2;
		if (i+1 == getIndexOfLearn()) i+=2;
		else i+=1;
	}
}

string dt::assignTreeProb(vector<double>vals, TreeNode<double> &a, int i) //test values by giving them the best guess available
{
	if(vals[i] <= a.getData())
	{	
		if ( a.getLeftChild() != NULL)
			assignTreeProb(vals,*a.getLeftChild(),i+1);
		else
			return a.getMostPopularResult();
	}
	else
	{	
		if ( a.getRightChild() != NULL)
			assignTreeProb(vals,*a.getRightChild(),i+1);
		else
			return a.getMostPopularResult();
	}
}

void dt::setMapVal(vector<double> vals, TreeNode<double> &a, int i, string actual) //assign values to map at bottom nodes (set i to 0, vals equal all attributes for one node, and TreeNode to first)
{
	
	if(vals[i] <= a.getData())
	{	
		if ( a.getLeftChild() != NULL)
			setMapVal(vals,*a.getLeftChild(),i+1,actual);
		else
			a.getMap()[actual]++;
	}
	else
	{	
		if ( a.getRightChild() != NULL)
			setMapVal(vals,*a.getRightChild(),i+1,actual);
		else
			a.getMap()[actual]++;
	}
}


