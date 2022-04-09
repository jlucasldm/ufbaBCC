#include<iostream>
#include<stack>
using namespace std;

int main(){
  int n;
  stack<int> pilha;
  while(cin>>n)
    pilha.push(n);
  while(!pilha.empty()){
    cout<<pilha.top()<<endl;
    pilha.pop();
  }

}
