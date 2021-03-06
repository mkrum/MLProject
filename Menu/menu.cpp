//Final visualization menu
//Michael Krumdick

#include "menu.h"

int main() {
    printMainMenu();
}
//a general menu printing function
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
//Main Menu function
void printMainMenu(){
    vector<string> mainM = {"WELCOME TO THE MACHINE LEARNING PROJECT", "Test", "Learn more about the algorithms", "Learn more about the datasets", "Quit"};
    printScreen(mainM);
    int choice;
    cin >> choice;
    cout << "***" << choice << endl;
    switch(choice){
        case 1:
            testMenu();
            break;
        case 2:
            algInfo();
            break;
        case 3:
            datasetInfo();
            break;
        case 4:
            system("clear");
            return;
        default:
            printMainMenu();
    }
}
//Displays the algorithm info
void algInfo(){
    vector<string> text = {"SELECT A ALGORITHM ", "Markov Logic Network", "Multinomial Logistic Regression","Decision Tree","Neural Network"};
    printScreen(text);
    int choice;
    cin >> choice;
    switch(choice){
        case 1:
            markovInfo();
            break;
	case 2:
	    multiNomLogRegInfo();
	    break;
	case 3:
	    decisionTreeInfo();
	    break;
        case 4:
            networkInfo();
            break;
        default:
            algInfo();
    }
}
//displays the content of a file
void display(string file){
    system("clear");
    std::ifstream mfile(file);
    string line;
    while (std::getline(mfile, line)){
        cout << line << endl;
    }
    int choice;
    cout << "\nMain Menu (1) or Learn About Another Dataset (2): ";
    cin >> choice;
    switch (choice){
        case 1:
            printMainMenu();
            break;
        case 2:
            datasetInfo();
            break;
        default:
            datasetInfo();
    }
}
//dataset information menu
void datasetInfo(){
    vector<string> text = {"SELECT A DATASET ", "Iris", "Breast Cancer", "Credit", "Wine", "Uncorrelated Data"};
    printScreen(text);
    int choice;
    cin >> choice;
    switch(choice){
        case 1:
            display("iris.txt");
            break;
        case 2:
            display("breastcancer.txt");
            break;
        case 3:
            display("credit.txt");
            break;
        case 4:
            display("wine.txt");
            break;
        case 5:
            display("uncorrelated.txt");
            break;
        default:
            testMenu();
    }
}
//displays the information for markov
void markovInfo(){
    system("clear");
    std::ifstream mfile("markov.txt");
    string line;
    while (std::getline(mfile, line)){
        cout << line << endl;
    }
    mfile.close();
    cout << "Example Case (will take a second to load)\n";
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
//Displays the info for a neural network
void networkInfo(){
    system("clear");
    std::ifstream mfile("network.txt");
    string line;
    while (std::getline(mfile, line)){
        cout << line << endl;
    }
    mfile.close();
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
//displays the info for the decision tree
void decisionTreeInfo(){
    system("clear");
    std::ifstream mfile("tree.txt");
    string line;
    while (std::getline(mfile, line)){
        cout << line << endl;
    }
    mfile.close();
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
//Displays info for MNLR
void multiNomLogRegInfo(){
    system("clear");
    std::ifstream mfile("multiNomLogReg.txt");
    string line;
    while (std::getline(mfile, line)){
        cout << line << endl;
    }
    mfile.close();
    cout << "Example Case (will take a second to load)\n" << endl;
    multiNomLogReg example("../datasets/breastcancer.csv" , 2);
    vector<double> ex;
    ex =  example.exec();
    cout << "Multinomial Logistic Regression ran in " << ex[1] << " seconds with " << ex[0]*100 << "\% accuracy";
    cout << "\nMain Menu (1) or Learn About Another Algorithm (2): ";
    int choice;
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
//Shows the menu for testing
void testMenu(){
    vector<string> text = {"SELECT A DATASET", "Iris", "Breast Cancer", "Credit","Wine", "Uncorrelated Data"};
    printScreen(text);
    int choice;
    cin >> choice;
    std::system("clear");
    switch(choice){
        case 1:
            cout << "Dataset: Iris" << endl;
            test("../datasets/iris.csv", 5);
            break;
        case 2:
            cout << "Dataset: Breast Cancer" << endl;
            test("../datasets/breastcancer.csv", 2);
            break;
        case 3:
            cout << "Dataset: Credit" << endl;
            test("../datasets/credit.csv", 16);
            break;
        case 4:
            cout << "Dataset: Wine" << endl;
            test("../datasets/wine.csv", 1);
            break;
        case 5:
            cout << "Dataset: Uncorrelated" << endl;
            test("../datasets/uncorrelated.csv", 3);
            break;
        default:
            testMenu();
    }
}
//Test a dataset
void test(string file, int index){
    printHeader();
    printMarkov(file, index);
    printNeuralNetwork(file, index);
    printMultiNomLogReg(file, index);
    printDecisionTree(file, index);
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
//Prints the display header for testing a dataset
void printHeader(){
    cout << std::left << std::setw(35) << "Algorithm" << std::setw(15) << "Time (Seconds)" << std::setw(15) << "Success Rate" << endl;
    cout << std::setfill('-') << std::setw(64) << '-' << std::setfill(' ') << endl;
}   
//Prints the results of Markov
void printMarkov(string file, int index){
    mln net = mln(file, index);
    vector<double> ret;
    ret = net.execute();
    cout << std::left << std::setw(35) << "Markov Logic Network" << std::setw(15) << ret[0] << std::setw(15) << ret[1] << endl;
}
//Prints the results for the Neural Network
void printNeuralNetwork(string file, int index){
    NeuralNetwork network=NeuralNetwork(file, index);
    network.execute();
    cout << std::left << std::setw(35) << "Neural Network" << std::setw(15) << network.getDuration() << std::setw(15) << network.getPercentage() << endl;
}
//Prints the results for MNLR
void printMultiNomLogReg(string file, int index){
	multiNomLogReg minler(file, index);
	vector<double> ret;
	ret = minler.exec();
	cout << std::left << std::setw(35) << "Multinomial Logistic Regression" << std::setw(15) << ret[1] << std::setw(15) << ret[0] << endl;
}
//Prints the results for Decision tree
void printDecisionTree(string file, int index){
	dt dtree(file, index);
	vector<double> ret;
	ret = dtree.execute();
	cout << std::left << std::setw(35) << "Decision Tree" << std::setw(15) << ret[1] << std::setw(15) << ret[0] << endl;
}
