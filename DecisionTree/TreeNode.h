#ifndef TNODE_H_
#define TNODE_H_

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <map>
#include <algorithm>
#include <locale>
using namespace std;

template<typename T>   // templated node type
class TreeNode {

 public:
  TreeNode();
  ~TreeNode();
  T getData() const;   // get function
  TreeNode<T> * getLeftChild();
  TreeNode<T> * getRightChild();
  TreeNode<T> * getParent();
  map <string,double> getMap(){return numOfResults;}
  void setData(double a){dataval = a;}
  string getMostPopularResult();
  void setParent(TreeNode<double> a){*parent = a;}
  void setLeft(TreeNode<double> * a){nextl = a;}
  void setRight(TreeNode<double> * a){nextr = a;}
  void setMap(map <string,double> a) {numOfResults = a;}

 private:
  T dataval;           // dataval for linked list node 
  map <string,double> numOfResults;
  TreeNode<T> *nextl;    // pointers to next object
  TreeNode<T> *nextr;
  TreeNode<T> *parent;
};

template<typename T>
TreeNode<T>::TreeNode() : dataval(0), nextl(NULL),nextr(NULL){}

template<typename T>
TreeNode<T>::~TreeNode(){}

template<typename T>
T TreeNode<T>::getData(void) const { return dataval; }


template<typename T>
TreeNode<T> * TreeNode<T>::getLeftChild(){return nextl;}

template<typename T>
TreeNode<T> * TreeNode<T>::getRightChild(){return nextr;}

template<typename T>
TreeNode<T> * TreeNode<T>::getParent(){return parent;}

template<typename T>
string TreeNode<T>::getMostPopularResult()
{
	map <string,double>::iterator it;
	it = numOfResults.begin();
	string val;
	if (it != numOfResults.end())
	{
		double popular = it->second;
		val = it->first;
		for(it=getMap().begin();it != getMap().end();it++)
		{
			if (it->second > popular)
			{
				popular = it->second;
				val = it->first;
			}
		}
	}
	else val = "wrong";
	return val;
}

#endif
