//Final visualization menu
//Michael Krumdick

#include "mln.h"
#include "multiNomLogReg.h"
#include "menu.h"
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <iomanip>
#include <string>
#include <cstdlib>

using std::string;
using std::map;
using std::vector;
using std::cout;
using std::endl;
using std::cin;

int main() {
    printMainMenu();
}

void printScreen(vector<string> inputs){
    std::system("clear");
    cout << std::left <<  '*' << std::setfill('*') << std::setw(65) << '*' << std::setfill(' ') << endl;
    cout << '*' << std::setw(64) << ' ' << '*' << endl;
    cout << '*' << std::setw((64 - inputs[0].length())/2.0) << " " << std::setw(65 - (64 - inputs[0].length())/2.0) << inputs[0] << '*' << endl;
    cout << '*' << std::setw(64) << ' ' << '*' << endl;
    cout << '*' << std::setw(64) << ' ' << '*' << endl;
    for(int i = 1; i < inputs.size(); i++){
         cout << std::left << '*' << "   " << i << ". " << std::setw(58) << inputs[i] << "*" << endl;
    }
    cout << '*' << std::setw(64) << ' ' << '*' << endl;
    cout << '*' << std::setw(64) << ' ' << '*' << endl;
    cout << '*' << std::setfill('*') << std::setw(65) << '*' << std::setfill(' ') << endl;
    cout << "Choice : ";
}

void printMainMenu(){
    vector<string> mainM = {"WELCOME TO THE MACHINE LEARNING PROJECT", "Test", "Learn more about the algorithms", "Learn more about the datasets", "Quit"};
    printScreen(mainM);
    int choice;
    cin >> choice;
    switch(choice){
        case 1:
            testMenu();
            break;
        case 2:
            algInfo();
            break;
        case 4:
            system("clear");
            return;
        default:
            printMainMenu();
    }
}

void algInfo(){
    vector<string> text = {"SELECT A ALGORITHM", "Markov Logic Network", "Multinomial Logistic Regression};
    printScreen(text);
    int choice;
    cin >> choice;
    switch(choice){
        case 1:
            markovInfo();
            break;
	case 2:
	    multiNomLogRegInfo();
        default:
            algInfo();
    }
}

void multiNomLogRegInfo(){
    system("clear");
    cout << 
"Markov Logic Network\n"
"\n\n"
"Description\n"
"Multinomial Logistic Regression is, in itself, a mathematical technique for classifying data to certain classifiers by modeling the relationship as a dot product of the dependent variables with certain \n"
"weights that are calculated via ordinary linear regression. This dot product comprises a predictor function that takes in a new data points dependent variables and outputs a value that lies within the\n"
"range of classifier values (numbers that correspond to the string classifier of a datapoint). It essentially creates multiple gradients that separate the differnt class fields of data and can guess which\n"
"classifier a new data point would fall under based on which gradient this data point lies within. \n"
"\n"
"\n"
"Strengths\n"
"   *Extremely fast due to mathematical nature\n"
"   *Works very well with binarily classified data (data with only two classifiers)\n"
"\n"
"Weaknesses\n"
"   *Inconsistent on small sample sizes and on data with more than four classifiers\n"
"   *Inner workings are numerical weights which aren't the most intelligible to humans\n"
"\n"
"Example Case (will take a second to load)\n";
    mnlr example("../breastcancer.csv", 2);
    vector<double> ex = example.exec();
    cout << "Multinomial Logistic Regression ran in " << ex[1] << "seconds with " << ex[2] << "% accuracy";
    cout << "\nMain Menu (1) or Learn About Another Algorithm (2): ";
    cin >> choice;
    switch (choice){
        case 1:
            printMainMenu();
            break;
        case 2:
            algInfo();
            break;
        default:
            algInfo();
}

void markovInfo(){
    system("clear");
    cout << 
"Markov Logic Network\n"
"\n\n"
"Description\n"
"In its simplest form, a Markov Logic Network is a series a logic statements with corresponding weights. It uses these logic statements and weights to analyze the data, and then determine which \n"
"outcome is the most likely. My implementation determines the logic statements using a Genetic Monte Carlo Method. It starts with simple first degree statements and then measures their individual \n"
"success rates. Those with higher success rates are saved into a knowledge base. It then takes these high success statements and mutates them into newer, more complex statements and repeats. This \n"
"process should find the optimal logic statements. For the weights of each of these statements, I just used their past probability of success. To make a prediction, I would run the unknown node \n"
"through all the optimized statements in the knowledge base, tracking the sum of the weights it accumulates. It the classifies the node as being the class with the highest weight score.\n"
"\n"
"Strengths\n"
"   *Relatively high success rate\n"
"   *Since it finds logic statements, it gives insights that are very easy to understand for humans\n"
"\n"
"Weaknesses\n"
"   *Relatively slow\n"
"   *Since it relies on randomly generated statements, it has a highly variable success rate\n"
"\n"
"Example Case (will take a second to load)\n"
"\n";
    mln net = mln("../datasets/breastcancer.csv", 2);
    net.example();
    int choice;
    cout << "\nMain Menu (1) or Learn About Another Algorithm (2): ";
    cin >> choice;
    switch (choice){
        case 1:
            printMainMenu();
            break;
        case 2:
            algInfo();
            break;
        default:
            algInfo();
    }
}

void testMenu(){
    vector<string> text = {"SELECT A DATASET", "Iris", "Breast Cancer", "Credit"};
    printScreen(text);
    int choice;
    cin >> choice;
    switch(choice){
        case 1:
            test("../datasets/iris.csv", 5);
            break;
        case 2:
            test("../datasets/breastcancer.csv", 2);
        case 3:
            test("../datasets/credit.csv", 16);
        default:
            testMenu();
    }
}

void test(string file, int index){
    printHeader();
    printMarkov(file, index);
    cout << "Re-Run (1), New Test (2), or Main Menu (3): ";
    int choice;
    cin >> choice;
    switch(choice){
        case 1:
            test(file, index);
            break;
        case 2:
            testMenu();
            break;
        case 3:
            printMainMenu();
            break;
        default:
            testMenu();
    }
}

void printHeader(){
    std::system("clear");
    cout << std::left << std::setw(35) << "Algorithm" << std::setw(15) << "Time (Seconds)" << std::setw(15) << "Success Rate" << endl;
    cout << std::setfill('-') << std::setw(64) << '-' << std::setfill(' ') << endl;
}   

void printMarkov(string file, int index){
    mln net = mln(file, index);
    vector<double> ret;
    ret = net.execute();
    cout << std::left << std::setw(35) << "Markov Logic Network" << std::setw(15) << ret[0] << std::setw(15) << ret[1] << endl;
}
void printMultiNomLogReg(string file, int index){
	mnlr minler(file, index);
	vector<double> ret;
	ret = milner.exec();
	cout << std::left << std::setw(35) << "Multinomial Logistic Regression" << std::setw(15) << ret[0] << std::setw(15) << ret[1] << endl;
}
