#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
	int vetor[50], n, num;
	vector<int> vet(50);
	while(cin>>num){
		vet.push_back(num); //cria espaços adicionais no "fundo" do vetor
	}
	for(int i=0; i<vet.size(); i++){
		cout<<vet[i]<<endl;
  }
  sort(vet.begin(), vet.end()); //ordena crescentemente no intervalo (x,y)
  //     sort(vet.rbegin(), vet.rend()); ordena decrescentemente
  //<==> reverse(vet.begin(), vet.end());

}
