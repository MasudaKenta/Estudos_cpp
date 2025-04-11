#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios::sync_with_stdio(0);cin.tie(0);

using namespace std;

const int INF = 0x3f3f3f3f;
int n, m, q;

typedef pair<int,int> Edge;
typedef vector<vector<Edge>> Graph;

vector<int> dijkstra(Graph &g, vector<int> hosp){
    priority_queue<Edge> pq;

    for(int amb : hosp)
        pq.push({-0, amb-1});

    vector<int> dist(n, INF);

    while(!pq.empty()){
        int w = -pq.top().f;
        int u = pq.top().s;

        pq.pop();

        if(dist[u] <= w)
            continue;

        dist[u] = w;
        for(auto [v, n_w] : g[u]){
            if(dist[v] > w+n_w){
                pq.push({-(w+n_w), v});
            }
        }
    }
    return dist;
}

void add_edge(Graph &g, int a, int b, int w){
    a--;
    b--;
    g[a].push_back({b,w});
    g[b].push_back({a,w});
}

void solve(){
    Graph grp = Graph(n, vector<Edge>());

    for(int i=0;i<m;i++){
        int a,b,w;
        cin >> a >> b >> w;
        add_edge(grp, a, b, w);
    }

    vector<int> hosp(q);
    for(int &i : hosp)
        cin >> i;

    vector<int> dist = dijkstra(grp, hosp);

    int ans = -1;
    for(int d : dist)
        ans = max(ans, d);
    cout << ans << endl;
}

int main(){_
    while(cin >> n >> m >>q);
        solve();

    return 0;
}
