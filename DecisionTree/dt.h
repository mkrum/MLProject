//Header for decision tree
//Marco Bruscia

#ifndef DT_H
#define DT_H
#include "dataset.h"
#include <string>
#include <iostream>
#include "Tree.h"
#include <map>
#include <algorithm>
#include <locale>
#include <vector>
#include <ctime>
using namespace std;

class dt {
    public:
        dt(string, int);
        ~dt();
        void createTree();
        Tree getTree(){return newTree;};
        string assignTreeProb(vector<double>, TreeNode<double> &, int);
        void setMapVal(vector<double>, TreeNode<double> &, int,string, int);
        vector <double> execute();
    private:
        dataset data;
        Tree newTree;
};

dt::dt(string s,int i):data(s,i){}

dt::~dt(){}

void dt::createTree()
{
	int i=0;
	int b = data.columns();
	TreeNode<double> chill = newTree.getFirst();
	if (b>5) b = 4;
	newTree.makeTree(b, chill,1);
	chill = newTree.getFirst();
	if (b>5) b = 4;
	while (b>0)
	{
		vector<double> stats;
		for(int j=0;j<data.tlength()*4;j++)
		{
			stats.push_back(data.get(j).getData(i));
		}
		double average, sum=0;
		for(int i=0;i<stats.size();i++)
		{	
			sum += stats[i];
		}
		average=sum/double(stats.size());
		newTree.setLevel(i+1,chill,average,1);
		b--;
		i+=1;
	}	
}

string dt::assignTreeProb(vector<double>vals, TreeNode<double> &a, int i) //test values by giving them the best guess available
{
	string s;
	if(vals[i] <= a.getData())
	{	
		if ( a.getLeftChild() != NULL)
		{
			s = assignTreeProb(vals,*a.getLeftChild(),i+1);
		}
		else
		{
			s = a.getMostPopularResult();
			return s;
		}
	}
	else
	{	
		if ( a.getRightChild() != NULL)
		{	
			s = assignTreeProb(vals,*a.getRightChild(),i+1);
		}
		else
		{
			s = a.getMostPopularResult();
			return s;
		}
	}
	return s;
}

void dt::setMapVal(vector<double> vals, TreeNode<double> &a, int i, string actual, int firstTime) //assign values to map at bottom nodes (set i to 0, vals equal all attributes for one node, and TreeNode to first)
{
	
	if(firstTime == 1) a = newTree.getFirst();
	map<string,double >::iterator it;
	if(vals[i] <= a.getData())
	{	
		if ( a.getLeftChild() != NULL)
			setMapVal(vals,*a.getLeftChild(),i+1,actual,0);
		else
		{
			map <string,double> disMap = a.getMap();
			it = disMap.find(actual);
			if(it != disMap.end()) //fill out map
			{
				disMap[actual]++;
			}
			else
			{
				disMap[actual]=1;
			}
			a.setMap(disMap);
		}
	}
	else
	{	
		if ( a.getRightChild() != NULL)
			setMapVal(vals,*a.getRightChild(),i+1,actual,0);
		else
		{	
			map <string,double> disMap = a.getMap();
			it = disMap.find(actual);
			if(it != disMap.end()) //fill out map
			{
				disMap[actual]++;
			}
			else
			{
				disMap[actual]=1;
			}
			a.setMap(disMap);
			
		}
	}
	if(firstTime == 1)
		newTree.setFirst(a);
}

vector<double> dt::execute()
{
	const clock_t begin_time = clock();
	vector <double> finalResults;
	int numCorrect = 0;
	double percentCorrect;
	string actual;
	createTree();
	TreeNode<double> root = getTree().getFirst();
	
	for(int i=0;i<data.tlength()*4;i++)
	{
		
		vector<double> vals;
		for(int j=0;j<data.columns();j++)
		{
			vals.push_back(data.get(i).getData(j));
		}
		actual = data.get(i).getIdent();
		setMapVal(vals,root,0,actual,1);
		
	}
	
	vector<string> testStats;
	int sizeOfTest = data.tlength();
	root = getTree().getFirst();
	for(int i=sizeOfTest*4;i<sizeOfTest*5-1;i++)
	{
		vector<double> stats;
		for(int j=0;j<data.columns();j++)
		{
			stats.push_back(data.get(i).getData(j));
		}
		testStats.push_back(assignTreeProb(stats, root,0));
		
	}
	for(int i=sizeOfTest*4;i<sizeOfTest*5-1;i++)
	{
		if(data.get(i).getIdent() == testStats[i-sizeOfTest*4])
			numCorrect++;
	
	}
	
	percentCorrect = numCorrect/double(data.tlength());
	double time = double(clock() - begin_time)/CLOCKS_PER_SEC;
	finalResults.push_back(percentCorrect);
	finalResults.push_back(time);
	return finalResults;
}

#endif
