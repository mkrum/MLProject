//Header for decision tree
//Marco Bruscia

#ifndef DT_H
#define DT_H
#include "dataset.h"
#include <string>
#include <iostream>
#include "Tree.h"
#include <map>
#include <algorithm>
#include <locale>
#include <vector>
#include <ctime>
using namespace std;

class dt {
    public:
        dt(string, int); //constructor
        ~dt(); //destructor
        void createTree(); //function that creates proper amount of nodes for tree
        Tree getTree(){return newTree;}; //returns private Tree newTree
        string assignTreeProb(vector<double>, TreeNode<double> &, int); //returns prediction as a string after traversing tree recursively
        void setMapVal(vector<double>, TreeNode<double> &, int,string, int); //trains the values by adding to map at bottom nodes
        vector <double> execute(); //manipulates dataset to run algorithm, returns time and accuracy
    private:
        dataset data; //dataset to be examined
        Tree newTree; //tree used to predict values
};

dt::dt(string s,int i):data(s,i){}

dt::~dt(){}

void dt::createTree()
{
	int i=0;
	int b = data.columns();
	TreeNode<double> chill = newTree.getFirst();
	if (b>5) b = 4; //caps the size of the tree to 4 levels to keep creation time down
	newTree.makeTree(b, chill,1); //creates tree with b levels
	chill = newTree.getFirst();
	if (b>5) b = 4;
	while (b>0) //assigns data values to each node
	{
		vector<double> stats;
		for(int j=0;j<data.tlength()*4;j++) //collects vector of one column
		{
			stats.push_back(data.get(j).getData(i));
		}
		double average, sum=0;
		for(int i=0;i<stats.size();i++) //calculate average for certain value
		{	
			sum += stats[i];
		}
		average=sum/double(stats.size());
		newTree.setLevel(i+1,chill,average,1); //sets that average at every node at level b
		b--;
		i+=1;
	}	
}

string dt::assignTreeProb(vector<double>vals, TreeNode<double> &a, int i) //test values by giving them the best guess available
{
	string s;
	if(vals[i] <= a.getData()) //go left
	{	
		if ( a.getLeftChild() != NULL) //if not at the bottom node
		{
			s = assignTreeProb(vals,*a.getLeftChild(),i+1);
		}
		else
		{
			s = a.getMostPopularResult();
			return s;
		}
	}
	else //go right
	{	
		if ( a.getRightChild() != NULL) //if not at the bottom node
		{	
			s = assignTreeProb(vals,*a.getRightChild(),i+1);
		}
		else
		{
			s = a.getMostPopularResult();
			return s;
		}
	}
	return s;
}

void dt::setMapVal(vector<double> vals, TreeNode<double> &a, int i, string actual, int firstTime) //assign values to map at bottom nodes
{
	
	if(firstTime == 1) a = newTree.getFirst(); //links TreeNode to root node of dtree during the first call
	map<string,double >::iterator it;
	if(vals[i] <= a.getData()) //go left
	{	
		if ( a.getLeftChild() != NULL) //if not at the bottom node
			setMapVal(vals,*a.getLeftChild(),i+1,actual,0);
		else
		{
			map <string,double> disMap = a.getMap();
			it = disMap.find(actual);
			if(it != disMap.end()) //check to see if key 'actual' exists in map yet
			{
				disMap[actual]++;
			}
			else
			{
				disMap[actual]=1;
			}
			a.setMap(disMap); //assigns map to treeNode a
		}
	}
	else //go right
	{	
		if ( a.getRightChild() != NULL) //if not at the bottom node
			setMapVal(vals,*a.getRightChild(),i+1,actual,0);
		else
		{	
			map <string,double> disMap = a.getMap();
			it = disMap.find(actual);
			if(it != disMap.end())//check to see if key 'actual' exists in map yet
			{
				disMap[actual]++;
			}
			else
			{
				disMap[actual]=1;
			}
			a.setMap(disMap); //assigns map to treeNode a
			
		}
	}
	if(firstTime == 1) //links root node of dtree to the root node of the function once done mapping
		newTree.setFirst(a);
}

vector<double> dt::execute() //run the algorithm
{
	const clock_t begin_time = clock();
	vector <double> finalResults;
	int numCorrect = 0;
	double percentCorrect;
	string actual;
	createTree(); //makes intial tree
	TreeNode<double> root = getTree().getFirst();
	
	for(int i=0;i<data.tlength()*4;i++) //collects vector of datavalues for each node in dataset, one node at a time
	{
		
		vector<double> vals;
		for(int j=0;j<data.columns();j++)
		{
			vals.push_back(data.get(i).getData(j));
		}
		actual = data.get(i).getIdent(); //get the actual value to be added to map
		setMapVal(vals,root,0,actual,1); //sets value by sending vector of values, root node, and string actual
		
	}
	
	vector<string> testStats;
	int sizeOfTest = data.tlength();
	root = getTree().getFirst();
	for(int i=sizeOfTest*4;i<sizeOfTest*5-2;i++) //create vector for each node in dataset
	{
		vector<double> stats;
		for(int j=0;j<data.columns();j++)
		{
			stats.push_back(data.get(i).getData(j));
		}
		testStats.push_back(assignTreeProb(stats, root,0)); //creates a vector of string guesses returned from assignTreeProb
		
	}
	for(int i=sizeOfTest*4;i<sizeOfTest*5-2;i++) //calculate number of correct guesses
	{
		if(data.get(i).getIdent() == testStats[i-sizeOfTest*4])
			numCorrect++;
	
	}
	//calculate percent correct and time
	percentCorrect = numCorrect/double(data.tlength());
	double time = double(clock() - begin_time)/CLOCKS_PER_SEC;
	finalResults.push_back(percentCorrect);
	finalResults.push_back(time);
	return finalResults;
}

#endif
