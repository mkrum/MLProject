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
using namespace std;

class dt {
    public:
        dt(string, int);
        ~dt();
        int getPrediction();
        double getOdds();
        int getHighestAttribute();
        void createTree();
        void traverseTree();
        dataset getData(){return data;};
        int getIndexOfLearn(){return indexOfLearn;};
        Tree getTree(){return newTree;};
        string assignTreeProb(vector<double>, TreeNode<double> &, int);
        void setMapVal(vector<double>, TreeNode<double> &, int,string, int);
    private:
        dataset data;
        Tree newTree;
        int pred;
        int numAttributes;
        double predOdds;
        int indexOfLearn;
};

dt::dt(string s,int i):data(s,i)
{
	indexOfLearn = i;
}

dt::~dt(){}

void dt::createTree()
{
	int i=0;
	int b = getData().columns();
	TreeNode<double> chill = newTree.getFirst();
	cout << "num columns: " << b << endl;
	if (b>5) b = 4;
	newTree.makeTree(b, chill,1);
	chill = newTree.getFirst();
	cout << "i'm here" << endl;
	cout << newTree.getFirst().getData() << endl;
	cout << newTree.getFirst().getLeftChild()->getData() << endl;
	if (b>5) b = 4;
	while (b>0)
	{
		vector<double> stats;
		for(int j=0;j<getData().tlength()*4;j++)
		{
			stats.push_back(getData().get(j).getData(i));
		}
		double average, sum=0;
		for(int i=0;i<stats.size();i++)
		{	
			sum += stats[i];
			//cout << stats[i] << endl;
		}
		average=sum/double(stats.size());
		newTree.setLevel(i+1,chill,average,1);
		if(b==4) cout << "top node" << average <<endl;
		if(b==3) cout << "second level: " << average << endl;
		if(b==2) cout << "third level: " << average << endl;
		if(b==1) cout << "fourth level: " << average << endl;
		b--;
		i+=1;
	}
	/*
	cout << newTree.getFirst().getData() << endl;
	cout << "left node: " << newTree.getFirst().getLeftChild()->getData() << endl;
	cout << "Righ node: " << newTree.getFirst().getRightChild()->getData() << endl;
	cout << "left left :" << newTree.getFirst().getLeftChild()->getLeftChild()->getData() << endl;
	cout << "left right :" << newTree.getFirst().getLeftChild()->getRightChild()->getData() << endl;
	cout << "left right left :" << newTree.getFirst().getLeftChild()->getRightChild()->getLeftChild()->getData() << endl;
	cout << "right right left :" << newTree.getFirst().getRightChild()->getRightChild()->getLeftChild()->getData() << endl;
	*/	
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
	cout << "so nice" << endl;
	return s;
}

void dt::setMapVal(vector<double> vals, TreeNode<double> &a, int i, string actual, int firstTime) //assign values to map at bottom nodes (set i to 0, vals equal all attributes for one node, and TreeNode to first)
{
	
	if(firstTime == 1) a = newTree.getFirst();
	map<string,double >::iterator it;
	//cout << "not even here" << endl;
	//map <string,double> disMap = a.getMap();
	if(vals[i] <= a.getData())
	{	
		//cout << "went left" << endl;
		if ( a.getLeftChild() != NULL)
			setMapVal(vals,*a.getLeftChild(),i+1,actual,0);
		else
		{
			//map <string,int>::iterator it;
			map <string,double> disMap = a.getMap();
			it = disMap.find(actual);
			if(it != disMap.end()) //fill out map
			{
				disMap[actual]++;
				//cout << "multiple here" << endl;
			}
			else
			{
				disMap[actual]=1;
				//cout << "first timer here " << a.getData() << endl;
			}
			a.setMap(disMap);
		}
	}
	else
	{	
		//cout << "went right" << endl;
		if ( a.getRightChild() != NULL)
			setMapVal(vals,*a.getRightChild(),i+1,actual,0);
		else
		{	
			map <string,double> disMap = a.getMap();
			it = disMap.find(actual);
			if(it != disMap.end()) //fill out map
			{
				disMap[actual]++;
				//cout << "multiple hizzere" << endl;
			}
			else
			{
				disMap[actual]=1;
				//cout << "first timer hizere" << a.getData() << endl;
			}
			a.setMap(disMap);
			
		}
	}
	if(firstTime == 1)
		newTree.setFirst(a);
}


#endif
