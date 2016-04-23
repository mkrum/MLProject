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
        mutate(generation[i], base[ident][rand]);
    }
}

void kb::mutate(insight *dst, insight *in){
    std::uniform_int_distribution<int> distribution(0, 1);
    if(distribution(generator)){
        dst->order          = in->order;
        dst->compOrder      = in->compOrder;
        dst->connectOrder   = in->connectOrder;
        dst->constants      = in->constants;
        std::uniform_real_distribution<double> dist(-.1, .1);
        for(int i = 0; i < in->constants.size(); i++){
            double delta = dist(generator);
            double shifted = in->constants[i] + delta;
            if(shifted > 0 && shifted < 1){
                dst->constants[i] = in->constants[i] + delta;
            }
        }
    } else {
        std::uniform_int_distribution<int> d1(0, in->order.size() - 1);
        std::uniform_int_distribution<int> d2(0, 1);
        double ord = d1(generator);
        dst->order.push_back(in->order[ord]);
        dst->compOrder.push_back(in->compOrder[ord]);
        dst->connectOrder.push_back(d2(generator));
        dst->constants.push_back(in->constants[ord]);
    }
}

std::ostream& operator<<(std::ostream & os, const kb test){
   for(auto elem : test.base){
        os << elem.first << std::endl;
        for(auto eq : elem.second){
            os << eq->weight() << std::endl;
        }
   }
}





