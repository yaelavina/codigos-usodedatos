#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class IPila { public: virtual void push() = 0; virtual void ordenar() = 0; };

class PilaSTL : public IPila {
    stack<int> s;
public:
    void push() override {
        int v; cout << "Dato: "; cin >> v; s.push(v);
    }
    void ordenar() override { // Burbuja
        vector<int> v;
        while(!s.empty()) { v.push_back(s.top()); s.pop(); }
        for(int i=0; i<v.size(); i++)
            for(int j=0; j<v.size()-1-i; j++)
                if(v[j] > v[j+1]) swap(v[j], v[j+1]);
        for(int x : v) s.push(x);
    }
    void ver() {
        stack<int> c = s;
        while(!c.empty()) { cout << c.top() << " "; c.pop(); }
    }
};

int main() {
    PilaSTL p; int op;
    do {
        cout << "\n1.Push 2.Orden 3.Ver 4.Salir: "; cin >> op;
        if(op==1) p.push(); if(op==2) p.ordenar(); if(op==3) p.ver();
    } while(op != 4);
    return 0;
}