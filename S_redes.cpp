#include <bits/stdc++.h>
using namespace std;

vector<tuple<int,int,int>> g;
vector<int> id, sz;

int Find(int x){
    return id[x] = (id[x]==x ? x: Find(id[x]));
}

void Union(int x, int y){
    x = Find(x), y = Find(y);
    if(x == y) return;
    if(sz[x]>sz[y]) swap(x,y);
    id[x] = y;
    sz[y] += sz[x];
}

int main(){
    int n,m; cin >> n >> m;

    id = vector<int> (n);
    sz = vector<int> (n,1);
    iota(id.begin(), id.end(), 0);
    while(m--){
        int a,b,w;
        cin >> a >> b >> w;
        a--;
        b--;
        g.push_back(make_tuple(w,a,b));
    }
    sort(g.begin(), g.end());
    int custo = 0;

    for(auto [w,a,b] : g){
        if(Find(a) != Find(b)){
            Union(a,b);
            custo+=w;
        }
    }

    cout << custo << endl;
    return 0;
}
