#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef struct dma dma;
struct dma{
	int dia;
    int mes;
    int ano;
};

bool cmp (dma a, dma b){
	return (a.ano > b.ano || (a.ano == b.ano && a.mes > b.mes) || (a.ano == b.ano && a.mes == b.mes && a.dia > b.dia));
}

int main(){
	vector<dma> vetor;
	dma aux;

	while(cin >> aux.dia >> aux.mes >> aux.ano){
		 vetor.push_back(aux);
	}

	sort(vetor.begin(), vetor.end(), cmp);
	reverse(vetor.begin(), vetor.end());

	for(int i = 0; i < vetor.size(); i++){
		cout << vetor[i].dia << ' ' << vetor[i].mes << ' ' << vetor[i].ano << endl;
	}

	return 0;
}