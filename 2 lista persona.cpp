#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Persona {
public:
    string curp;
    int prioridad;
};

struct NodoL {
    Persona p;
    NodoL* sig;
};

class IListaDP {
public:
    virtual void agregar() = 0;
    virtual void ordenar() = 0;
    virtual void mostrar() = 0;
};

class AbsListaDP : public IListaDP {
protected:
    NodoL* cabeza = nullptr;
    int total = 0;
};

class ImpListaDP : public AbsListaDP {
public:
    void agregar() override {
        Persona per;
        cout << "CURP: "; cin >> per.curp;
        cout << "Prioridad: "; cin >> per.prioridad;
        cabeza = new NodoL{per, cabeza};
        total++;
    }
};

class ListaPersonaD : public ImpListaDP {
public:
    void ordenar() override {
        if (total < 2) return;
        Persona* a = new Persona[total];
        NodoL* aux = cabeza;
        for(int i=0; i<total; i++) { a[i] = aux->p; aux = aux->sig; }

        for (int m=1; m < total; m *= 2) {
            for (int l=0; l < total-1; l += 2*m) {
                int mid = min(l + m - 1, total-1), r = min(l + 2*m - 1, total-1);
                int n1 = mid - l + 1, n2 = r - mid;
                Persona L[n1], R[n2];
                for(int i=0; i<n1; i++) L[i] = a[l+i];
                for(int j=0; j<n2; j++) R[j] = a[mid+1+j];
                int i=0, j=0, k=l;
                while(i<n1 && j<n2) 
                    a[k++] = (L[i].prioridad <= R[j].prioridad) ? L[i++] : R[j++];
                while(i<n1) a[k++] = L[i++];
                while(j<n2) a[k++] = R[j++];
            }
        }
        aux = cabeza;
        for(int i=0; i<total; i++) { aux->p = a[i]; aux = aux->sig; }
        delete[] a;
    }

    void mostrar() override {
        NodoL* t = cabeza;
        while(t) { 
            cout << "{" << t->p.curp << ":" << t->p.prioridad << "} "; 
            t = t->sig; 
        }
        cout << endl;
    }
};

int main() {
    ListaPersonaD l; int op;
    do {
        cout << "\n1.Agregar 2.Ordenar 3.Mostrar 4.Salir: "; cin >> op;
        if(op==1) l.agregar(); if(op==2) l.ordenar(); if(op==3) l.mostrar();
    } while(op != 4);
    return 0;
}
