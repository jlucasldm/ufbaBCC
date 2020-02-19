#include <iostream>
#include <queue>
using namespace std;

struct nego
{
    string nome;
    char sexo;
};

int main()
{
    int t;
    nego e;

    queue<nego> femea;
    queue<nego> macho;
    queue<nego> ajuste;

    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> e.nome >> e.sexo;
        femea.push(e);
    }
    for (int i = 0; i < t; i++)
    {
        cin >> e.nome >> e.sexo;
        macho.push(e);
    }
    for (int i = 0; i < t; i++)
    {
        if (femea.front().sexo == 'H')
        {
            ajuste.push(femea.front());
            femea.pop();
        }
        else
        {
            femea.push(femea.front());
            femea.pop();
        }
    }
    for (int i = 0; i < t; i++)
    {
        if (macho.front().sexo == 'M')
        {
            ajuste.push(macho.front());
            macho.pop();
        }
        else
        {
            macho.push(macho.front());
            macho.pop();
        }
    }
    while (!ajuste.empty())
    {
        if (ajuste.front().sexo == 'H')
        {
            macho.push(ajuste.front());
            ajuste.pop();
        }
        else if (ajuste.front().sexo == 'M')
        {
            femea.push(ajuste.front());
            ajuste.pop();
        }
    }
    cout << "Fila Feminina:\n";
    if (femea.empty())
    {
        cout << "Vazia\n";
    }
    else
    {
        while (!femea.empty())
        {
            cout << femea.front().nome << "\n";
            femea.pop();
        }
    }
    cout << "Fila Masculina:\n";
    if (macho.empty())
    {
        cout << "Vazia\n";
    }
    else
    {
        while (!macho.empty())
        {
            cout << macho.front().nome << "\n";
            macho.pop();
        }
    }
    return 0;
}
