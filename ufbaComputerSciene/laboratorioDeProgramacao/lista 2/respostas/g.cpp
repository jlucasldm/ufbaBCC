#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int main(){
    priority_queue<int> pq;
    int n, g, aux;

    cin>>n;
    for(int i=0; i<n; i++){
        cin>>g;
        for(int j=0; j<g; j++){
            cin>>aux;
            pq.push(aux);
        }
        cout<<pq.top()<<endl;
        pq.pop();
    }

    return 0;
}