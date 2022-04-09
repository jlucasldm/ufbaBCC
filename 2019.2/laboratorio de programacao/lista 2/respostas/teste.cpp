#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int main(){
    priority_queue<int, vector<int>, greater<int>> pq;
    int tempo, pmin, n, aux;

    cin>>tempo>>pmin;
    for(int i=0; i<tempo; i++){
        cin>>n;
        for(int j=0; j<n; j++){
            cin>>aux;
            pq.push(aux);
        }
        for(int k=0; k<pmin; k++){
            cout<<pq.top()<<endl;
            pq.pop();
        }
    }

    return 0;
}