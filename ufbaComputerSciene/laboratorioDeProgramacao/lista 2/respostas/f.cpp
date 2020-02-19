#include<iostream>
#include<map>
#include<vector>
using namespace std;

int reprovado(int aulasTomadas, int aulasDadas){
    if(aulasTomadas<(0.75*aulasDadas)){
        return 1;
    }else{
        return 0;
    }
}

int main(){
    int n, d; //aulunos matriculados / aulas dadas
    int aluno;
    int presentes;
    map<int, int> m;
    map<int, int>::iterator it;

    cin>>n>>d;
    for(int i=0; i<n; i++){
        cin>>aluno;
        m[aluno]=0;
    }

    for(int i=0; i<d; i++){
        cin>>presentes;
        for(int i=0; i<presentes; i++){
            cin>>aluno;
            m[aluno]+=1;
        }
    }

    for(it=m.begin(); it!=m.end(); it++){
        cout<<(*it).first<<": ";
        if(reprovado(it->second, d)){
            cout<<"RF"<<endl;
        }else if((*it).second>=0.75*d){
            cout<<d-(*it).second<<endl;
        }
    }
    cout<<endl;

    return 0;
}