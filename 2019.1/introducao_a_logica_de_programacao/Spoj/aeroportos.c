#include<stdio.h>
int main(){ 
int maior=0; 
int a,v,x,y,T=1; 
scanf("%d%d",&a,&v);
while (a!=0 && v!=0) { 
    int z=0; 
    int i; 
    int aeroportos[a]; 
    int p;
    for (p=0; p<a; p++){ 
        aeroportos[p]=0;
    }

    for (i = 0; i < v; i++) { 
        scanf("%d %d",&x,&y); 
        aeroportos[x-1]++; 
        aeroportos[y-1]++;
        } 
    for (i = 0; i < a; i++) { 
        if(aeroportos[i]>maior){ 
            maior = aeroportos[i];
            } 
    } 
    printf("Teste %d\n",T);
    for(i=0;i<a;i++){ 
        if(maior == aeroportos[i]){ 
            printf("%d ",i+1);
        } 
    }
    printf("\n\n");
    T++; 
    scanf("%d%d", &a, &v); 
    } 
return 0;
}
