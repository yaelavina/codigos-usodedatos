#include <iostream>
#include <string>
using namespace std;

class Persona { public: string nombre; int edad; };
struct NodoP { Persona p; NodoP* sig; };

class IPilaDP { public: virtual void add() = 0; virtual void ordenar() = 0; };

class AbsPilaDP : public IPilaDP { protected: NodoP* tope = nullptr; };

// III. IMPLEMENTACION (Maneja el objeto Persona)
class ImpPilaDP : public AbsPilaDP {
public:
    void add() override {
        Persona per; cout << "Nombre: "; cin >> per.nombre; cout << "Edad: "; cin >> per.edad;
        tope = new NodoP{per, tope};
    }
};

// IV. CONCRETA
class PilaPersonaD : public ImpPilaDP {
public:
    void ordenar() override {
        for(NodoP* i = tope; i; i = i->sig)
            for(NodoP* j = i->sig; j; j = j->sig)
                if(i->p.edad > j->p.edad) swap(i->p, j->p);
    }
    void ver() {
        for(NodoP* t = tope; t; t = t->sig) cout << t->p.nombre << " ";
        cout << endl;
    }
};

int main() {
    PilaPersonaD p; int op;
    do {
        cout << "\n1.Add 2.Orden 3.Ver 4.Salir: "; cin >> op;
        if(op==1) p.add(); if(op==2) p.ordenar(); if(op==3) p.ver();
    } while(op != 4);
    return 0;
}