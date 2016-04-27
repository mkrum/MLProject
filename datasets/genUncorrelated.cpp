//Generates a random file of uncorrelated data
//Michael Krumdick

#include <random>
#include <fstream>
#include <string>
#include <vector>
#include <functional>

using namespace std;

int main(){
    vector<string> names = {"michael", "Will", "Luke", "Marco"};
    ofstream mfile("uncorrelated.csv");
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(0,3);
    auto rname = std::bind(distribution, generator);
    std::uniform_real_distribution<double> dis(0, 1);
    auto rando = std::bind(dis, generator);
    for(int i = 0; i < 100; i++){
        mfile << rando() << "," << rando() << "," << names[rname()] << endl;
    }
    
}
