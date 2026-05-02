#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

struct Persona { string nom; int edad; };

class PilaPers {
    stack<Persona> s;
public:
    void add() {
        Persona p; cout << "Nom: "; cin >> p.nom; cout << "Edad: "; cin >> p.edad;
        s.push(p);
    }
    void ordenar() {
        vector<Persona> v;
        while(!s.empty()) { v.push_back(s.top()); s.pop(); }
        for(int i=0; i<v.size(); i++)
            for(int j=0; j<v.size()-1-i; j++)
                if(v[j].edad > v[j+1].edad) swap(v[j], v[j+1]);
        for(auto& x : v) s.push(x);
    }
    void ver() {
        stack<Persona> c = s;
        while(!c.empty()){ cout << c.top().nom << " "; c.pop(); }
    }
};

int main() {
    PilaPers p; int op;
    do {
        cout << "\n1.Add 2.Orden 3.Ver 4.Salir: "; cin >> op;
        if(op==1) p.add(); if(op==2) p.ordenar(); if(op==3) p.ver();
    } while(op != 4);
    return 0;
}