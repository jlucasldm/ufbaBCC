//João Lucas Lima de Melo
enum Departamento {
    COMPUTACAO("Departamento de Ciencia da Computacao"),
    MATEMATICA("Departamento de Matematica"),
    FISICA("Departamento de Fisica"),
    MUSICA("Departamento de Musica");
    
    private String name;

    Departamento(String name) {
        this.name = name;
    }

    public String getName() {
        return this.name;
    }
}

public class Professor
{
    // variáveis de instância - substitua o exemplo abaixo pelo seu próprio
    private String nomeProfessor;
    private String nomeDepartamento;
    private String dataAdmissao;
    private int numeroRegistro;

    
    public Professor(String nomeProfessor, String nomeDepartamento, String dataAdmissao, int numeroRegistro)
    {
        // inicializa variáveis de instância
        this.nomeProfessor = nomeProfessor;
        this.nomeDepartamento = nomeDepartamento;
        this.dataAdmissao = dataAdmissao;
        this.numeroRegistro = numeroRegistro;
    }
    
    public Professor(String nomeProfessor, String nomeDepartamento, int numeroRegistro)
    {
        // inicializa variáveis de instância
        this.nomeProfessor = nomeProfessor;
        this.nomeDepartamento = nomeDepartamento;
        this.dataAdmissao = "01/01/2009";
        this.numeroRegistro = numeroRegistro;
    }

    
    //gets e sets
    public void setNomeProfessor(String nomeProfessor)
    {
        this.nomeProfessor = nomeProfessor;
    }
    
    public void setNomeDepartamento(String nomeDepartamento)
    {
        this.nomeDepartamento = nomeDepartamento;
    }
    
    public void setNomeDepartamento(int indexDepartamento)
    {
        //this.nomeDepartamento = nomeDepartamento;
        //Departamento dep = Departamento.values()[indexDepartamento-1];
        //System.out.println(dep.getName());
        this.nomeDepartamento = Departamento.values()[indexDepartamento-1].getName();
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
    
    public String getNomeDepartamento()
    {
        return this.nomeDepartamento;
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
        // ponha seu código aqui
        System.out.println("Nome do professor: " + this.nomeProfessor + "\nNome do departamento: " + this.nomeDepartamento + "\nData de admissao: " + this.dataAdmissao + "\nNumero do registro: " + this.numeroRegistro);
    }
}
