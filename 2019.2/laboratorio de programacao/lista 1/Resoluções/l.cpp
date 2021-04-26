#include <iostream>
#include <queue>
using namespace std;

struct pessoa
{
    int id;    //identificador da pessoa
    int money; //dinheiros que ela tem
};

int main()
{
    int n; //pessoas no parque
    int m; //tempo decorrido
    int x; //valor do ingresso

    cin >> n >> m >> x;
    queue<pessoa> lista;
    pessoa aux;
    for (int i = 0; i < n; i++)
    {
        cin >> aux.id >> aux.money;
        if (aux.money >= x)
        {
            lista.push(aux);
        }
    }
    for (int i = 0; i < m; i++)
    {
        lista.front().money -= x;
        if (lista.front().money >= x)
        {
            lista.push(lista.front());
        }
        lista.pop();
    }
    if (lista.empty())
    {
        cout << "SEM FILA";
    }
    else
    {
        while (!lista.empty())
        {
            cout << lista.front().id << " " << lista.front().money << "\n";
            lista.pop();
        }
    }

    return 0;
}
