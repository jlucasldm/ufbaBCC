#include <queue>
using namespace std;

bool cmp (pair<int, int> a, pair<int, int> b){
    return (a.second>b.second || a.second==b.second && a.first<b.first);
}

int main()
{
    int n, i, num;
    pair<int,int> p;
    priority_queue<pair<int,int>, vector<pair<int, int>>, bool(*)(pair<int, int>, pair<int, int>)> pq(cmp);
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> p.first>> p.second;
        pq.push(p);
    }
    return 0;
}