#include<iostream>
#include<map>
#include<vector>
using namespace std;


int main(){
    int n, m;
    char fonte, destino;
    int qntd;
    string a, b, word;
    map<string, string> tradAB;
    map<string, string> tradBA;
    map<string, string>::iterator it;
    vector<string> frase;

    cin>>n>>m;
    for(int i=0; i<n; i++){
        cin>>a>>b;
        tradAB[a]=b;
        tradBA[b]=a;
    }

    for(int i=0; i<m; i++){
        cin>>fonte>>destino>>qntd;
        string word;

        for(int j=0; j<qntd; j++){
            cin>>word;
            if(fonte=='A' && destino=='B'){
                it = tradAB.find(word);
                if(it!=tradAB.end()){
                    frase.push_back(it->second);
                }else{
                    frase.push_back(word);
                }
            }else if(fonte=='B' && destino=='A'){
                it = tradBA.find(word);
                if(it!=tradBA.end()){
                    frase.push_back(it->second);
                }else{
                    frase.push_back(word);
                }
            }else{
                frase.push_back(word);
            }
        }
    }

    for(int j=0; j<frase.size(); j++){
            cout<<frase[j]<<' ';
        }
        cout<<endl;

    return 0;
}