#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main(){
  string s;
  char aux;
  cin>>s;
  stack<char> expressao;
  for(int i=0; i<s.size()-1; i++){
    expressao.push(s[i]);
    aux=expressao.top();
    expressao.pop();
    if((expressao.top()=='{' && aux=='}') || (expressao.top()=='(' && aux==')') || (expressao.top()=='[' && aux==']')){
      if(!expressao.empty()){
        expressao.pop();
      }
    }else{
      expressao.push(aux);
    }
  }
  if(expressao.empty())
    cout<<"SIM";
  else
    cout<<"NAO";
  return 0;
}
