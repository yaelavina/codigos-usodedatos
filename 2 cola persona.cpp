#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Persona {
public:
    string nombre;
    int id;
};

struct NodoP {
    Persona p;
    NodoP* sig;
};

class IColaDP {
public:
    virtual void encolar() = 0;
    virtual void ordenar() = 0;
    virtual void mostrar() = 0;
};

class AbsColaDP : public IColaDP {
protected:
    NodoP *frente = nullptr, *final = nullptr;
    int cont = 0;
};

class ImpColaDP : public AbsColaDP {
public:
    void encolar() override {
        Persona per;
        cout << "Nombre: "; cin >> per.nombre;
        cout << "ID: "; cin >> per.id;
        NodoP* nuevo = new NodoP{per, nullptr};
        if (!frente) frente = final = nuevo;
        else { final->sig = nuevo; final = nuevo; }
        cont++;
    }
};

class ColaPersonaD : public ImpColaDP {
public:
    void ordenar() override {
        if (cont < 2) return;
        // Pasamos a arreglo para Quicksort Iterativo
        Persona* temp = new Persona[cont];
        NodoP* aux = frente;
        for(int i=0; i<cont; i++) { temp[i] = aux->p; aux = aux->sig; }

        stack<pair<int,int>> s; s.push({0, cont-1});
        while(!s.empty()){
            int l=s.top().first, h=s.top().second; s.pop();
            int piv = temp[h].id; int i = l-1;
            for(int j=l; j<h; j++) 
                if(temp[j].id < piv) swap(temp[++i], temp[j]);
            swap(temp[i+1], temp[h]);
            int pi = i+1;
            if(pi-1 > l) s.push({l, pi-1});
            if(pi+1 < h) s.push({p+1, h});
        }
        
        aux = frente;
        for(int i=0; i<cont; i++) { aux->p = temp[i]; aux = aux->sig; }
        delete[] temp;
    }

    void mostrar() override {
        for(NodoP* t = frente; t; t = t->sig) 
            cout << "[" << t->p.nombre << "|" << t->p.id << "]->";
        cout << "NULL" << endl;
    }
};

int main() {
    ColaPersonaD c; int op;
    do {
        cout << "\n1.Encolar 2.Ordenar 3.Mostrar 4.Salir: "; cin >> op;
        if(op==1) c.encolar(); if(op==2) c.ordenar(); if(op==3) c.mostrar();
    } while(op != 4);
    return 0;
}
