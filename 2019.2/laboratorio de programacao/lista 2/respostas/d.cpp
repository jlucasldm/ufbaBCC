#include<iostream>
#include<map>
#include<iomanip>
using namespace std;

double percent(double parcial, double total){
    return (parcial*100/total);
}

int main(){
    double count = 0;
    string name;
    map<string, double> pokemonqntd;
    map<string, double>::iterator it;
    cout<<fixed<<setprecision(2);    

    while(1==1){
        cin>>name;
        if(name=="FIM"){
            break;
        }
        pokemonqntd[name]+=1;
        count++;
    }

    for(it = pokemonqntd.begin(); it != pokemonqntd.end(); it++){
        pokemonqntd[it->first]=percent(pokemonqntd[it->first], count);
    }

    for(it = pokemonqntd.begin(); it != pokemonqntd.end(); it++){
        cout<<it->first<<' '<<it->second<<endl;
    }
    cout<<endl;

    return 0;
}