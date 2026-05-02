#include <iostream>

using namespace std;

class IEstadistica {
public:
    virtual void procesarDatos() = 0;
};

class CalculadoraEstadistica : public IEstadistica {
public:
    void procesarDatos() override {
        int numeros[5];
        int* ptr = numeros;
        
        cout << "Ingrese 5 numeros enteros:" << endl;
        for (int i = 0; i < 5; i++) {
            cout << "Numero [" << i + 1 << "]: ";
            cin >> *(ptr + i);
        }

        int suma = 0;
        int maximo = *ptr;
        int minimo = *ptr;

        for (int i = 0; i < 5; i++) {
            int valorActual = *(ptr + i);
            
            suma += valorActual;

            if (valorActual > maximo) maximo = valorActual;
            if (valorActual < minimo) minimo = valorActual;
        }

        double promedio = static_cast<double>(suma) / 5;
        int media = *(ptr + 2); 

        cout << "\n--- RESULTADOS ---" << endl;
        cout << "Suma: " << suma << endl;
        cout << "Promedio: " << promedio << endl;
        cout << "Media (dato central): " << media << endl;
        cout << "Maximo: " << maximo << endl;
        cout << "Minimo: " << minimo << endl;
    }
};

int main() {
    CalculadoraEstadistica calc;
    calc.procesarDatos();
    
    return 0;
}