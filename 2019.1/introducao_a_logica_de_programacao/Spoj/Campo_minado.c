#include<stdio.h>
int main(){
    int n;
    int i;
    scanf("%d",&n);
    int cm[n];
    for(i=0;i<n;i++){
        scanf("%d",&cm[i]);
    }
    printf("\n");
    
    for (i=0;i<n;i++){
        if(i==0){
            printf("%d\n",cm[i]+cm[i+1]);
        }
        else if(i==n-1){
            printf("%d\n",cm[i-1]+cm[i]);
        }
        else{
            printf("%d\n",cm[i-1]+cm[i]+cm[i+1]);
        }
    }

return 0;    
}