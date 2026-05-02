#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Dato { int val; };

class OrdenadorMerge {
public:
    void ordenar() {
        vector<int> nums = {40, 10, 30, 20};
        vector<char> chars = {'z', 'm', 'a', 'f'};
        vector<Dato> datos = {{100}, {10}, {50}, {20}};
        int n = nums.size();

        for (int tam = 1; tam < n; tam *= 2) {
            for (int izq = 0; izq < n - 1; izq += 2 * tam) {
                int medio = min(izq + tam - 1, n - 1);
                int der = min(izq + 2 * tam - 1, n - 1);
                
                inplace_merge(nums.begin() + izq, nums.begin() + medio + 1, nums.begin() + der + 1);
                inplace_merge(chars.begin() + izq, chars.begin() + medio + 1, chars.begin() + der + 1);
                
                auto comp = [](Dato a, Dato b) { return a.val < b.val; };
                inplace_merge(datos.begin() + izq, datos.begin() + medio + 1, datos.begin() + der + 1, comp);
            }
        }

        cout << "Merge: " << nums[0] << ", " << chars[0] << ", " << datos[0].val << endl;
    }
};

int main() {
    OrdenadorMerge om;
    om.ordenar();
    return 0;
}
