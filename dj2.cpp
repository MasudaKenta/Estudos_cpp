#include <bits/stdc++.h>
using namespace std;

int main(){
    map<int,int> anterior;

    int n, m;
    cin >> n >> m; //n vertices e m arestas
    //typedef pair<int, int> edge; // vertice, peso

    /*
        G[i] = vertice inicial
        G[i][j] = arestas do vertice i
        G[i][j].fisrt = vertice de destino da aresta (i, G[i][j].fisrt)
        G[i][j].second = peso da aresta (i, G[i][j].fisrt)
    */
    vector<vector<pair<int, int>>> G(n);

    for(int i = 0; i < m; i++){
        int v, u, w; //vertice v, vertice u, peso w da aresta (v, u)
        cin >> v >> u >> w;
        v--; u--;
        //inserção bidirecional dos nós
        G[v].push_back({u, w}); //inserção na matriz de adjacência - ida
        G[u].push_back({v, w}); //inserção na matriz de adjacência - volta
    }

    int origem, destino;
    cin >> origem >> destino;

    priority_queue<pair<int, int>> dj; //vertices abertos na forma (vertice adjacente, custo)


    /*
    estimativa de menor caminho na forma [v, w],
    v = vertice anterior
    w = menor distancia ate o menor[i]
    */
    vector<int> menor(n, INT_MAX);  //Resultado do Djikstra

    //menor[0].first = 0; //vertice de inicio
    //menor[0].second = 0; //peso do vertice de inicio
    menor[origem-1] = 0;
    anterior[0] = 0;

    dj.push({origem-1, -0}); //abre o vertice 0


    //enquanto houver vertices abertos
    while(dj.size() > 0){

        //escolha aquele vertice com o menor estimativa
        // *No caso, sera o topo da priority_queue
        int v = dj.top().first;
        int w = -dj.top().second;

        dj.pop(); //fecha o vertice, retirando-o da lista de vertices abertos (ja foi visitado)


        if(w != menor[v]) continue; //para grafos grandes, compensa tempo

        for(auto aresta : G[v]){ //enquanto houver vertice aberto na adjacencia de v, relaxe a aresta (v, u)
            int u = aresta.first;
            int cost = aresta.second;

            if(menor[u] > menor[v] + cost){
                menor[u] = menor[v] + cost;
                anterior[u] = v;
                dj.push({u, -menor[u]});
            }
        }
    }

    cout << menor[destino-1] << endl;


    /*
    vector<int> viagem;
    int destino;
    cin >> destino;
    viagem.push_back(destino);

    //cout << destino << " <- ";

    destino--;

    while(true){
        int sla = anterior[destino];
        if(sla!=0){
            viagem.push_back(sla+1);
            //cout << sla+1 << " <- ";
        }

        destino = sla;

        if(destino==0){
            viagem.push_back(destino+1);
            //cout << destino + 1 << endl;
            break;
        }
    }

    for(int i=viagem.size()-1;i>=0;i--){
        cout << viagem[i];
        if(i!=0)
            cout << " -> ";
    }
    cout << "\n";
    */




    return 0;
}




