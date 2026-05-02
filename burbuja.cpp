#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct Dato { int id; string etiqueta; };

class OrdenadorBurbuja {
public:
    void ordenar() {
        // Datos a ordenar
        int n = 4;
        int enteros[] = {5, 2, 8, 1};
        char letras[] = {'d', 'a', 'c', 'b'};
        Dato objetos[] = {{3, "Tres"}, {1, "Uno"}, {4, "Cuatro"}, {2, "Dos"}};

        // Algoritmo Burbuja Iterativo
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - 1 - i; j++) {
                if (enteros[j] > enteros[j+1]) swap(enteros[j], enteros[j+1]);
                if (letras[j] > letras[j+1]) swap(letras[j], letras[j+1]);
                if (objetos[j].id > objetos[j+1].id) swap(objetos[j], objetos[j+1]);
            }
        }

        cout << "Burbuja: " << enteros[0] << ", " << letras[0] << ", " << objetos[0].etiqueta << endl;
    }
};

int main() {
    OrdenadorBurbuja ob;
    ob.ordenar();
    return 0;
}