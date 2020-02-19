#include <iostream>
#include <set>
#include <string>
using namespace std;

typedef pair<string, int> par;

int main()
{
    int n, m, e;
    set<par> total;
    set<par>::iterator it;
    par p;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> p.first >> p.second;
        total.insert(p);
    }
    for (it = total.begin(); it != total.end(); it++)
    {
        cout << it->first << " " << it->second << endl;
    }

    return 0;
}
