#include<iostream>
#include<queue>
using namespace std;

int main(){
  int n;
  queue<int> fila;
  while(cin>>n)
    fila.push(n);
  while(!fila.empty()){
    cout<<fila.front()<<endl;
    fila.pop();
  }

}
