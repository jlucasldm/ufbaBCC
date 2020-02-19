#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<string, int> a, pair<string, int> b){
    return(a.first < b.first);
}

int main(){
    vector<pair<string, int>> vet;
    pair<string, int> aux;
    int n, p, count = 0;

    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>aux.first>>aux.second;
        vet.push_back(aux);
    }

    cin>>p;
    for(int i = 0; i < p; i++){
        cin>>aux.first;
        vector<pair <string, int>>::iterator r = lower_bound(vet.begin(), vet.end(), aux, cmp);

        count+=(*r).second;
    }

    cout<<count<<endl;
        
    return 0;
}