//Marco Bruscia

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "TreeNode.h"

using namespace std;

class Tree {

	public:
		Tree(string);
		TreeNode<int> getFirst();
		void findDataVal(int, TreeNode<int>,int);
		void buildNode();
		int getNumLevels();
	private:
		vector < TreeNode<int> > tree;
		TreeNode<double> first;
		int numLevels;

};


Tree::Tree(string s)
{	
}

TreeNode<int> Tree::getFirst()
{
	return first;
}



void Tree::findDataVal(int a, TreeNode<int> c, int j)
{	
	if(j-1)
	{
		if(c.getLeftChild().getData() == a)		
			cout << c.getLeftChild().getLabel() << endl;
		
		if(c.getRightChild().getData() == a)
			cout <<  c.getRightChild().getLabel() << endl;
			
		findDataVal(a, c.getRightChild(),j-1);
		findDataVal(a, c.getLeftChild(),j-1);
	}
	
}

int Tree::getNumLevels() { return numLevels; }

void Tree::buildNode(vector<double> a)
{
	treeNode n = findNextNode();
	TreeNode nextOne;
	nextOne->parent = n;
	if(leftNode(n))
		n->nextl = nextOne;
	else n->nextr = nextOne;
	double average, sum=0;
	for(int i=0;i<a.size();i++)
		sum += a[i];
	average=sum/a.size()
	nextOne.setData(average);
}

TreeNode<double> Tree::findNextNode();
{
	node a = first;
	while(a != NULL)
	{
		a = a.getLeftChild();
		if(a == NULL) break;
		a = a.getRightChild();
	}
	return a;
}

int Tree::leftNode(n)
{
	if (n.getParent().getLeftChild == n)
		return 1
	else return 0;
}

