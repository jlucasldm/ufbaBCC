

/**
 * Write a description of class professor here.
 * 
 * @author Rita 
 * @version 1.0
 */
public class Professor
{
   private enum Departamento {DCC,DMAT, DEST, DFIS,DMU,INV};
   private String nomeProfessor, dataAdmissao, nomeDepartamento;//*sigla departamento em string*/
   private Departamento siglaDepartamento;
   private int registro;
   
   public Professor(String nomeProfessor,int idDepartamento,String dataAdmissao, int registro)
   {
       this.nomeProfessor = nomeProfessor;
       /*this.nomeDepartamento = nomeDepartamento;*/
       this.dataAdmissao = dataAdmissao;
       this.registro = registro;
       this.setDepartamento (idDepartamento);
    }
   
    public Professor(String nomeProfessor,String nomeDepartamento,String dataAdmissao, int registro)
    {
        this.nomeProfessor = nomeProfessor;
       /*this.nomeDepartamento = nomeDepartamento;*/
       this.dataAdmissao = dataAdmissao;
       this.registro = registro;
       this.setDepartamento (nomeDepartamento);
    }
    
    public void setDepartamento(String nomeDepartamento)
    {
        if ((nomeDepartamento.equals (Departamento.DCC)) |(nomeDepartamento.equals(Departamento.DMAT))| (nomeDepartamento.equals(Departamento.DFIS))|
 (nomeDepartamento.equals(Departamento.DMU)) )
            this.nomeDepartamento = nomeDepartamento;
         else
            this.nomeDepartamento = String.valueOf(Departamento.INV);
    }
    public void setDepartamento(Departamento siglaDepartamento){
         this.siglaDepartamento = siglaDepartamento;
  }
    public void DepartamentoExt(Departamento siglaDepartamento)
    {
        if (this.siglaDepartamento == Departamento.DCC) 
          System.out.println (Departamento.DCC.toString()+ "Departamento de Ciencia da Computação");
    
       
    }
/* Coloque neste metodo um comando convertendo o enum para String*/
     public void setDepartamento(int idDepartamento)
    {
        
        switch (idDepartamento)
        {
          case 1:
            this.setDepartamento(Departamento.DCC);
          break;
          case 2:
            this.setDepartamento(Departamento.DMAT);
          break;
          case 3:
            this.setDepartamento(Departamento.DFIS);
          break;
          case 4:
            this.setDepartamento(Departamento.DMU);
          break;
          default:
            this.setDepartamento(Departamento.INV);
          break;
        }
        /* É simples, para converter o Enum para String use o método toString() assim:

XXXX.toString();*/
    }   
     public String getNome () {
         return this.nomeProfessor;}
 
     public void mostraDadosProfessor () {
        System.out.println ("Professor(a): "+ this.getNome() + "\n Departamento :" + this.siglaDepartamento);
    }
}