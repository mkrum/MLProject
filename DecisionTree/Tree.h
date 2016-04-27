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
		~Tree();
		TreeNode<double> getFirst();
		void makeTree(int, TreeNode<double> &, int);
		void setLevel(int, TreeNode<double> &, double,int);
		void setFirst (TreeNode<double> a){first = a;}
	private:
		TreeNode<double> first;

};


Tree::Tree(){}

Tree::~Tree(){}

void Tree::makeTree(int numLevels,TreeNode<double> &k, int firstTime)
{
	
	if (numLevels > 1)
	{
		TreeNode<double>* newNodeL = NULL;
		TreeNode<double>* newNodeR = NULL;
		newNodeL = new TreeNode<double>;
		newNodeR = new TreeNode<double>;
		k.setRight(newNodeR);
		k.setLeft(newNodeL);
		makeTree(numLevels-1,*newNodeL,0);
		makeTree(numLevels-1,*newNodeR,0);
	}
	if(firstTime == 1) first = k;
}

void Tree::setLevel(int levelNum, TreeNode<double> &k, double average, int firstTime)
{
	if(firstTime == 1) k=first;
	if (levelNum > 1)
	{
		setLevel(levelNum-1, *(k.getLeftChild()),average,0);
		setLevel(levelNum-1, *(k.getRightChild()),average,0);
	}
	else
	{
		k.setData(average);
	}
	if(firstTime == 1) first = k;	
	
}

TreeNode<double> Tree::getFirst()
{
	return first;
}

#endif
