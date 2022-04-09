public class Assinante
{
    // variáveis de instância
    private String cpf;
    private String nome;
    private String endereco;
    private String telefone;

    /**
     * COnstrutor para objetos da classe Assinante
     */
    public Assinante(String cpf, String nm, String end, String tel)
    {
        // inicializa variáveis de instância
        this.cpf = cpf;
        this.nome = nm;
        this.endereco = end;
        if(tel.length() <= 9){
            this.telefone = "71"+tel;
        }else{
            this.telefone = tel;
        }
    }
    
    //gets e sets
    public String getCpf(){return cpf;}
    
    public String getNome(){return nome;}
    
    public String getEndereco(){return endereco;}
    
    public String getTelefone(){return telefone;}
    
    public void setCpf(String c){this.cpf = c;}
    
    public void setNome(String nm){this.nome = nm;}
    
    public void setEndereco(String end){this.endereco = end;}
    
    public void setTelefone(String tel){
        if(tel.length() <= 9){
            this.telefone = "71"+tel;
        }else{
            this.telefone = tel;
        }
    }
    
    //métodos
    public void consultaAssinante(Assinante assinante){
        System.out.println("Cpf: "+cpf+"\nNome: "+nome+"\nEndereco: "+endereco+"\nTelefone: "+telefone);
    }
}
