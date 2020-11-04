//João Lucas Lima de Melo
public class Funcionario
{
    // variáveis de instância - substitua o exemplo abaixo pelo seu próprio
    private String nome;
    private String endereco;
    private String telefone;
    private float salario;
    private String dataAdmissao;
    private String dataDemissao;

    
    //construtores
    public Funcionario(String nome, String endereco, String telefone, float salario, String dataAdmissao)
    {
        // inicializa variáveis de instância
        this.nome = nome;
        this.endereco = endereco;
        this.telefone = telefone;
        this.salario = salario;
        this.dataAdmissao = dataAdmissao;
        this.dataDemissao = "";
    }

    public Funcionario(String nome, String endereco, String telefone, String dataAdmissao)
    {
        // inicializa variáveis de instância
        this.nome = nome;
        this.endereco = endereco;
        this.telefone = telefone;
        this.salario = 1045;
        this.dataAdmissao = dataAdmissao;
        this.dataDemissao = "";
    }
    
    public Funcionario(String nome, String endereco, String telefone, float salario)
    {
        // inicializa variáveis de instância
        this.nome = nome;
        this.endereco = endereco;
        this.telefone = telefone;
        this.salario = salario;
        this.dataAdmissao = "dia de hoje";
        this.dataDemissao = "";
    }
    
    public Funcionario(String nome, String endereco, String telefone)
    {
        // inicializa variáveis de instância
        this.nome = nome;
        this.endereco = endereco;
        this.telefone = telefone;
        this.salario = 1045;
        this.dataAdmissao = "dia de hoje";
        this.dataDemissao = "";
    }
    
    
    //gets e sets
    public void setNome(String nome)
    {
        this.nome = nome;
    }
    
    public void setEndereco(String endereco)
    {
        this.endereco = endereco;
    }
    
    public void setTelefone(String telefone)
    {
        this.telefone = telefone;
    }
    
    public void setSalario(float salario)
    {
        this.salario = salario;
    }
    
    public void setDataAdmissao(String dataAdmissao)
    {
        this.dataAdmissao = dataAdmissao;
    }
    
    public void setDataDemissao(String dataDemissao)
    {
        this.dataDemissao = dataDemissao;
    }
    
    public String getNome()
    {
        return this.nome;
    }
    
    public String getEndereco()
    {
        return this.endereco;
    }
    
    public String getTelefone()
    {
        return this.telefone;
    }
    
    public float getSalario()
    {
        return this.salario;
    }
    
    public String getDataAdmissao()
    {
        return this.dataAdmissao;
    }
    
    public String getDataDemissao()
    {
        return this.dataDemissao;
    }
    
    
    //metodos
    public void demitirFuncionario(String dataDemissao)
    {
        // ponha seu código aqui
        this.dataDemissao = dataDemissao;
    }
    
    public void demitirFuncionario()
    {
        // ponha seu código aqui
        this.dataDemissao = "hoje";
    }
    
    public void promoverFuncionario(int percentualPromocao)
    {
        //int salario = this.salario;
        this.salario += this.salario*percentualPromocao/100;
    }
    
    public void promoverFuncionario()
    {
        //int salario = this.salario;
        this.salario += this.salario*3/100;
    }
}
