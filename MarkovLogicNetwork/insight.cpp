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
    std::cout << "******" << order.size() << " " << compOrder.size() << " " << connectOrder.size() << std::endl;
    for(int i = 0; i < order.size(); i++){
        std::cout << n[i] <<  " " << constants[i] << std::endl;
        results.push_back(comparisions[compOrder[i]](n[order[i]], constants[i]));
    }
    bool final = results[results.size() - 1];
    for(int j = results.size() - 2; j >= 0; j--){
        final = connectors[connectOrder[j]](results[j], final);
    }
    
    if(identifier.compare(n.getIdent())){
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
            return true;
        }
    }
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

ostream& operator<<(ostream & os, const insight in){
    vector<string> comp {">", "<"};
    vector<string> con {"and", "or"};
    for(int i = 0; i < in.order.size(); i++){
        os << "( Data[" << in.order[i] << "] " << comp[in.compOrder[i]] << " " << in.constants[i] << " ) ";
        if(i > 0) {
            os << con[in.connectOrder[i - 1]] << " ";
        }
    }
}
   


