import java.util.ArrayList;
/**
 * Write a description of class atendente here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class Atendente
{
   private String curso;
   private static int controleMatricula = 0;
   private static ArrayList<Aluno> alunos = new ArrayList<Aluno>();
   
   public Atendente(String curso)
   {
        this.curso = curso;    
   }

   public String getCurso(){
       return this.curso;
   }

   public int getControleMatricula(){
       return this.controleMatricula;
   }

   public ArrayList<Aluno> getAlunos(){
       return this.alunos;
   }

   public void setCurso(String curso){
       this.curso = curso;
   }

   public void setControleMatricula(int controleMatricula){
       this.controleMatricula = controleMatricula;
   }

   public void setAlunos(ArrayList<Aluno> alunos){
       this.alunos = alunos;
   }

   public void matriculaAluno(String nome)
   {
       this.incrementaMatricula();
       Aluno aluno = new Aluno(nome, this.curso, this.controleMatricula);
       alunos.add(aluno);
       System.out.println("matricula do aluno "+aluno.getNome()+" �: "+controleMatricula+", Curso:"+ aluno.getCurso() );
       
   }
   
   private void incrementaMatricula()
   {
       controleMatricula++;
    }
        
}
