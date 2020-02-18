#include <stdio.h> // biblioteca standard de I/O
// a seguir a funcao CopiaVetor
void CopiaVetor(int n, int Vorig[ ], int Vdest[ ]){ // dois vetores
   int j; // j=0,1,2,…n-1

   for(j=0,j<n;j++){ // j=0,1,2,..n-1
   Vdest[j]=Vorig[j];
 } // fim for j
} // fim da funcao CopiaVetor

// a seguir a funcao main()
main(){
 int j,conta, Vorig[15],Vdest[15]; // declarações

 conta=0;
 for(j=0;j<15;j++){ // inicializa vetor
    Vorig[j]=conta++;
 } // fim for j
 CopiaVetor(15,Vorig,Vdest); // chama função
 for(j=0;j<15;j++){
    printf("%d ", Vorig[j],Vdest[j]);
 } // fim for j
}// fim main
