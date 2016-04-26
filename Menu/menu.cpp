//Final visualization menu
//Michael Krumdick

#include "mln.h"
#include "menu.h"

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
    cout << "***" << choice << endl;
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
    vector<string> text = {"SELECT A ALGORITHM", "Markov Logic Network"};
    printScreen(text);
    int choice;
    cin >> choice;
    switch(choice){
        case 1:
            markovInfo();
            break;
        default:
            algInfo();
    }
}


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
            break;
        case 3:
            test("../datasets/credit.csv", 16);
            break;
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
