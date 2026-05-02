#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Persona { public: string curp; int valor; };

class IColaP { public: virtual void add() = 0; virtual void ordenar() = 0; };

class AbsColaP : public IColaP {
protected:
    Persona *arr; int f, a, cap, cont;
public:
    AbsColaP(int n) : cap(n), f(0), a(-1), cont(0) { arr = new Persona[n]; }
};

class ImpColaP : public AbsColaP {
public:
    ImpColaP(int n) : AbsColaP(n) {}
    void add() override {
        if(cont < cap) {
            a = (a+1)%cap;
            cout << "CURP: "; cin >> arr[a].curp;
            cout << "Valor: "; cin >> arr[a].valor;
            cont++;
        }
    }
};

class ColaPersona : public ImpColaP {
public:
    ColaPersona(int n) : ImpColaP(n) {}
    void ordenar() override {
        stack<pair<int,int>> s; s.push({0, cont-1});
        while(!s.empty()){
            int l=s.top().first, h=s.top().second; s.pop();
            int p=arr[h].valor, i=l-1;
            for(int j=l; j<h; j++) if(arr[j].valor < p) swap(arr[++i], arr[j]);
            swap(arr[i+1], arr[h]);
            int pi=i+1;
            if(pi-1 > l) s.push({l, pi-1});
            if(pi+1 < h) s.push({pi+1, h});
        }
    }
    void ver() {
        for(int i=0; i<cont; i++) cout << arr[(f+i)%cap].curp << " ";
        cout << endl;
    }
};

int main() {
    ColaPersona c(5); int op;
    do {
        cout << "\n1.Add 2.Orden 3.Ver 4.Salir: "; cin >> op;
        if(op==1) c.add(); if(op==2) c.ordenar(); if(op==3) c.ver();
    } while(op != 4);
    return 0;
}