//Header for decision tree
//Marco Bruscia

#ifndef DT_H
#define DT_H
#include "dataset.h"
#include <string>
#include <iostream>
#include "Tree.h"
#include <map>
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
        string assignTreeProb(vector<double>, TreeNode<double> , int);
        void setMapVal(vector<double>, TreeNode<double> , int,string);
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
	int count = 1,index = 0;
	TreeNode<double> chill = newTree.getFirst();
	newTree.makeTree(4, chill);
	cout << "i'm here" << endl;
	while (b>0)
	{
		vector<double> stats;
		for(int j=0;j<getData().tlength()*4;j++)
		{
			stats.push_back(getData().get(j).getData(i));
		}
		double average, sum=0;
		for(int i=0;i<stats.size();i++)
			sum += stats[i];
		average=sum/stats.size();
		newTree.setLevel(i+1,chill,average);
		b--;
		i+=1;
	}
	cout << newTree.getFirst().getData() << endl;
}

string dt::assignTreeProb(vector<double>vals, TreeNode<double> a, int i) //test values by giving them the best guess available
{
	if(vals[i] <= a.getData())
	{	
		cout << "swex" << endl;
		if ( a.getLeftChild() != NULL)
		{
			cout << "tuddy" << endl;
			assignTreeProb(vals,*a.getLeftChild(),i+1);
		}
		else
			return a.getMostPopularResult();
	}
	else
	{	
		cout << "anal" << endl;
		if ( a.getRightChild() != NULL)
		{	
			cout << "s" << endl;
			assignTreeProb(vals,*a.getRightChild(),i+1);
			cout << "fu" << endl;
		}
		else
			return a.getMostPopularResult();
	}
	cout << "so nice" << endl;
}

void dt::setMapVal(vector<double> vals, TreeNode<double> a, int i, string actual) //assign values to map at bottom nodes (set i to 0, vals equal all attributes for one node, and TreeNode to first)
{
	
	if(vals[i] <= a.getData())
	{	
		if ( a.getLeftChild() != NULL)
			setMapVal(vals,*a.getLeftChild(),i+1,actual);
		else
		{
			map <string,int>::iterator it;
			it = a.getMap().find(actual);
			if(it != a.getMap().end()) //fill out map
			{
				a.getMap()[actual]++;
			}
			else
			{
				a.getMap()[actual]=1;
			}
		}
	}
	else
	{	
		if ( a.getRightChild() != NULL)
			setMapVal(vals,*a.getRightChild(),i+1,actual);
		else
		{	
			map <string,int>::iterator it;
			it = a.getMap().find(actual);
			if(it != a.getMap().end()) //fill out map
			{
				a.getMap()[actual]++;
			}
			else
			{
				a.getMap()[actual]=1;
			}
		}
	}
}


#endif
