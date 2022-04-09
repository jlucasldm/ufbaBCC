#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    int n;
    int aux = 0;
    cin >> n;
    vector<int> vet(n);
    for (int i = 0; i < vet.size(); i++)
    {
        cin >> vet[i];
    }
    sort(vet.begin(), vet.end());
    cout << vet[n / 2] << endl;
    return 0;
}
