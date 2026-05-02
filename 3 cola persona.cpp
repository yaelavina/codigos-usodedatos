#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

struct Persona { string nombre; int id; };

class ColaSistema {
    queue<Persona> q;
public:
    void agregar() {
        Persona p;
        cout << "Nombre: "; cin >> p.nombre;
        cout << "ID: "; cin >> p.id;
        q.push(p);
    }

    void ordenar() {
        if(q.empty()) return;
        vector<Persona> v;
        while(!q.empty()) { v.push_back(q.front()); q.pop(); }

        stack<pair<int,int>> limites;
        limites.push({0, (int)v.size()-1});
        while(!limites.empty()) {
            int ini = limites.top().first, fin = limites.top().second;
            limites.pop();
            if(ini >= fin) continue;
            
            int pivot = v[fin].id, i = ini - 1;
            for(int j=ini; j<fin; j++)
                if(v[j].id < pivot) swap(v[++i], v[j]);
            swap(v[i+1], v[fin]);
            
            limites.push({ini, i});
            limites.push({i+2, fin});
        }
        for(auto &p : v) q.push(p);
    }

    void mostrar() {
        queue<Persona> copia = q;
        while(!copia.empty()) {
            cout << "{" << copia.front().nombre << ":" << copia.front().id << "} ";
            copia.pop();
        }
        cout << endl;
    }
};

int main() {
    ColaSistema c; int op;
    do {
        cout << "\n1.Agregar 2.Ordenar 3.Mostrar 4.Salir: "; cin >> op;
        if(op==1) c.agregar(); else if(op==2) c.ordenar(); else if(op==3) c.mostrar();
    } while(op != 4);
    return 0;
}