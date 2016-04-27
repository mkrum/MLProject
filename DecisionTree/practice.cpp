
//Marco Bruscia

#include "dt.h"
#include "Tree.h"
#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <locale>
using namespace std;

int main()
{
	dt dtree("iris.csv",5);
	vector <double> results;
	results = dtree.execute();
	cout << results[0] << " " << results[1] << endl;
	return 0;
}
