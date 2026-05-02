#include <iostream>
#include <queue>
#include <vector>
#include <stack>
using namespace std;

class ColaSTL {
    queue<int> q;
public:
    void add() { int v; cin >> v; q.push(v); }
    void ordenar() { // QuickSort Iterativo
        vector<int> v;
        while(!q.empty()){ v.push_back(q.front()); q.pop(); }
        stack<pair<int,int>> st; st.push({0, (int)v.size()-1});
        while(!st.empty()){
            int l=st.top().first, h=st.top().second; st.pop();
            if(l>=h) continue;
            int p=v[h], i=l-1;
            for(int j=l; j<h; j++) if(v[j]<p) swap(v[++i], v[j]);
            swap(v[i+1], v[h]);
            st.push({l, i}); st.push({i+2, h});
        }
        for(int x : v) q.push(x);
    }
    void ver() { queue<int> c=q; while(!c.empty()){ cout<<c.front()<<" "; c.pop(); } }
};

int main() {
    ColaSTL c; int op;
    do { cin >> op; if(op==1) c.add(); if(op==2) c.ordenar(); if(op==3) c.ver(); } while(op!=4);
    return 0;
}