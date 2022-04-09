//João Lucas Lima de Melo
public class Professor
{
    // variáveis de instância - substitua o exemplo abaixo pelo seu próprio
    private String nomeProfessor;
    private Departamento departamento;
    private String dataAdmissao;
    private int numeroRegistro;

    
    public Professor(String nomeProfessor, Departamento departamento, String dataAdmissao, int numeroRegistro)
    {
        // inicializa variáveis de instância
        this.nomeProfessor = nomeProfessor;
        this.departamento = departamento;
        this.dataAdmissao = dataAdmissao;
        this.numeroRegistro = numeroRegistro;
    }
    
    public Professor(String nomeProfessor, Departamento departamento, int numeroRegistro)
    {
        // inicializa variáveis de instância
        this.nomeProfessor = nomeProfessor;
        this.departamento = departamento;
        this.dataAdmissao = "01/01/2009";
        this.numeroRegistro = numeroRegistro;
    }

    public Professor(String nomeProfessor, SiglaDepartamento siglaDepartamento, String dataAdmissao, int numeroRegistro)
    {
        // inicializa variáveis de instância
        this.nomeProfessor = nomeProfessor;
        this.departamento = new Departamento(siglaDepartamento);
        this.dataAdmissao = dataAdmissao;
        this.numeroRegistro = numeroRegistro;
    }
    
    public Professor(String nomeProfessor, SiglaDepartamento siglaDepartamento, int numeroRegistro)
    {
        // inicializa variáveis de instância
        this.nomeProfessor = nomeProfessor;
        this.departamento = new Departamento(siglaDepartamento);
        this.dataAdmissao = "01/01/2009";
        this.numeroRegistro = numeroRegistro;
    }

    
    //gets e sets
    public void setNomeProfessor(String nomeProfessor)
    {
        this.nomeProfessor = nomeProfessor;
    }

    public void setDepartamento(SiglaDepartamento siglaDepartamento)
    {
        this.departamento = new Departamento(siglaDepartamento);
    }

    public void setDepartamento(int numero){
        this.departamento = new Departamento(SiglaDepartamento siglaDepartamento.values()[numero-1]);
    }
    
    public void setDataAdmissao(String dataAdmissao)
    {
        this.dataAdmissao = dataAdmissao;
    }
    
    public void setNumeroRegistro(int numeroRegistro)
    {
        this.numeroRegistro = numeroRegistro;
    }
    
    public String getNomeProfessor()
    {
        return this.nomeProfessor;
    }
    
    public Departamento getDepartamento()
    {
        return this.departamento;
    }
    
    public String getDataAdmissao()
    {
        return this.dataAdmissao;
    }
    
    public int getNumeroRegistro()
    {
        return this.numeroRegistro;
    }
    
    
    //metodos
    public void exibirConteudo()
    {
        System.out.println("Nome do professor: " + this.nomeProfessor + "\nNome do departamento: " + this.departamento.getNome() + "\nData de admissao: " + this.dataAdmissao + "\nNumero do registro: " + this.numeroRegistro);
    }
}
