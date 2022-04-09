#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(int a, int b){
    return(a < b);
}

int main(){
    vector<int> vet;
    vector<int> resp;
    int n, q, nota, consulta, aux;

    cin>>n>>q;
    for(int i = 0; i < n; i++){
        cin>>aux;
        vet.push_back(aux);
    }

    stable_sort(vet.begin(), vet.end(), cmp);

    cin>>consulta;
    for(int i = 0; i < consulta; i++){
        cin>>nota;
        bool r = binary_search(vet.begin()+n-q, vet.end(), nota);

        if(r) cout << "Sim" << endl;
        else cout << "Nao" << endl;
    }

    
    cout<<endl;
    return 0;
}