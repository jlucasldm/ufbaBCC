#include<iostream>
#include<map>
using namespace std;

int main(){
    int n;
    int m;
    string gringa;
    string nativa;
    string word;
    map<string, string> mapa;
    map<string, string>::iterator it;
    
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>gringa>>nativa;
            mapa[gringa]=nativa;
    }

    cin>>m;
    string frase[m] = {};
    for(int i=0; i<m; i++){
        cin>>word;
        
        it = mapa.find(word);
        if(it==mapa.end()){
            frase[i] = word;
        }else{
            frase[i] = it->second;
        }
    }

    for(int i=0; i<m; i++){
        cout<<frase[i]<<' ';
    }
    cout<<endl;
    return 0;
}