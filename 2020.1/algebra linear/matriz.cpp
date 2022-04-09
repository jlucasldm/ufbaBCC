/*
Um professor pediu para criar um programa que seila o que recebe numero de medalha de cada aluno recebeu por dia. Entra numero de 
dias dps numero de alunos.
Guardar em uma a onde linha = aluno; coluna = dia e dps exibe
*/
#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int nlinhas;
    int aux = 0;
    char operacao;
    cin>>nlinhas;

    int a[nlinhas][3], b[nlinhas][3], resultado[nlinhas][3];

    for(int i=0; i<nlinhas; i++){
          for(int j=0; j<3; j++){
              cin>>a[i][j];
        }
    }

    for(int i=0; i<nlinhas; i++){
         for(int j=0; j<3; j++){
              cin>>b[i][j];
        }
    }

    cout<<"escolha a operação"<<endl;
    cin>>operacao;

    if(operacao == 's' /*soma de matriz*/){
    
        for(int i=0; i<nlinhas; i++){
            for(int j=0; j<3; j++){
                resultado[i][j]=a[i][j]+b[i][j];
            }
        }

        for(int i=0; i<nlinhas; i++){
            cout<<"| ";
            for(int j=0; j<3; j++){
                cout<<resultado[i][j]<<" ";
            }
            cout<<"|"<<endl;
        }

    }else if(operacao == 'm' /*multiplicacao de matriz*/){
        
        if(nlinhas == 3){
            for(int i=0; i<nlinhas; i++){
                for(int j=0; j<3; j++){
                    for(int k=0; k<3; k++){
                        aux+=a[i][k]*b[k][j];
                    }
                    resultado[i][j]=aux;
                    aux=0;
                }
            }

            for(int i=0; i<nlinhas; i++){
                cout<<"| ";
                for(int j=0; j<3; j++){
                    cout<<resultado[i][j]<<" ";
                }
                cout<<"|"<<endl;
            }

        }else{
            cout<<"dá não, meu abençoado"<<endl;
        }
    }

  return 0;
}