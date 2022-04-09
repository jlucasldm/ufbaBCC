#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main(){
    int n, i, num;
    priority_queue<int> pq; // fila de prioridade - Assim os maiores elementos estarão no topo - Padrão less<int>
    priority_queue<int, vector<int>, greater<int>> pq; // Assim é o contrario da declaração Padrão, ou seja, para casos onde se deseja o minimo
    for(int i = 0; i < n; i++)
    {
        cin >> num;
        pq.push(num);// A medida que se coloca os elementos na heap, ela vai se reordenando
    }
    while(!pq.empty())
    {
        cout << pq.top() << endl;
        pq.pop();
    }
}