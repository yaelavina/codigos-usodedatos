#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Persona { public: string nombre; int id; };

class IListaP { public: virtual void add() = 0; virtual void ordenar() = 0; };

class AbsListaP : public IListaP {
protected:
    Persona *arr; int tam, cap;
public:
    AbsListaP(int n) : cap(n), tam(0) { arr = new Persona[n]; }
};

class ImpListaP : public AbsListaP {
public:
    ImpListaP(int n) : AbsListaP(n) {}
    void add() override {
        if(tam < cap) {
            cout << "Nombre: "; cin >> arr[tam].nombre;
            cout << "ID: "; cin >> arr[tam].id;
            tam++;
        }
    }
};

class ListaPersona : public ImpListaP {
public:
    ListaPersona(int n) : ImpListaP(n) {}
    void ordenar() override { // MergeSort por ID
        for (int m=1; m <= tam-1; m = 2*m) {
            for (int l=0; l < tam-1; l += 2*m) {
                int mid = min(l + m - 1, tam-1), r = min(l + 2*m - 1, tam-1);
                int n1 = mid - l + 1, n2 = r - mid;
                Persona L[n1], R[n2];
                for(int i=0; i<n1; i++) L[i] = arr[l+i];
                for(int j=0; j<n2; j++) R[j] = arr[mid+1+j];
                int i=0, j=0, k=l;
                while(i<n1 && j<n2) arr[k++] = (L[i].id <= R[j].id) ? L[i++] : R[j++];
                while(i<n1) arr[k++] = L[i++];
                while(j<n2) arr[k++] = R[j++];
            }
        }
    }
    void ver() {
        for(int i=0; i<tam; i++) cout << arr[i].nombre << " ";
        cout << endl;
    }
};

int main() {
    ListaPersona l(5); int op;
    do {
        cout << "\n1.Add 2.Orden 3.Ver 4.Salir: "; cin >> op;
        if(op==1) l.add(); if(op==2) l.ordenar(); if(op==3) l.ver();
    } while(op != 4);
    return 0;
}