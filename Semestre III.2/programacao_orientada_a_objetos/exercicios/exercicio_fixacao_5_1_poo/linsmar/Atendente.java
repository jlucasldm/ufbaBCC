import java.util.ArrayList;
/**
 * Write a description of class Atendente here.
 * 
 * @author (Linsmar da Silva Vital) 
 * @version (20201114)
 */
public class Atendente
{
   private String curso;
   private static int novaMatricula = 0;
   private static ArrayList<Aluno> alunosMatriculados = new ArrayList<Aluno>();
   private static ArrayList<Atendente> atendentesExistentes = new ArrayList<Atendente>();
   
   public Atendente(String curso){
       this.curso = curso;
   }
   
   public static void criarMatricula(String nome, String curso){
       addMatricula();
       Aluno x = new Aluno(nome, curso, novaMatricula);
       alunosMatriculados.add(x);
       System.out.println(
        "Nome do Aluno: " + x.getNome() + "\n" +
        "Curso: " + x.getCurso() + "\n" + 
        "Matricula: " + novaMatricula + "\n" + "------------"
       );
   }
   public static void criarAtendente(String curso){
       Atendente x = new Atendente(curso);
       atendentesExistentes.add(x);
   }
   
   public static void addMatricula(){
       novaMatricula++;
   }
   public static ArrayList<Aluno> getAlunosMatriculados(){
       return alunosMatriculados;
   }
   public static ArrayList<Atendente> getAtendentesExistentes(){
       return atendentesExistentes;
   }
   public String getCurso() {
       return this.curso;
   }
}
