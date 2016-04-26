//implemenation of the mln class
//Michael Krumdick

#include "mln.h"

mln::mln(string file, int index):data(file, index), objects(data.classes()), dkb(data.classes(), 10) {
    num = 100/objects.size();
    for(int i = 0; i < objects.size(); i++){
            vector<insight*> temp;
            for(int z = 0; z < num; z++){
                insight *insert = new insight(data.columns(), objects[i]);
                temp.push_back(insert);
            }
            knowledge.push_back(temp);
    }
}

vector<double> mln::execute(){ 
    vector<double> ret;
    std::clock_t begin = std::clock();
    learn();
    std::clock_t end = std::clock();
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    ret.push_back(double(elapsed_secs));
    ret.push_back(test());
    return ret;
}

void mln::learnWeights(node n){
    std::thread t[knowledge.size()];
    for(int j = 0; j < knowledge.size(); j++){
            t[j] = std::thread(std::bind(&mln::learnVec, this, std::placeholders::_1, std::placeholders::_2), knowledge[j], n); 
    }

    for(int i = 0; i < knowledge.size(); i++){
        t[i].join();
    }
}

void mln::learnVec(vector<insight*> vec, node n){
    for(auto &part : vec){
        part->check(n);    
    }    
}

void mln::debug(){
    cout << dkb;
}

void mln::evolve(){
    for(auto &know : knowledge){
        dkb.update(know, know[0]->ident());
        dkb.generate(num, know[0]->ident(), know);
    }
}

void mln::learn(){
    for(int i = 0; i < 1; i++){
        data.learn(std::bind(&mln::learnWeights, this, std::placeholders::_1), 1);
        evolve();
    }
}

void mln::classify(node n){
    dkb.classify(n);
}

double mln::test(){
    data.test(std::bind(&mln::classify, this, std::placeholders::_1));
    return dkb.rate();
}

void mln::example(){ 
    vector<double> ret = execute();
    cout << "It took: " << ret[0] << " Seconds to classify the breast cancer data at a success rate of " << ret[1] << endl;
    cout << "Here is the knowledge base that it compiled: " << endl;
    debug();
}

void mln::tweaking(){
    data.learn(std::bind(&mln::learnWeights, this, std::placeholders::_1), 1);
    evolve();
    debug();
    for(int i = 0; i < 100; i++){
        data.learn(std::bind(&mln::learnWeights, this, std::placeholders::_1), 1);
        evolve();
        cout << test() << endl;
    }
    debug();
   
}
