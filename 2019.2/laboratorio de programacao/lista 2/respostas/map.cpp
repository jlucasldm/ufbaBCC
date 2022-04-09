#include <iostream>
#include <map>
using namespace std;

int main(){
    string chave;
    int v;

    map<string, int> m;
    for(int i = 0; i < 10; i++){
        cin >> chave >> v;
        m[chave] = v;
        m[chave] += v;
        m[chave]++;
    }

    map<string, int>:: iterator it = m.begin();
    for(it = m.begin(); it != m.end(); it++){
        cout << it->first << endl;
        cout << it-> second << endl;
    }
    it = m.find(chave);
    if(it != m.end()) m.erase(it);
    m.clear();

    return 0;
}

//Cada chave tem apenas um valor, se repetir, ele vai trocar
//Ele não procura um elemento, se procurar ele cria uma nova chave - count no set
//Insere chaves ordenadas
//Não tem chaves repetidas