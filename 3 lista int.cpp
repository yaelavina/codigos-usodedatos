#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class ListaSTL {
    vector<int> v;
public:
    void add() { int x; cin >> x; v.push_back(x); }
    void ordenar() { // MergeSort Iterativo
        int n = v.size();
        for (int m=1; m < n; m *= 2) {
            for (int l=0; l < n-1; l += 2*m) {
                int mid=min(l+m-1, n-1), r=min(l+2*m-1, n-1);
                inplace_merge(v.begin()+l, v.begin()+mid+1, v.begin()+r+1);
            }
        }
    }
    void ver() { for(int x : v) cout << x << " "; }
};

int main() {
    ListaSTL l; int op;
    do { cin >> op; if(op==1) l.add(); if(op==2) l.ordenar(); if(op==3) l.ver(); } while(op!=4);
    return 0;
}