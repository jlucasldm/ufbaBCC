#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int v[n];
    int r[n];
    int i;
    int j;
    int maior=0;
    int m=0;
    for (i=0;i<n;i++){
        scanf("%d",&v[i]); 
    }
    for (i=0;i<n;i++){
        r[i]=0;
    }
    for (i=0;i<n;i++){
        for (j=0;j<n;j++){
            if (v[i]==v[j]){
                r[i]+=1;
            }
        }
    }
    for (i=0;i<n;i++){
        if (r[i]>maior){
            maior=r[i];
        }
    }
    for (i=0;i<n;i++){
        if(r[i]==maior && v[i]>m){
            m=v[i];
        }
    }
printf("%d\n",m);
return 0;
}