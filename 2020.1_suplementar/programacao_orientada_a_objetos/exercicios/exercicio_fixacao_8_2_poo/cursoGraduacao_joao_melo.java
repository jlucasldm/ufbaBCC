public class CursoGraduacao extends Curso{
    private int qtdDisciplinasObrigatorias;
    private int qtdDisciplinasOptativas;

    public CursoGraduacao(String id, String nome, String area, int qtdVagas, int qtdDisciplinasObrigatorias, int qtdDisciplinasOptativas){
        super(id, nome, area, qtdVagas, 900);
        this.qtdDisciplinasObrigatorias = qtdDisciplinasObrigatorias;
        this.qtdDisciplinasOptativas = qtdDisciplinasOptativas;
    }

    public void setQtdDisciplinasObrigatorias(int qtdDisciplinasObrigatorias){
        this.qtdDisciplinasObrigatorias = qtdDisciplinasObrigatorias;
    }

    public void setQtdDisciplinasOptativas(int qtdDisciplinasOptativas){
        this.qtdDisciplinasOptativas = qtdDisciplinasOptativas;
    }

    public int getQtdDisciplinasObrigatorias(){
        return this.qtdDisciplinasObrigatorias;
    }

    public int getQtdDisciplinasOptativas(){
        return this.qtdDisciplinasOptativas;
    }

    public String consultaCurso(){
        return "Nome: " + this.getNome() + "\n" +
                "Disciplinas a serem cursadas: " + this.getQtdDisciplinasObrigatorias();
    }
}