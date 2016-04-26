//Marco Bruscia
#ifndef _T_H_
#define _T_H_

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "TreeNode.h"
#include <algorithm>
#include <locale>
using namespace std;

class Tree {

	public:
		Tree();
		TreeNode<double> getFirst();
		void buildNode(vector<double>, TreeNode<double> &, int);
		int getNumLevels();
		TreeNode<double>  findNextNode(TreeNode<double> &);
		int leftNode(TreeNode<double> &);
		void makeTree(int, TreeNode<double> &);
		void setLevel(int, TreeNode<double> &, double);
	private:
		vector < TreeNode<double> > tree;
		TreeNode<double> first;
		int numLevels;

};


Tree::Tree()
{
	
}

void Tree::makeTree(int numLevels,TreeNode<double> &k)
{
	
	if (numLevels > 0)
	{
		TreeNode<double>* newNodeL = NULL;
		TreeNode<double>* newNodeR = NULL;
		newNodeL = new TreeNode<double>;
		newNodeR = new TreeNode<double>;
		k.setRight(newNodeR);
		k.setLeft(newNodeL);
		makeTree(numLevels-1,*newNodeL);
		makeTree(numLevels-1,*newNodeR);
	}
	else
		cout << "done" << endl;
}

void Tree::setLevel(int levelNum, TreeNode<double> &k, double average)
{
	if (levelNum > 1)
	{
		cout << "top" << endl;
		setLevel(levelNum-1, *(k.getLeftChild()),average);
		setLevel(levelNum-1, *(k.getRightChild()),average);
	}
	else
	{
		k.setData(average);
		first = k;
	}
		
	
}

TreeNode<double> Tree::getFirst()
{
	return first;
}


int Tree::getNumLevels() { return numLevels; }
/*
void Tree::buildNode(vector<double> a, TreeNode<double> &k, int count)
{
	cout << "in here famo" << endl;
	TreeNode<double> c = getFirst();
	TreeNode<double> n = findNextNode(c); //finds next available empty node
	cout << "no way it gets here" << endl;
	TreeNode<double> nextOne;
	nextOne.setParent(n);
	double average, sum=0;
	for(int i=0;i<a.size();i++)
		sum += a[i];
	average=sum/a.size();
	nextOne.setData(average);
	cout << average << endl;
	
	
	
	if(count == 0)
		k.setData(average);
	else 
	{	
		buildNode(a,*(k->getLeftChild()),count-1);
		buildNode(a,*(k->getRightChild()),count-1);
	}	
		
	if(leftNode(n))
		n.setLeft(nextOne);
	else
		n.setRight(nextOne);
}

TreeNode<double> Tree::findNextNode(TreeNode<double>  &a)//needs to be fixed
{
	if(a.getLeftChild() == NULL) return *(a.getLeftChild()->getParent());
	if(a.getRightChild() == NULL) return *(a.getLeftChild()->getParent());
	return findNextNode(*(a.getLeftChild()));
}

int Tree::leftNode(TreeNode<double> &n)
{
	if (n.getParent()->getLeftChild()->getData() ==  n.getData())
		return 1;
	else return 0;
}
*/
#endif
