#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int main(){
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> resp;
    int tempo, pmin, n, aux;

    cin>>tempo>>pmin;
    for(int i=0; i<tempo; i++){
        cin>>n;
        for(int j=0; j<n; j++){
            cin>>aux;
            pq.push(aux);
        }
        for(int k=0; k<pmin; k++){
            if(pq.empty()!=1){
                resp.push_back(pq.top());
                pq.pop();
            }
        }
    }

    for(int i=0; i<resp.size(); i++){
        cout<<resp[i]<<' ';
    }
    cout<<endl;
    
    return 0;
}