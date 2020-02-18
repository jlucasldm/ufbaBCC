#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main()
{
    int n;
    int m;
    int e;
    int a;
    set<int> pokedex;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> e;
        pokedex.insert(e);
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a;
        if (pokedex.count(a))
        {
            cout << "Repetido\n";
        }
        else
        {
            cout << "Temos que pegar!\n";
            pokedex.insert(a);
        }
    }
    return 0;
}