#include <iostream>
#include <stack> 
using namespace std;

class ICola {
public:
    virtual void encolar() = 0;
    virtual void ordenar() = 0;
};

class AbsCola : public ICola {
protected:
    int *arr, f, a, cap, cont;
public:
    AbsCola(int n) : cap(n), f(0), a(-1), cont(0) { arr = new int[n]; }
};

class ColaBasica : public AbsCola {
public:
    ColaBasica(int n) : AbsCola(n) {}
    void encolar() override {
        if(cont < cap) {
            int v; cout << "Dato: "; cin >> v;
            a = (a + 1) % cap; arr[a] = v; cont++;
        }
    }
    void ordenar() override { 
        if(cont < 2) return;
        stack<pair<int,int>> s; s.push({0, cont-1});
        while(!s.empty()){
            int l=s.top().first, h=s.top().second; s.pop();
            int piv=arr[h], i=l-1;
            for(int j=l; j<h; j++) if(arr[j]<piv) swap(arr[++i], arr[j]);
            swap(arr[i+1], arr[h]);
            int pi = i+1;
            if(pi-1 > l) s.push({l, pi-1});
            if(pi+1 < h) s.push({pi+1, h});
        }
    }
    void ver() {
        for(int i=0; i<cont; i++) cout << arr[(f+i)%cap] << " ";
        cout << endl;
    }
};

int main() {
    ColaBasica c(5); int op;
    do {
        cout << "\n1.In 2.Orden 3.Ver 4.Salir: "; cin >> op;
        if(op==1) c.encolar(); if(op==2) c.ordenar(); if(op==3) c.ver();
    } while(op != 4);
    return 0;
}
