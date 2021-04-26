#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int main(){
    priority_queue<int> grif;
    priority_queue<int, vector<int>, greater<int>> sonsCres;
    int n, g, s, m, aux;

    cin>>n;
    for(int j=0; j<n; j++){
        cin>>g>>s;
        for(int i=0; i<g; i++){
            cin>>aux;
            grif.push(aux);
        }

        for(int i=0; i<s; i++){
            cin>>aux;
            sonsCres.push(aux);
        }
        cin>>m;
        for(int i=0; i<m && !(grif.empty() || sonsCres.empty()); i++){
            cout<<grif.top()<<' '<<sonsCres.top()<<endl;
            grif.pop();
            sonsCres.pop();
        }
    }

    cout<<endl;

    return 0;
}