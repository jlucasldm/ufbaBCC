public class JogadorFutebol{
    String nome;
    String posicao;
    int anoNascimento;
    String nacionalidade;
    int altura;
    int peso;
    String retornaJogadorFutebol(){
        return nome, posicao, anoNascimento, nacionalidade, altura, peso;
    }
    int calculoIdade(int anoAtual){
        return anoAtual - anoNascimento;
    }
    int tempoParaAposentar(int anoAtual){
        int idade = anoAtual - anoNascimento;
        int tempoRestante;
        if(posicao == 'defesa'){
            tempoRestante = 40-idade;
            //se aposenta aos 40
        }else if(posicao == 'meio-campo'){
            tempoRestante = 38-idade;
            //se aposenta aos 38
        }else{
            tempoRestante = 35-idade;
            //se aposenta aos 35
        }
        return tempoRestante;
    }
}