/*
Um professor pediu para criar um programa que seila o que recebe numero de medalha de cada aluno recebeu por dia. Entra numero de 
dias dps numero de alunos.
Guardar em uma matriz onde linha = aluno; coluna = dia e dps exibe
*/
#include<iostream>
#include<algorithm>
using namespace std;

int main(){
  int ndias;
  int nalunos;
  cin>>ndias>>nalunos;

  int matriz[ndias][nalunos];

  for(int i=0; i<ndias; i++){
      for(int j=0; j<nalunos; j++){
          cin>>matriz[i][j];
      }
  }

  for(int i=0; i<ndias; i++){
      cout<<"| ";
      for(int j=0; j<nalunos; j++){
          cout<<matriz[i][j]<<" ";
      }
      cout<<"|"<<endl;
  }
  return 0;
}