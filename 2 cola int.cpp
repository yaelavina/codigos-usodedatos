#include <iostream>
#include <stack>
using namespace std;

struct Nodo { int dato; Nodo* sig; };

class IColaD { public: virtual void encolar() = 0; virtual void ordenar() = 0; };

class AbsColaD : public IColaD {
protected:
    Nodo *frente = nullptr, *final = nullptr;
    int cont = 0;
};

class ColaDinamicaBasica : public AbsColaD {
public:
    void encolar() override {
        int v; cout << "Dato: "; cin >> v;
        Nodo* nuevo = new Nodo{v, nullptr};
        if (!frente) frente = final = nuevo;
        else { final->sig = nuevo; final = nuevo; }
        cont++;
    }
    void ordenar() override { // QuickSort Iterativo (usando arreglo temporal para facilitar)
        if (cont < 2) return;
        int* temp = new int[cont]; Nodo* aux = frente;
        for(int i=0; i<cont; i++) { temp[i] = aux->dato; aux = aux->sig; }
        // QuickSort Iterativo sobre el arreglo temporal
        stack<pair<int,int>> s; s.push({0, cont-1});
        while(!s.empty()){
            int l=s.top().first, h=s.top().second; s.pop();
            int p=temp[h], i=l-1;
            for(int j=l; j<h; j++) if(temp[j]<p) swap(temp[++i], temp[j]);
            swap(temp[i+1], temp[h]);
            int pi=i+1;
            if(pi-1 > l) s.push({l, pi-1});
            if(pi+1 < h) s.push({pi+1, h});
        }
        aux = frente; for(int i=0; i<cont; i++) { aux->dato = temp[i]; aux = aux->sig; }
        delete[] temp;
    }
    void mostrar() {
        for(Nodo* t = frente; t; t = t->sig) cout << t->dato << "->";
        cout << "NULL" << endl;
    }
};

int main() {
    ColaDinamicaBasica c; int op;
    do {
        cout << "\n1.In 2.Orden 3.Ver 4.Salir: "; cin >> op;
        if(op==1) c.encolar(); if(op==2) c.ordenar(); if(op==3) c.mostrar();
    } while(op != 4);
    return 0;
}