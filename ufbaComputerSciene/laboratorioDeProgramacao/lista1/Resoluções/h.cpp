#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct riquiMorde
{
    string nome;
    int valor;
};

bool forca(riquiMorde a, riquiMorde b)
{
    return (a.nome < b.nome || (a.nome == b.nome && a.valor > b.valor));
};

int main()
{
    int p;
    cin >> p;
    vector<riquiMorde> treco;
    riquiMorde aux;
    for (int i = 0; i < p; i++)
    {
        cin >> aux.nome >> aux.valor;
        treco.push_back(aux);
    }
    sort(treco.begin(), treco.end(), forca);
    for (int i = 0; i < p; i++)
    {
        cout << treco[i].nome << " " << treco[i].valor << endl;
    }
    return 0;
}