//Marco Bruscia
#ifndef T_H
#define T_H

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
		void buildNode(vector<double> );
		int getNumLevels();
		TreeNode<double>  findNextNode(TreeNode<double> &);
		int leftNode(TreeNode<double> &);
	private:
		vector < TreeNode<double> > tree;
		TreeNode<double> first;
		int numLevels;

};


Tree::Tree()
{}

TreeNode<double> Tree::getFirst()
{
	return first;
}


int Tree::getNumLevels() { return numLevels; }

void Tree::buildNode(vector<double> a)
{
	TreeNode<double> c = getFirst();
	TreeNode<double> n = findNextNode(c); //finds next available empty node
	TreeNode<double> nextOne;
	nextOne.setParent(n);
	double average, sum=0;
	for(int i=0;i<a.size();i++)
		sum += a[i];
	average=sum/a.size();
	nextOne.setData(average);
	if(leftNode(n))
		n.setLeft(nextOne);
	else
		n.setRight(nextOne);
}

TreeNode<double> Tree::findNextNode(TreeNode<double>  &a)//needs to be fixed
{
	if(a.getLeftChild() == NULL) return *(a.getLeftChild());
	if(a.getRightChild() == NULL) return *(a.getLeftChild());
	return findNextNode(*(a.getLeftChild()));
}

int Tree::leftNode(TreeNode<double> &n)
{
	if (n.getParent()->getLeftChild()->getData() ==  n.getData())
		return 1;
	else return 0;
}
#endif
