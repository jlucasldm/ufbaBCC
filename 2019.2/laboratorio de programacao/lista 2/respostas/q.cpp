#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    vector<int> ordem;
    vector<int>::iterator it;
    vector<int> resp;
    int n, m, aux, q, count = 0;

    cin>>n>>m; //larguraXcomprimento da foto original
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin>>aux; //altura de cada parte da cidade no momento 0
            ordem.push_back(aux);
        }
    }

    sort(ordem.begin(), ordem.end());

    cin>>q; //numero de consultas
    for(int i = 0; i < q; i++){
        cin>>aux; //horas passadas
        it = upper_bound(ordem.begin(), ordem.end(), aux);  //aponta pra o indice, que é o endereço de memoria
        resp.push_back(abs(it-ordem.begin()));              //ordem.begin() tambem se trata do índice, que é o endereço de memoria
    }

    for(int i=0; i<resp.size(); i++){
        cout<<resp[i]<<endl;
    }
        
    return 0;
}