#include <iostream>
#include <string>

using namespace std;

struct Auto {
    float precio;
    int anio;
};

struct PersonaPE {
    string nombre, ap, am;
    char genero;
    int edad;
    Auto coche;
};

class PersonaPOO {
private:
    string nombre, ap, am;
    char genero;
    int edad;
public:
    Auto coche;

    void setDatos(string n, string p_ap, string p_am, char g, int e, float pr, int a) {
        nombre = n; ap = p_ap; am = p_am; genero = g; edad = e;
        coche.precio = pr; coche.anio = a;
    }

    void mostrar() {
        cout << "POO -> " << nombre << " " << ap << " | Auto: $" << coche.precio << " (" << coche.anio << ")" << endl;
    }
};

int main() {
    PersonaPE listaPE[1];
    PersonaPE* ptrPE = listaPE;

    cout << "--- INGRESO DATOS PE ---" << endl;
    cout << "Nombre: "; cin >> (ptrPE + 0)->nombre;
    cout << "Apellido Paterno: "; cin >> (ptrPE + 0)->ap;
    cout << "Precio Auto: "; cin >> (ptrPE + 0)->coche.precio;
    cout << "Anio Auto: "; cin >> (ptrPE + 0)->coche.anio;

    PersonaPOO listaPOO[1];
    PersonaPOO* ptrPOO = listaPOO;

    cout << "\n--- INGRESO DATOS POO ---" << endl;
    string n, ap, am; char g; int e, an; float pr;
    cout << "Nombre: "; cin >> n;
    cout << "Apellido Paterno: "; cin >> ap;
    cout << "Apellido Materno: "; cin >> am;
    cout << "Genero (M/F): "; cin >> g;
    cout << "Edad: "; cin >> e;
    cout << "Precio Auto: "; cin >> pr;
    cout << "Anio Auto: "; cin >> an;

    (ptrPOO + 0)->setDatos(n, ap, am, g, e, pr, an);

    cout << "\n--- RESULTADOS ENTREGA ---" << endl;
    cout << "PE  -> " << (ptrPE + 0)->nombre << " " << (ptrPE + 0)->ap << " | Auto: $" << (ptrPE + 0)->coche.precio << endl;
    (ptrPOO + 0)->mostrar();

    return 0;
}