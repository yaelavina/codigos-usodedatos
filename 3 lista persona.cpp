#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Persona { string curp; int id; };

class ListaPers {
    vector<Persona> v;
public:
    void add() { Persona p; cin >> p.curp >> p.id; v.push_back(p); }
    void ordenar() {
        int n = v.size();
        for (int m=1; m < n; m *= 2) {
            for (int l=0; l < n-1; l += 2*m) {
                int mid=min(l+m-1, n-1), r=min(l+2*m-1, n-1);
                // Ordena basándose en el ID
                auto comp = [](const Persona& a, const Persona& b){ return a.id < b.id; };
                inplace_merge(v.begin()+l, v.begin()+mid+1, v.begin()+r+1, comp);
            }
        }
    }
    void ver() { for(auto& x : v) cout << x.curp << " "; }
};

int main() {
    ListaPers l; int op;
    do { cin >> op; if(op==1) l.add(); if(op==2) l.ordenar(); if(op==3) l.ver(); } while(op!=4);
    return 0;
}