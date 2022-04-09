#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct dbz
{
    string war;
    int pwr;
};

bool forca(dbz a, dbz b)
{
    return (a.pwr > b.pwr);
};

int main()
{
    int j, k;
    cin >> j >> k;
    vector<dbz> tabela;
    //k == vencedores
    //j == guerreiros lutando
    dbz aux;
    for (int i = 0; i < j; i++)
    {
        cin >> aux.war >> aux.pwr;
        tabela.push_back(aux);
    }
    sort(tabela.begin(), tabela.end(), forca);
    for (int i = 0; i < k; i++)
    {
        cout << tabela[i].war << " " << tabela[i].pwr << endl;
    }
    return 0;
}
