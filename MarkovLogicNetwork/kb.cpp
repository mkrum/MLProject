//implementation for the knowledge base class
//Michael Krumdick

#include "kb.h"

kb::kb(vector<string> inClasses, int inSiz):classes(inClasses), size(inSiz){
    for(auto classe : classes){
        for(int i = 0; i < size; i++){
            insight *temp = new insight(0, classe);
            base[classe].push_back(temp);
        }
        lower[classe] = 0;
    }
}

void kb::update(vector<insight*> newInfo, string ident){
    for(auto &info : newInfo){
        if(info->weight() > lower[ident]){
            insert(info, ident);
        }      
    }   
}

void kb::insert(insight *info, string ident){
    int i = 0;
    while(i <= base[ident].size()){
        if(i == base[ident].size() - 1){
            lower[ident] = info->weight();
        }
        if(info->weight() > base[ident][i]->weight()){
            base[ident].insert(base[ident].begin() + i, info);
            base[ident].pop_back();
            break;
        }
        i++;
    }
}

void kb::generate(int length, string ident, vector<insight*>& generation){
    std::uniform_int_distribution<int> distribution(0, base[ident].size() - 1);
    int rand = distribution(generator);
    for(int i = 0; i < generation.size(); i++){
  //      generation[i] = mutate(*base[ident][rand]);
    }
}

insight* kb::mutate(insight in){
    insight *temp = new insight(in);
    std::uniform_int_distribution<int> distribution(0, 1);
    if(distribution(generator)){
        std::uniform_real_distribution<double> dist(-.1, .1);
        double delta = dist(generator);
        for(auto &constant : temp->constants){
            constant = constant + delta;
        }
    } else {
        std::uniform_int_distribution<int> d1(0, in.length);
        std::uniform_int_distribution<int> d2(0, 1);
        temp->order.push_back(d1(generator));
        temp->compOrder.push_back(d2(generator));
        temp->connectOrder.push_back(d2(generator));
    }
    return temp;
}

std::ostream& operator<<(std::ostream & os, const kb test){
   for(auto elem : test.base){
        os << elem.first << std::endl;
        for(auto eq : elem.second){
            os << eq->weight() << std::endl;
        }
   }
}





