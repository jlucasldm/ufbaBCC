#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int n;
    int x;
    int aux = 0;
    cin >> n;
    stack<int> pilha;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        if (x == -1 && !pilha.empty())
        {
            pilha.pop();
        }
        else if (x != -1)
            pilha.push(x);
    }
    if (pilha.empty())
    {
        cout << 0;
    }
    else
    {
        while (!pilha.empty())
        {
            aux += pilha.top();
            pilha.pop();
        }
        cout << aux;
    }
    return 0;
}