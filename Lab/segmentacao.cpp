#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
    //
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0); 
    //

    set<pair<long long int, long long int>> seg;
    set<pair<long long int, long long int>>::iterator it; 
    set<pair<long long int, long long int>>::iterator ant;
    set<pair<long long int, long long int>>::iterator prox;
    pair<long long int, long long int> ocupacao;
    long long int n;
    long long int count = 0;
    int aux;
    char c;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> c >> ocupacao.first >> ocupacao.second;
        if (c == 'E'){
            it = seg.insert(ocupacao).first;
            aux = 0;
            if (it != seg.begin()){
                ant = it;
                ant--;
                if (ant->second == ocupacao.first - 1){
                    aux++;
                }
            }
            prox = it;
            prox++;
            if (prox != seg.end()){
                if (prox->first == ocupacao.second + 1){
                    aux++;
                }
            }
            if (aux == 0){
                count++;
            }
            else if (aux == 2){
                count--;
            }
        }
        else
        {
            it = seg.find(ocupacao);
            int aux = 0;

            if (it != seg.begin())
            {
                ant = it;
                ant--;
                if (ant->second == ocupacao.first - 1)
                    aux++;
            }
            prox = it;
            prox++;
            if (prox != seg.end())
            {
                if (prox->first == ocupacao.second + 1)
                    aux++;
            }

            if (aux == 0)
                count--;
            else if (aux == 2)
                count++;

            seg.erase(ocupacao);
        }
        cout << count << endl;
    }
    return 0;
}