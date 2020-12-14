public class CursoPosGraduacao extends Curso{
    private int cargaHorariaMax;

    public CursoPosGraduacao(String id, String nome, String area, int qtdVagas, int cargaHorariaMax){
        super(id, nome, area, qtdVagas, 1200);
        this.cargaHorariaMax = cargaHorariaMax;
    }

    public void setCargaHorariaMax(int cargaHorariaMax){
        this.cargaHorariaMax = cargaHorariaMax;
    }

    public int getCargaHorariaMax(){
        return this.cargaHorariaMax;
    }

    public String consultaCurso(){
        return "Nome: " + this.getNome() + "\n" +
                "Carga horaria do curso: " + this.getCargaHorariaMax();
    }
}