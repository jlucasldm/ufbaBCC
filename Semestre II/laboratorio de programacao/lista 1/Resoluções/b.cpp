#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
  int n;
  cin>>n;
  vector<int> u(n);
  vector<int> v(n);
  vector<int> d(n);
  int aux = 0;

  for(int i=0; i<u.size(); i++){
      cin>>u[i];
  }
  for(int i=0; i<v.size(); i++){
      cin>>v[i];
  }
  for(int i=0; i<d.size(); i++){
      cin>>d[i];
  }

  for(int i=0; i<u.size(); i++){
    if((u[i]+v[i])==d[i]){
      aux += 1;
    }
  }

  if(aux==n){
    cout<<"OK"<<endl;
  }
  if(aux!=n){
    cout<<"NOPE :("<<endl;
  }
  return 0;
}
