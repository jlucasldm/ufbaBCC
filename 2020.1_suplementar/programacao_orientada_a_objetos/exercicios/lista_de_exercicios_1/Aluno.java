public class Aluno{
    private String nome;
    private int anoIngresso;
    private int qtdDisciplinasAporvadas;

    public Aluno(String nome, int anoIngresso, int qtdDisciplinasAporvadas){
        this.nome = nome;
        this.anoIngresso = anoIngresso;
        this.qtdDisciplinasAporvadas = qtdDisciplinasAporvadas;
    }

    //implementar gets e sets

    public int creditos(){
        return this.qtdDisciplinasAporvadas*4;
    }

    public int permanenciaDoAluno(int anoAtual){
        return anoAtual - anoIngresso;
    }
}