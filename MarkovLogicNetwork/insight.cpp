//implementation for the insight class
//Michael Krumdick

#include "insight.h"
   
insight::insight(int len, string in) : identifier(in), attempts(0), successes(0), length(len){
    std::random_device rd;
    std::default_random_engine gen(rd());
    std::uniform_int_distribution<int> d(0,1);
    std::uniform_int_distribution<int> d1(0, len);
    order.push_back(d1(gen));
    compOrder.push_back(d(gen));
    std::uniform_real_distribution<double> dist(0.0, 1.0);
    constants.push_back(dist(gen));
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
        results.push_back(comparisions[compOrder[i]](n[order[i]], constants[i]));
    }
    bool final = condense(results);
//this is overly verbose, but deal with it    
    if(identifier.compare(n.getIdent()) == 0){
       if(final){
           successes++;
           return true;
       } else {
           return false;
       }
    } else {
        if(final){
            return false;
        } else {
            successes++;
            return false;
        }
    }
}

bool insight::condense(vector<bool> results){
    vector<bool> temp;
    bool fin = results[0];
    for(int j = 1; j < results.size(); j++){
        if (connectOrder[j] == 0){
            fin = fin || results[j];
        } else {
            temp.push_back(fin);
            fin = results[j];
        }
    }
    bool ret;
    if(temp.size() > 0){
        ret = temp[0];
        for(int i = 1; i < temp.size(); i++){
            ret = ret && temp[i];
        }
    } else {
        ret = fin;
    }
    return ret;
}

void insight::vectorInit(){
    comparisions.push_back(std::greater<double>());
    comparisions.push_back(std::less<double>());
    connectors.push_back(std::logical_and<bool>());
    connectors.push_back(std::logical_or<bool>());

}

string insight::ident() const {
    return identifier;
}

int insight::column() const {
    return order[0];
}

int insight::size() const {
    return length;
}

ostream& operator<<(ostream & os, insight in){
    vector<string> comp {">", "<"};
    vector<string> con {"and", "or"};
    for(int i = 0; i < in.order.size(); i++){
        os << "( Data[" << in.order[i] << "] " << comp[in.compOrder[i]] << " " << in.constants[i] << " ) ";
        if(in.connectOrder.size() > 0 && i < in.order.size() - 1) {
            os << con[in.connectOrder[i]] << " ";
        }
    }
    return os;
}
   


