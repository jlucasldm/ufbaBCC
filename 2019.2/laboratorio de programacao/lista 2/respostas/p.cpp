#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    vector<int> casas;
    vector<int> ordem;
    vector<int>::iterator presente;
    int n, m, aux, count = 0;

    cin>>n>>m;
    for(int i = 0; i < n; i++){
        cin>>aux;
        casas.push_back(aux);
    }

    for(int i = 0; i < m; i++){
        cin>>aux;
        ordem.push_back(aux);
    }

    presente=casas.begin();
    for(int i = 0; i < m; i++){
        vector<int>::iterator it = lower_bound(casas.begin(), casas.end(), ordem[i]);
        count+=abs(it-presente);
        presente=it;
    }
    cout<<count<<endl;
        
    return 0;
}