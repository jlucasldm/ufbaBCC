#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int n, m, e;
    cin >> n >> m;
    queue<int> fila;
    for (int i = 0; i < n; i++)
    {
        cin >> e;
        fila.push(e);
    }
    for (int i = 0; i < m; i++)
    {
        fila.front()--;
        if (fila.front() != 0 && !fila.empty())
        {
            int x;
            x = fila.front();
            fila.push(x);
        }
        if (!fila.empty())
        {
            fila.pop();
        }
    }

    if (fila.empty())
    {
        cout << "pronto";
    }
    else
    {
        int p = fila.size();
        cout << p << endl;
        while (!fila.empty())
        {
            cout << fila.front() << " ";
            fila.pop();
        }
    }

    return 0;
}
