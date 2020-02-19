#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
  int n;
  cin>>n;
  cin.ignore();
  vector<string> times(n);
  int aux = 0;

  for(int i=0; i<times.size(); i++){
      getline(cin,times[i]);
  }

  for(int i=0; i<(n/2); i++){
    cout<<*times.begin()<<" X "<<*(times.end()-1)<<endl;
    times.erase(times.begin());
    times.erase(times.end());
  }
  return 0;
}