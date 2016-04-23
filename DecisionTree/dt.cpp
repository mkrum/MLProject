//implementation for dt
//Marco Bruscia

#include "dt.h"
#include <string>
#include <iostream>
using namespace std;

dt::dt(string,int):data(string s, int i){}

dt::createTree()
{
	int i=getNumAttributes();
	int count = 1;
	Tree("newTree") newTree;
	
	while (getNumAttributes()>0)
	{
		for(int k=0;k<count;k++)
		{
			
		}
		
		newTree.buildNode()
		count=count*2;
	}
}
