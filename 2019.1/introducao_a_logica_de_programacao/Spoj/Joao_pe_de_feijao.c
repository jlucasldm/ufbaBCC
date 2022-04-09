#include<stdio.h>
int main(){
    long long int n;
    
    while(n!=0){
	scanf("%d",&n);
    if(n==0){
        break;
    }
        long long int prod=n*n;
        long long int i;
        long long int esq1=prod/10;
        long long int dir1=prod%10;
        long long int esq2=prod/100;
        long long int dir2=prod%100;
        long long int esq3=prod/1000;
        long long int dir3=prod%1000;
        long long int esq4=prod/10000;
        long long int dir4=prod%10000;
        long long int esq5=prod/100000;
        long long int dir5=prod%100000;
        long long int esq6=prod/1000000;
        long long int dir6=prod%1000000;
        long long int esq7=prod/10000000;
        long long int dir7=prod%10000000;
        long long int esq8=prod/100000000;
        long long int dir8=prod%100000000;
        long long int esq9=prod/1000000000;
        long long int dir9=prod%1000000000;
        long long int esq10=prod/10000000000;
        long long int dir10=prod%10000000000;
        if(n==1){
            printf("1: S\n");
            continue;
        }
        if(n==esq1+dir1 && esq1>0 && dir1>0){
            printf("%d: S\n",n);
        }
        else if(n==esq2+dir2 && esq2>0 && dir2>0){
            printf("%d: S\n",n);
        }
        else if(n==esq3+dir3 && esq3>0 && dir3>0){
            printf("%d: S\n",n);
        }
        else if(n==esq4+dir4 && esq4>0 && dir4>0){
            printf("%d: S\n",n);
        }
        else if(n==esq5+dir5 && esq5>0 && dir5>0){
            printf("%d: S\n",n);
        }
        else if(n==esq6+dir6 && esq6>0 && dir6>0){
            printf("%d: S\n",n);
        }
        else if(n==esq7+dir7 && esq7>0 && dir7>0){
            printf("%d: S\n",n);
        }
        else if(n==esq8+dir8 && esq8>0 && dir8>0){
            printf("%d: S\n",n);
        }
        else if(n==esq9+dir9 && esq9>0 && dir9>0){
            printf("%d: S\n",n);
        }
        else if(n==esq10+dir10 && esq10>0 && dir10>0){
            printf("%d: S\n",n);
        }
        else{
            printf("%d: N\n",n);
        }
    }
return 0;    
}