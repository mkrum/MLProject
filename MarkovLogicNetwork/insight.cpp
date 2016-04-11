//implementation for the insight class
//Michael Krumdick

#include "insight.h"
#include <iostream>

insight::insight(int i, string in) : identifier(in), attempts(0), successes(0){
    order.push_back(i);
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(0.0, 1.0);
    constants.push_back(dist(mt));
    vectorInit();
}

insight::insight(int i, int j, string in): identifier(in), attempts(0), successes(0) {
    order.push_back(i);
    constants.push_back(-j);
    vectorInit();
}

double insight::weight() const{
    if(attempts > 0){
        return successes/(1.0 * attempts);
    } else {
        return 0.0;
    }
}

bool insight::check(node n) {
    attempts++;
    vector<bool> results;
    for(int i = 0; i < order.size(); i++){
        if (constants[i] > 0){
            results.push_back(comparisions[i](n[order[i]], constants[i]));
        } else {
            results.push_back(comparisions[i](n[order[i]], n[-constants[i]]));
        }
    }
    for(int j = results.size(); j > 1; j++){
        results[j - 1] = connectors[j](results[j], results[j-1]);
    }
    bool ret = identifier.compare(n.getIdent()) && results[0];
    if (ret){
        successes++;
    }
    return ret;
}

void insight::vectorInit(){
    comparisions.push_back(std::greater<double>());
    comparisions.push_back(std::less<double>());
    connectors.push_back(std::logical_and<bool>());
    connectors.push_back(std::logical_or<bool>());

}
