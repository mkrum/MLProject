//Marco Bruscia

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Node.h"

using namespace std;

class Tree {

	public:
		Tree(string);
		Node<int> getFirst();
		void findDataVal(int, Node<int>,int);
		void buildNode();
		int getNumLevels();
	private:
		vector < Node<int> > tree;
		Node<int> first;
		int numLevels;

};


Tree::Tree(string s)
{	
}

Node<int> Tree::getFirst()
{
	return first;
}



void Tree::findDataVal(int a, Node<int> c, int j)
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

void Tree::buildNode(vector<double>)
{
	
}

