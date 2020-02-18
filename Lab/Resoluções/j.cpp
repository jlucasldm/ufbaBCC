#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int m;     //onstros na fila de cartas
    int r;     //odadas
    int d = 0; //dead
    int e;     //entrada auxiliar

    queue<int> poder;
    queue<int> advrs;

    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> e;
        poder.push(e);
    }
    cin >> r;
    for (int i = 0; i < r; i++)
    {
        cin >> e;
        advrs.push(e);
    }

    for (int i = 0; i < r; i++)
    {
        if (poder.front() < advrs.front() && !poder.empty())
        {
            d++;
            poder.pop();
        }
        else if (!poder.empty())
        {
            int x;
            x = poder.front();
            poder.push(x);
            poder.pop();
        }
        advrs.pop();
    }

    cout << d << endl;

    return 0;
}
