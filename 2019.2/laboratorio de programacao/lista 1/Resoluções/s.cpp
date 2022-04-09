#include <iostream>
#include <set>
using namespace std;

int main()
{
    int n, m, e;
    int aux = 0;
    pair<int, int> p;
    set<int> total;
    set<int>::iterator it;

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> e;
        total.insert(e);
    }
    for (int i = 0; i < m; i++)
    {
        cin >> p.first >> p.second;
        if (total.count(p.first))
        {
            total.insert(p.second);
        }
    }
    cout << total.size() << endl;
    return 0;
}
