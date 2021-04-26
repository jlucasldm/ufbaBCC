#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int e;
    int n;
    int m;
    int pont = 0;
    int teto = 0;
    cin >> n >> m;
    stack<int> tetris;
    for (int i = 0; i < n; i++)
    {
        cin >> e;
        if (tetris.empty())
        {
            tetris.push(e);
            teto++;
        }
        else if (e + tetris.top() == 111)
        {
            tetris.pop();
            pont += 10;
            teto--;
        }
        else if (e + tetris.top() != 111)
        {
            tetris.push(e);
            teto++;
        }
        if (teto == m)
        {
            break;
        }
    }
    if (teto == m)
    {
        cout << "game over";
    }
    else
    {
        cout << pont;
    }
    return 0;
}
