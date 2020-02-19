#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int, char> a, pair<int, char> b){
    return(a.first < b.first);
}

int main(){
    vector<pair<int, char>> vet;
    vector<pair <int, char>>::iterator r;
    pair<int, char> aux;
    vector<char> resp;
    int l, a;
    char c = '0';

    cin>>l;
    for(int i = 0; i < l; i++){
        cin>>aux.first>>aux.second;
        vet.push_back(aux);
    }

    cin>>a;
    for(int i = 0; i < a; i++){
        cin>>aux.first;
        r = lower_bound(vet.begin(), vet.end(), aux, cmp);
        cout<<r->first;
        if((*r).first==aux.first){
            resp.push_back((*r).second);
        }else{
            resp.push_back(c);
        }
    }

    for(int i=0; i<resp.size(); i++){
        if(resp[i]=='0'){
            cout<<"Ausente"<<endl;
        }else{
            cout<<resp[i]<<endl;
        }
    }
        
    return 0;
}