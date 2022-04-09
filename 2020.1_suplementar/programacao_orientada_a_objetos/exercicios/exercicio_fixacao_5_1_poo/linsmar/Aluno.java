
/**
 * Escreva a descrição da classe Aluno aqui.
 * 
 * @author (Linsmar da Silva Vital) 
 * @version (20201114)
 */
public class Aluno
{
    // variáveis de instância - substitua o exemplo abaixo pelo seu próprio
    private String nome;
    private String curso;
    private int matricula;

    /**
     * COnstrutor para objetos da classe Aluno
     */
    public Aluno(String nome, String curso, int matricula)
    {
        this.nome = nome;
        this.curso = curso;
        this.matricula = matricula;
    }

    /**
     * 
     */
    public String getNome(){
        return this.nome;
    }
    public String getCurso(){
        return this.curso;
    }
    public int getMatricula(){
        return this.matricula;
    }
}
