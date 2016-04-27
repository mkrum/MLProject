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
		Tree(); //constructor
		~Tree(); //destructor
		TreeNode<double> getFirst(); //return root node
		void makeTree(int, TreeNode<double> &, int); //links all nodes of tree together
		void setLevel(int, TreeNode<double> &, double,int); //sets data value for nodes of certain level
		void setFirst (TreeNode<double> a){first = a;} // sets root node
	private:
		TreeNode<double> first; //root of the data tree

};


Tree::Tree(){}

Tree::~Tree(){}

void Tree::makeTree(int numLevels,TreeNode<double> &k, int firstTime) //takes in number of levels, root node, and int to link root node
{
	
	if (numLevels > 1) //if not on lowest level
	{
		TreeNode<double>* newNodeL = NULL; //make two new nodes
		TreeNode<double>* newNodeR = NULL;
		newNodeL = new TreeNode<double>;
		newNodeR = new TreeNode<double>;
		k.setRight(newNodeR); //set them as children to current node
		k.setLeft(newNodeL);
		makeTree(numLevels-1,*newNodeL,0); //recursive calls on the new nodes
		makeTree(numLevels-1,*newNodeR,0);
	}
	if(firstTime == 1) first = k;
}

void Tree::setLevel(int levelNum, TreeNode<double> &k, double average, int firstTime) //assign data value to each level
{
	if(firstTime == 1) k=first;
	if (levelNum > 1) //if not on lowest level, recursive call to children
	{
		setLevel(levelNum-1, *(k.getLeftChild()),average,0);
		setLevel(levelNum-1, *(k.getRightChild()),average,0);
	}
	else
	{
		k.setData(average); //assign data value to node k
	}
	if(firstTime == 1) first = k; //link first node at the end
	
}

TreeNode<double> Tree::getFirst() //return first node
{
	return first;
}

#endif
