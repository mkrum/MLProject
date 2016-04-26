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

//template<typename T> class LinkedList; // forward declaration of List

template<typename T>   // templated node type
class TreeNode {

  

 public:
  TreeNode(T, string);     // constructor
  TreeNode();
  TreeNode(TreeNode<T> &, TreeNode<T> &);
  T getData() const;   // get function
  string getLabel();
  TreeNode<T> * getLeftChild();
  TreeNode<T> * getRightChild();
  TreeNode<T> * getParent();
  map <string,double> getMap(){return numOfResults;}
  void setLabel(string s){label = s;}
  void setData(double a){data = a;}
  string getMostPopularResult();
  void setParent(TreeNode<double> a){*parent = a;}
  void setLeft(TreeNode<double> * a){nextl = a;}
  void setRight(TreeNode<double> * a){nextr = a;}
  void setMap(map <string,double> a) {numOfResults = a;}

 private:
  T data;           // data for linked list node 
  string label;
  map <string,double> numOfResults;
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
TreeNode<T> * TreeNode<T>::getLeftChild()
{
	return nextl;
}

template<typename T>
TreeNode<T> * TreeNode<T>::getRightChild()
{
	return nextr;
}

template<typename T>
TreeNode<T> * TreeNode<T>::getParent()
{
	return parent;
}

template<typename T>
string TreeNode<T>::getMostPopularResult()
{
	map <string,double>::iterator it = numOfResults.begin();
	cout << "literally" << endl;
	double popular = it->second;
	string val = it->first;
	cout << "nah tho" << endl;
	for(it=getMap().begin();it != getMap().end();it++)
	{
		cout << "fammin" << endl;
		if (it->second > popular)
		{
			popular = it->second;
			val = it->first;
		}
	}
	cout << "hope you like fammin too" <<endl;
	return val;
}

#endif
