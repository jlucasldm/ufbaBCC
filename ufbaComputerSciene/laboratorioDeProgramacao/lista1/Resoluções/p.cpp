#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    string s;
    char aux;
    cin >> s;
    stack<char> pilha;
    for (int i = 0; i < s.size(); i++)
    {
        aux = s[i];
        if ((aux == ')' && pilha.top() == '(') || (aux == '}' && pilha.top() == '{') || (aux == ']' && pilha.top() == '['))
        {
            pilha.pop();
        }
        else
        {
            pilha.push(aux);
        }
    }
    if (pilha.empty())
    {
        cout << "SIM";
    }
    if (!pilha.empty())
    {
        cout << "NAO";
    }
    return 0;
}
