#include <iostream>
#include <stack>
using namespace std;

struct tipo{
    int qnt, validade;
};

int main(){
    int n, m;
    stack<tipo> pilha, pilha_aux;

//PILHA NO INICIO
    cin >> n;
    for(int i = 0; i < n; i++){
        tipo aux;
        cin >> aux.qnt >> aux.validade;
        while(!pilha.empty() && pilha.top().validade <= aux.validade){
            pilha_aux.push(pilha.top());
            pilha.pop();
        }
        pilha.push(aux);
        while(!pilha_aux.empty()){
            aux = pilha_aux.top();
            pilha_aux.pop();
            if(aux.validade == pilha.top().validade)
                pilha.top().qnt += aux.qnt;
            else
                pilha.push(aux);
        }
    }

//NEGOCIAÇÕES
    cin >> m;
    for(int i = 0; i < m; i++){
        char neg;
        cin >> neg;
//LOJA COMPRANDO FENO
        if(neg == 'V'){
            tipo aux;
            cin >> aux.qnt >> aux.validade;
            while(!pilha.empty() && pilha.top().validade <= aux.validade){
                pilha_aux.push(pilha.top());
                pilha.pop();
            }
            pilha.push(aux);
            while(!pilha_aux.empty()){
                aux = pilha_aux.top();
                pilha_aux.pop();
                if(aux.validade == pilha.top().validade)
                    pilha.top().qnt += aux.qnt;
                else
                    pilha.push(aux);
            }
        }
//LOJA VENDENDO FENO
        else if(neg == 'C'){
            int vendas;
            cin >> vendas;
            for(int j = 0; j < vendas && !pilha.empty(); j++){
                tipo aux = pilha.top();
                pilha.pop();
                aux.qnt--;
                if(aux.qnt > 0) pilha.push(aux);
            }
        }
    }

    if(pilha.empty()) cout << "Sem estoque" << endl;
    while(!pilha.empty()){
        tipo aux = pilha.top();
        pilha.pop();
        cout << aux.qnt << ' ' << aux.validade << endl;
    }

    return 0;
}