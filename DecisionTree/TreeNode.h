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
  TreeNode(); //constructor
  ~TreeNode(); //destructor
  T getData() const;   // get function
  TreeNode<T> * getLeftChild(); //returns left child
  TreeNode<T> * getRightChild(); //returns right child
  TreeNode<T> * getParent(); //return parent
  map <string,double> getMap(){return numOfResults;} //returns map
  void setData(double a){dataval = a;} //sets data value
  string getMostPopularResult(); //returns guess as string
  void setParent(TreeNode<double> a){*parent = a;} //set functions for all private variables
  void setLeft(TreeNode<double> * a){nextl = a;}
  void setRight(TreeNode<double> * a){nextr = a;}
  void setMap(map <string,double> a) {numOfResults = a;}

 private:
  T dataval;           // dataval for linked list node 
  map <string,double> numOfResults; //map to keep track of most popular
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
	it = numOfResults.begin(); //start iterator at beginning of map
	string val;
	if (it != numOfResults.end()) //if the map isn't empty
	{
		double popular = it->second; //initialize most popular
		val = it->first;
		for(it=getMap().begin();it != getMap().end();it++) //traverse map
		{
			if (it->second > popular) //change most popular if one of the keys has higher second value
			{
				popular = it->second;
				val = it->first;
			}
		}
	}
	else val = "wrong"; //returns wrong if can't make a guess (map empty)
	return val;
}

#endif
