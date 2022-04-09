#include<stdio.h>
int main(){
    int i;
    int p;
    int s;
    int in;
    int di;
    int j;
    scanf("%d %d",&p,&s);
    int v[p];
    for(i=0;i<p;i++){
        v[i]=0;
    }
    for(i=0;i<s;i++){
      scanf("%d %d",&in,&di);
      for(j=in-1;j<p;j+=di){
        v[j]=1;
      }
      for(j=in-1;j>=0;j-=di){
        v[j]=1;
      }  
    }
    
    printf("\n");
    for(i=0;i<p;i++){
        printf("%d\n",v[i]);
    }
return 0;    
}