#include<iostream>
#include<map>
using namespace std;

int main(){
    int n;
    int qnt;
    string chave;
    map<string, int> m;
    
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>chave>>qnt;
        m[chave]+=qnt;
    }

    for(map<string, int>::iterator it = m.begin(); it != m.end(); it++){
        cout<<(*it).first<<' '<<(*it).second<<endl;
    }
    return 0;
}