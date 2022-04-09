#include<stdio.h>
int main(){
    int n; //minimo de numero de caracteres
    int m; //minimo de letras minÃºsculas
    int a; //minimo de letras maiÃºsculas
    int k; //minimo de nÃºmero
    char senha[1000];
    int i; //indice do for
    int N=0;
    int M=0;
    int A=0;
    int K=0;
 
    scanf("%d%d%d%d",&n,&m,&a,&k);
    for(i=0; i!=1000; i++){
        senha[i]=0;
    }
    scanf("%s",senha);
    for(i=0; i!=1000; i++){
        if(senha[i]!='\0'){
            N++;
        }
        if(senha[i]>='a' && senha[i]<='z'){
            M++;
        }
        if(senha[i]>='A' && senha[i]<='Z'){
            A++;
        }
        if(senha[i]>='0' && senha[i]<='9'){
            K++;
        }
    }
    if(N>=n && M>=m && A>=a && K>=k){
        printf("Ok =/");
    }
    if(N<n || M<m || A<a || K<k){
        printf("Ufa :)");
    }
return 0;
} 