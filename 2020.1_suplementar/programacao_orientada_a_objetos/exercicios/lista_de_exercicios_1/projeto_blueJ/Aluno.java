
/**
 * Write a description of class aluno here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class Aluno
{
    private int matricula;
    private String nome; 
    private String curso;
    
    public Aluno(String nome, String curso, int matricula)
    {
        this.nome = nome;
        this.curso = curso;
        this.matricula = matricula;
    }
    
    public int getMatricula(){
        return this.matricula;
    }

    public String getNome(){
        return this.nome;
    }

    public String getCurso(){
        return this.curso;
    }

    public void setMatricula(int matricula){
        this.matricula = matricula;
    }

    public void setNome(String nome){
        this.nome = nome;
    }

    public void setCurso(String curso){
        this.curso = curso;
    }
}
