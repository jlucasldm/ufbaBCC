#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int main(){
    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;
    pair<int, string> aux;
    int n, m, xp;

    cin>>n;
    for(int i=0; i<n; i++){
        cin>>aux.second>>aux.first;
        pq.push(aux);
    }

    cin>>m;
    for(int i=0; i<m; i++){
        cin>>xp;
        aux=pq.top();
        pq.pop();
        aux.first+=xp;
        pq.push(aux);
    }

    while(pq.empty()!=1){
        aux=pq.top();
        cout<<aux.second<<' '<<aux.first<<endl;
        pq.pop();
    }

    cout<<endl;

    return 0;
}