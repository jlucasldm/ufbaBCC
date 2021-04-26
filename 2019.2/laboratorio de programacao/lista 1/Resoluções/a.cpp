#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
  int n;
  int c;
  int aux = -1;
  cin>>n;
  vector<int> esmeraldas(n);
  for(int i=0; i<esmeraldas.size(); i++){
      cin>>esmeraldas[i];
    }
  cin>>c;
  for(int i=0; i<esmeraldas.size(); i++){
      if(c == esmeraldas[i]){
        aux=c;
        break;
      }
  }
    cout<<aux<<endl;
  return 0;
}