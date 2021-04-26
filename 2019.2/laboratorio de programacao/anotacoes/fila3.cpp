#include<iostream>
#include<queue>
using namespace std;


struct pos{
  int s;
  string nome;
}


int main(){
  int n;
  queue<pos> fila;
  pos aux;
  while(cin>>aux.s>>aux.nome)
    fila.push(aux);
  while(!fila.empty()){
    cout<<fila.front().s<<endl;
    fila.pop();
  }

}
