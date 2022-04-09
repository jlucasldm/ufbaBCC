#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int h;
    int a;
    int g;
    int aux = 0;
    int l = 1;
    cin >> h;
    stack<int> ash;
    stack<int> gary;
    for (int i = 0; i < h; i++)
    {
        cin >> a;
        ash.push(a);
        cin >> g;
        gary.push(g);
    }
    while (l == 1)
    {
        if (ash.top() > gary.top())
        {
            ash.top() -= gary.top();
            gary.pop();
        }
        else if (ash.top() < gary.top())
        {
            gary.top() -= ash.top();
            ash.pop();
            aux++;
        }
        else if (ash.top() == gary.top())
        {
            ash.pop();
            gary.pop();
            aux++;
        }
        if (ash.empty() || gary.empty())
        {
            l = 0;
        }
    }
    cout << aux;
    return 0;
}
