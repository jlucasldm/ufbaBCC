public class JogadorFutebol{
    String nome;
    String posicao;
    int anoNascimento;
    String nacionalidade;
    int altura;
    int peso;
    
    String retornaJogadorFutebol(){
        return nome + " " + anoNascimento + " " + nacionalidade + " " + altura + " " + posicao + " " + peso;
    }
    
    int calculoIdade(int anoAtual){
        return anoAtual - anoNascimento;
    }
    
    int tempoParaAposentar(int anoAtual){
        int idade = anoAtual - anoNascimento;
        int tempoRestante;
        
        if(posicao == "defesa"){
            tempoRestante = 40-idade;
        }else if(posicao == "meio-campo"){
            tempoRestante = 38-idade;
        }else{
            tempoRestante = 35-idade;
        }
        
        if(tempoRestante < 0){
            tempoRestante = 0;
        }
        return tempoRestante;
    }
}