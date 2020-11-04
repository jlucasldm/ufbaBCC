public class Assinante
{
    // variáveis de instância
    private String cpf;
    private String nome;
    private String endereco;
    private String telefone;
    private Anuncio[] anuncios;

    /*
    Construtor para objetos da classe Assinante
    */

    public Assinante(String cpf, String nome, String endereco, String telefone)
    {
        // inicializa variáveis de instância
        this.cpf = cpf;
        this.nome = nome;
        this.endereco = endereco;
        if(telefone.length() <= 9){
            this.telefone = "71"+telefone;
        }else{
            this.telefone = telefone;
        }
        this.anuncios = new Anuncio[100];
    }
    
    //gets e sets
    public String getCpf(){
        return this.cpf;
    }
    
    public String getNome(){
        return this.nome;
    }
    
    public String getEndereco(){
        return this.endereco;
    }
    
    public String getTelefone(){
        return this.telefone;
    }

    public Anuncio[] getAnuncios(){
        return this.anuncios;
    }
    
    public void setCpf(String cpf){
        this.cpf = cpf;
    }
    
    public void setNome(String nome){
        this.nome = nome;
    }
    
    public void setEndereco(String endereco){
        this.endereco = endereco;
    }
    
    public void setTelefone(String telefone){
        if(telefone.length() <= 9){
            this.telefone = "71"+telefone;
        }else{
            this.telefone = telefone;
        }
    }

    public void setAnuncios(Anuncio anuncios){
        for(int i = 0; i < this.anuncios.length; i++){
            if(this.anuncios[i] == null){
                this.anuncios[i] = anuncios;
                break;
            }
        }
    }

    //métodos
    public String consultaAssinante(){
        return "Cpf: "+this.cpf+"//Nome: "+this.nome+"//Endereco: "+this.endereco+"//Telefone: "+this.telefone;
    }
}
