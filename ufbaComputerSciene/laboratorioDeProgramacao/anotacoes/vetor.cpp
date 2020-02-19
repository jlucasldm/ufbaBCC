#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct carro{
  int id;
  int t;
};

bool cmp(carro a, carro b){
  return(a.t < b.t || a.t == b.t && a.id < b.id)
};

int main(){
      vector<carro>carros(10);
      carro aux;
      while(cin>>aux.t>>aux.id){
        carros.push_back(aux);
      }
      sort(carros.begin(), carros.end(), cmp);
}
