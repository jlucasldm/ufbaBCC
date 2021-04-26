#include<queue>
using namespace std;

int main(){
    int n, i, num;
    priority_queue<int, vector<int>, greator<int>> pq;
    cin>>n;
    for(i=0; i<n; i++){
        cin>>num;
        pq.push(num);
    }
    while(!pq.empty()){
        cout<<pq.top()<<endl;
        pq.pop();
    }
    return 0;
}+