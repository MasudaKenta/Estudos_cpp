#include <bits/stdc++.h>
using namespace std;

map<string, vector<string>> organograma;

void listarSetores(const string& setor){
    if(organograma.find(setor)!=organograma.end()){
        sort(organograma[setor].begin(), organograma[setor].end());     //ordenar os setores relativos ao setor pai em questão

        for(const string& s : organograma[setor]){
            cout << s << endl;

            listarSetores(s);                                           //recursividade para listar setores subordinados
        }
    }

}

int main(){
    string a,b, pai, setor;
    cin >> pai;

    while(cin >> a >> b && a!="fim"){
        organograma[b].push_back(a);
    }

    cin >> setor;
    cout << setor << endl;
    listarSetores(setor);
    return 0;
}
