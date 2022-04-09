#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int main(){
    priority_queue<pair<int, string>> pq;
    pair<int, string> aux;
    int dias, atendimentos, clientes;

    cin>>dias>>atendimentos;
    for(int i=0; i<dias; i++){
        cin>>clientes;
        for(int j=0; j<clientes; j++){
            cin>>aux.second>>aux.first;
            pq.push(aux);
        }
        for(int k=0; k<atendimentos; k++){
            aux=pq.top();
            cout<<aux.second<<endl;
            pq.pop();
        }
    }

    cout<<endl;

    return 0;
}