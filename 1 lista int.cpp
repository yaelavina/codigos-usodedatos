#include <iostream>
#include <algorithm>
using namespace std;

class ILista { public: virtual void insertar() = 0; virtual void ordenar() = 0; };

class AbsLista : public ILista {
protected:
    int *arr, tam, cap;
public:
    AbsLista(int n) : cap(n), tam(0) { arr = new int[n]; }
};

class ListaBasica : public AbsLista {
public:
    ListaBasica(int n) : AbsLista(n) {}
    void insertar() override {
        if(tam < cap) {
            int v; cout << "Dato: "; cin >> v;
            arr[tam++] = v;
        }
    }
    void ordenar() override { // MergeSort Iterativo
        for (int m=1; m <= tam-1; m = 2*m) {
            for (int l=0; l < tam-1; l += 2*m) {
                int mid = min(l + m - 1, tam-1), r = min(l + 2*m - 1, tam-1);
                int n1 = mid - l + 1, n2 = r - mid;
                int L[n1], R[n2];
                for(int i=0; i<n1; i++) L[i] = arr[l+i];
                for(int j=0; j<n2; j++) R[j] = arr[mid+1+j];
                int i=0, j=0, k=l;
                while(i<n1 && j<n2) arr[k++] = (L[i]<=R[j]) ? L[i++] : R[j++];
                while(i<n1) arr[k++] = L[i++];
                while(j<n2) arr[k++] = R[j++];
            }
        }
    }
    void ver() {
        for(int i=0; i<tam; i++) cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    ListaBasica l(5); int op;
    do {
        cout << "\n1.Ins 2.Orden 3.Ver 4.Salir: "; cin >> op;
        if(op==1) l.insertar(); if(op==2) l.ordenar(); if(op==3) l.ver();
    } while(op != 4);
    return 0;
}