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
	vector<int>::iterator it;
	for(it=vet.begin(); it!=vet.end(); it++){
		cout<<*it<<endl;
	}
	vet.clear();
	vet.erase(vet.begin()+2, vet.end());
}
