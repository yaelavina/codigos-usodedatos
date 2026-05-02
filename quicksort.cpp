#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct Dato { int prioridad; };

class OrdenadorQuick {
public:
    void ordenar() {
        int nums[] = {7, 1, 9, 3};
        char letras[] = {'x', 'h', 'a', 'p'};
        Dato datos[] = {{50}, {10}, {40}, {20}};
        int n = 4;

        // Pila para simular la recursión (QuickSort Iterativo)
        stack<pair<int, int>> pila;
        pila.push({0, n - 1});

        while (!pila.empty()) {
            int ini = pila.top().first;
            int fin = pila.top().second;
            pila.pop();

            if (ini >= fin) continue;

            // Partición con el último elemento como pivote
            int pivote = nums[fin];
            int i = ini - 1;
            for (int j = ini; j < fin; j++) {
                if (nums[j] < pivote) {
                    i++;
                    swap(nums[i], nums[j]);
                    swap(letras[i], letras[j]);
                    swap(datos[i], datos[j]);
                }
            }
            swap(nums[i + 1], nums[fin]);
            swap(letras[i + 1], letras[fin]);
            swap(datos[i + 1], datos[fin]);
            
            int p_idx = i + 1;

            // Guardamos los rangos de las dos mitades
            pila.push({ini, p_idx - 1});
            pila.push({p_idx + 1, fin});
        }

        cout << "Quick: " << nums[0] << ", " << letras[0] << ", " << datos[0].prioridad << endl;
    }
};

int main() {
    OrdenadorQuick oq;
    oq.ordenar();
    return 0;
}