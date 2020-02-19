#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
  int n;
  int aux = 0;
  cin >> n;
  vector<int> vet(n);
  for(int i=0; i<vet.size(); i++){
    cin >> vet[i];
  }
  sort(vet.begin(), vet.end());
  for(int i=0; i<(vet.size())-1; i++){
    aux+=(vet[i+1])-vet[i]-1;
  }
  cout << aux << endl;
  return 0;
}
