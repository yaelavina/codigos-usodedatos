#include <iostream>
using namespace std;

struct Nodo { int v; Nodo* sig; };

class IListaD { public: virtual void add() = 0; virtual void ordenar() = 0; };

class AbsListaD : public IListaD { protected: Nodo* cab = nullptr; int n = 0; };

class ListaDinamicaBasica : public AbsListaD {
public:
    void add() override {
        int val; cout << "Valor: "; cin >> val;
        cab = new Nodo{val, cab}; n++;
    }
    void ordenar() override { // MergeSort Iterativo (vía arreglo temporal)
        if (n < 2) return;
        int* a = new int[n]; Nodo* aux = cab;
        for(int i=0; i<n; i++) { a[i] = aux->v; aux = aux->sig; }
        for (int m=1; m < n; m *= 2) {
            for (int l=0; l < n-1; l += 2*m) {
                int mid = min(l + m - 1, n-1), r = min(l + 2*m - 1, n-1);
                int n1 = mid - l + 1, n2 = r - mid;
                int L[n1], R[n2];
                for(int i=0; i<n1; i++) L[i] = a[l+i];
                for(int j=0; j<n2; j++) R[j] = a[mid+1+j];
                int i=0, j=0, k=l;
                while(i<n1 && j<n2) a[k++] = (L[i]<=R[j]) ? L[i++] : R[j++];
                while(i<n1) a[k++] = L[i++]; while(j<n2) a[k++] = R[j++];
            }
        }
        aux = cab; for(int i=0; i<n; i++) { aux->v = a[i]; aux = aux->sig; }
        delete[] a;
    }
    void ver() {
        for(Nodo* t = cab; t; t = t->sig) cout << t->v << " ";
        cout << endl;
    }
};

int main() {
    ListaDinamicaBasica l; int op;
    do {
        cout << "\n1.Add 2.Orden 3.Ver 4.Salir: "; cin >> op;
        if(op==1) l.add(); if(op==2) l.ordenar(); if(op==3) l.ver();
    } while(op != 4);
    return 0;
}