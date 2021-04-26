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
    aux=fila.front();
    if(aux.s%2==0)
      fila.pop();
    else{
      aux.s=aux.s-1
      fila.push(aux);
    }
  }

}
