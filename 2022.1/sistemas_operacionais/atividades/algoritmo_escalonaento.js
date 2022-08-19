
var quantum = 2;
var sobrecarga = 1;

class Processo {
    constructor(nome, tempo_de_chegada, tempo_de_execucao,
        deadline, prioridade){ 
            this.nome;           
            this.tempo_de_chegada,
            this.tempo_de_execucao,
            this.deadline,
            this.prioridade
        }
};

var n_processos = 4;
var tempo_limite = 30;

var matrix = [tempo_limite][n_processos];

for(var i = 0; i < tempo_limite; i++){
    for(var j = 0; j < n_processos; j++){
        matrix[i][j] = " ";
    }
}

for(var i = 0; i < tempo_limite; i++){
    console.log("A ");
    for(var j = 0; j < n_processos; j++){
        console.log(matrix[i][j]);
    }
    console.log("\n");
}
