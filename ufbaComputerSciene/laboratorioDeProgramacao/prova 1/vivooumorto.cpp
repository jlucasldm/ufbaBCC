#include <iostream>
#include <set>
#include <string>
using namespace std;

int main(){
	int n, mortos;
	string aux;

	set<string> cnjt_vivos, cnjt_mortos;
	set<string>:: iterator it;

	cin >> n;
	cin.ignore();
	for(int i = 0; i < n; i++){
		getline(cin, aux);
		cnjt_vivos.insert(aux);
	}

	cin >> mortos;
	cin.ignore();
	for(int i = 0; i < mortos; i++){
		getline(cin, aux);
		cnjt_mortos.insert(aux);
	}

	for(it = cnjt_mortos.begin(); it != cnjt_mortos.end(); it++){
		cnjt_vivos.erase(*it);
	}

	for(it = cnjt_vivos.begin(); it != cnjt_vivos.end(); it++){
	  cout << *it << endl;
	}

	for(it = cnjt_mortos.begin(); it != cnjt_mortos.end(); it++){
	  cout << *it << endl;
	}
	return 0;
}