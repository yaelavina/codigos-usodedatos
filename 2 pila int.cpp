#include <iostream>
using namespace std;

struct Nodo {
    int dato;
    Nodo* siguiente;
};

class IPilaD {
public:
    virtual void push() = 0;
    virtual void pop() = 0;
    virtual void ordenar() = 0;
    virtual void mostrar() = 0;
};

class AbsPilaD : public IPilaD {
protected:
    Nodo* tope;
public:
    AbsPilaD() : tope(nullptr) {}
};

class PilaDinamicaBasica : public AbsPilaD {
public:
    void push() override {
        int v; cout << "Dato: "; cin >> v;
        Nodo* nuevo = new Nodo{v, tope};
        tope = nuevo;
    }
    void pop() override {
        if (tope) {
            Nodo* aux = tope;
            cout << "Sale: " << aux->dato << endl;
            tope = tope->siguiente;
            delete aux;
        } else cout << "Vacia" << endl;
    }
    void ordenar() override { // Burbuja Iterativo sobre Nodos
        if (!tope) return;
        for (Nodo* i = tope; i != nullptr; i = i->siguiente) {
            for (Nodo* j = i->siguiente; j != nullptr; j = j->siguiente) {
                if (i->dato > j->dato) swap(i->dato, j->dato);
            }
        }
    }
    void mostrar() override {
        Nodo* t = tope;
        while(t) { cout << "[" << t->dato << "]->"; t = t->siguiente; }
        cout << "NULL" << endl;
    }
};

int main() {
    PilaDinamicaBasica p; int op;
    do {
        cout << "\n1.Push 2.Pop 3.Orden 4.Ver 5.Salir: "; cin >> op;
        if(op==1) p.push(); if(op==2) p.pop(); if(op==3) p.ordenar(); if(op==4) p.mostrar();
    } while(op != 5);
    return 0;
}
