#include <iostream>
using namespace std;

int main(){
    int i;
    int j;
    int m;
    int n;
    int xr;
    int yr;
    int xq;
    int yq;
    int dis=0;
    cin>>m>>n;
    int a[m][n];

    for(i=0; i<m; i++){
        for(j=0; i<n; i++){
            cin>>a[i][j];
        }
    }

    for(i=0; i<m; i++){
        for(j=0; i<n; i++){
            if(a[i][j]==1){
                a[i][j]=-1;
            }
        }
    }

    a[xq][yq]=1;

}