//implementation for the knowledge base class
//Michael Krumdick

#include "kb.h"

kb::kb(vector<string> inClasses, int inSiz):classes(inClasses), size(inSiz), successes(0), trials(0){
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
    findDef();
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
    auto rand = std::bind(distribution, generator);
    for(int i = 0; i < generation.size() * .5; i++){
        generation[i] = new insight(mutate(*base[ident][rand()], *base[ident][rand()]));
    }
    for(int j = generation.size() * .5; j < generation.size(); j++){
        generation[j] = new insight(base[ident].size(), ident);
    }
}

void kb::findDef(){
    double min = 1;
    for(auto entry : lower){
        if (entry.second < min){
            def = entry.first;
        }
    }
}

insight kb::mutate(insight dst, insight in){
    std::uniform_int_distribution<int> distribution(0, 1);
    std::uniform_int_distribution<int> d1(0, in.order.size() - 1);
    std::uniform_int_distribution<int> d2(0, 1);
    int ord = d1(generator);
    for(int i = 0; i < dst.order.size(); i++){
        if(in.order[ord] == dst.order[i] && in.compOrder[ord] == dst.compOrder[i]){
            dst.order          = in.order;
            dst.compOrder      = in.compOrder;
            dst.connectOrder   = in.connectOrder;
            dst.constants      = in.constants;
            std::uniform_real_distribution<double> dist(-.1, .1);
            for(int i = 0; i < in.constants.size(); i++){
                double delta = dist(generator);
                double shifted = in.constants[i] + delta;
                if(shifted > 0 && shifted < 1){
                    dst.constants[i] = in.constants[i] + delta;
                }
            }
            return dst;
        }
    }
    dst.order.push_back(in.order[ord]);
    dst.compOrder.push_back(in.compOrder[ord]);
    dst.connectOrder.push_back(d2(generator));
    dst.constants.push_back(in.constants[ord]);
    return dst;
}

void kb::classify(node n){
    std::map<string, double> vals;
    string iMax = def;
    double max = 0;
    double score;
    for(auto classe: classes){
        score = 0;
        for(auto in : base[classe]){
            if(in->check(n)) {
                score += in->weight();
            }
        }
        if(score > max){
            iMax = classe;
            max = score;
        }
    }
    if(iMax.compare(n.getIdent()) == 0){
        successes++;
    }
    trials++;

}

double kb::rate() const{
    return successes/(double)trials;
}

std::ostream& operator<<(std::ostream & os, const kb test){
   for(auto elem: test.base){
        os << "Class: " << elem.first << std::endl;
        std::cout << "Weight   Statement" << std::endl;
        for(auto obj : elem.second){
            os << obj->weight() << " " << *obj << std::endl;
        }
   }
}
