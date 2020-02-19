#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(){
    vector<int> vet;
    vector<int> resp;
    int n, m, dimensoes, disponiveis, count=0;

    cin>>n>>m;
    for(int i = 0; i < n; i++){
        cin>>disponiveis;
        vet.push_back(disponiveis);
    }

    for(int i=0; i<m; i++){
        cin>>dimensoes;
        bool r = binary_search(vet.begin(), vet.end(), dimensoes);
        if(r){
            count++;
        }
    }

    cout<<count<<endl;
    
    return 0;
}