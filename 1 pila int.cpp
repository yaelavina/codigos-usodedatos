#include <iostream>
using namespace std;

class IPilaB {
public:
    virtual void push() = 0;
    virtual void pop() = 0;
    virtual void ordenar() = 0;
    virtual void mostrar() = 0;
};

class AbsPilaB : public IPilaB {
protected:
    int *datos, tope, cap;
public:
    AbsPilaB(int n) : cap(n), tope(-1) { datos = new int[n]; }
    ~AbsPilaB() { delete[] datos; }
};

class PilaBasica : public AbsPilaB {
public:
    PilaBasica(int n) : AbsPilaB(n) {}
    void push() override {
        if(tope < cap - 1) {
            int v; cout << "Numero: "; cin >> v;
            datos[++tope] = v;
        } else cout << "Pila Llena" << endl;
    }
    void pop() override {
        if(tope >= 0) cout << "Sacaste: " << datos[tope--] << endl;
        else cout << "Pila Vacia" << endl;
    }
    void ordenar() override { // Burbuja Iterativo
        for(int i=0; i < tope; i++)
            for(int j=0; j < tope-i; j++)
                if(datos[j] > datos[j+1]) swap(datos[j], datos[j+1]);
    }
    void mostrar() override {
        for(int i=0; i <= tope; i++) cout << datos[i] << " ";
        cout << endl;
    }
};

int main() {
    int n, op; cout << "Tamano: "; cin >> n;
    PilaBasica p(n);
    do {
        cout << "\n1.Agregar 2.Sacar 3.Ordenar 4.Ver 5.Salir: "; cin >> op;
        if(op==1) p.push(); if(op==2) p.pop(); if(op==3) p.ordenar(); if(op==4) p.mostrar();
    } while(op != 5);
    return 0;
}
