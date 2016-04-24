#ifndef _NODE_H_
#define _NODE_H_

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

//template<typename T> class LinkedList; // forward declaration of List

template<typename T>   // templated node type
class TreeNode {

  

 public:
  TreeNode(T, string);     // constructor
  TreeNode();
  TreeNode(TreeNode<T> &, TreeNode<T> &);
  T getData() const;   // get function
  string getLabel();
  TreeNode<T> getLeftChild();
  TreeNode<T> getRightChild();
  TreeNode<T> getParent();
  void setParent();
  void setLabel(string s){label = s;}
  void setData(double a){data = a;}

 private:
  T data;           // data for linked list node 
  string label;
  map <double> numOfResults;
  TreeNode<T> *nextl;    // pointers to next object
  TreeNode<T> *nextr;
  TreeNode<T> *parent;
};

// NOTE:  all of the functions are in the .h file to overcome issues with
//        templates and linking

// constructor, using member initialization list syntax
template<typename T>
TreeNode<T>::TreeNode(T a,string s) :data(a),nextl(NULL),nextr(NULL),label(s){}

template<typename T>
TreeNode<T>::TreeNode() : data(0), nextl(NULL),nextr(NULL),label(""){}

template<typename T>
TreeNode<T>::TreeNode(TreeNode<T> &a, TreeNode<T> &b) :data(0),nextl(&a),nextr(&b),label(""){}

// simple get function for our class (if friendship is not used)
template<typename T>
T TreeNode<T>::getData(void) const { return data; }

template<typename T>
string TreeNode<T>::getLabel() { return label;}

template<typename T>
void TreeNode<T>::setParent()
{
	if(nextl->getData() >= nextr->getData())
	{
		data = nextl->getData();
		label = nextl->getLabel();
	}
	else
	{
		data = nextr->getData();
		label = nextr->getLabel();
	}
}

template<typename T>
TreeNode<T> TreeNode<T>::getLeftChild()
{
	return *nextl;
}

template<typename T>
TreeNode<T> TreeNode<T>::getRightChild()
{
	return *nextr;
}

template<typename T>
TreeNode<T> TreeNode<T>::getParent()
{
	return *parent;
}


#endif
