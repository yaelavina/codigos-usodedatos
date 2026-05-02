#include <iostream>
#include <string>
using namespace std;

class Persona { public: string nombre; int edad; };

class IPilaP {
public:
    virtual void agregar() = 0;
    virtual void ordenar() = 0;
};

class AbsPilaP : public IPilaP {
protected:
    Persona *arr; int tope, cap;
public:
    AbsPilaP(int n) : cap(n), tope(-1) { arr = new Persona[n]; }
};

// CLASE IMPLEMENTACION (Para cumplir SOLID)
class ImpPilaP : public AbsPilaP {
public:
    ImpPilaP(int n) : AbsPilaP(n) {}
    void agregar() override {
        if(tope < cap - 1) {
            tope++;
            cout << "Nombre: "; cin >> arr[tope].nombre;
            cout << "Edad: "; cin >> arr[tope].edad;
        }
    }
};

class PilaPersona : public ImpPilaP {
public:
    PilaPersona(int n) : ImpPilaP(n) {}
    void ordenar() override {
        for(int i=0; i < tope; i++)
            for(int j=0; j < tope-i; j++)
                if(arr[j].edad > arr[j+1].edad) swap(arr[j], arr[j+1]);
    }
    void ver() {
        for(int i=0; i<=tope; i++) cout << arr[i].nombre << " ";
        cout << endl;
    }
};

int main() {
    PilaPersona p(5); int op;
    do {
        cout << "\n1.Add 2.Orden 3.Ver 4.Salir: "; cin >> op;
        if(op==1) p.agregar(); if(op==2) p.ordenar(); if(op==3) p.ver();
    } while(op != 4);
    return 0;
}