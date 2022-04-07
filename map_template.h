#include <iostream>
#include <vector>
using namespace std;

template<typename C, class T> class map_template{
private:

struct node{
    T t;
    C c;
    node(T tt, C cc): t(tt), c(cc){};
};
vector<node> dane;

public:
map_template(){};
map_template(const map_template & s){
    //dane.clear();
    //this->dane.resize(s.dane.size);
    for(unsigned i = 0; i < s.dane.size(); i++){
        dane.push_back(node(s.dane[i].t, s.dane[i].c));
    }

};
~map_template(){
    dane.clear();
}
void Add(const C cc, const T tt){
     dane.push_back(node(tt, cc));
};
friend ostream & operator << (ostream & s, const map_template & c){
    if(c.dane.empty()) s<< "Database is empty";
    else{
        for(unsigned i = 0; i < c.dane.size(); i++){
        s<< "Key: " << c.dane[i].c<<endl;
        s << c.dane[i].t <<endl;
        }
    }
    return s;
};
T* Find(C cc){
    for(unsigned i = 0; i < dane.size(); i++){
        if(dane[i].c==cc) return &dane[i].t;
    }
    return NULL;
}

};


