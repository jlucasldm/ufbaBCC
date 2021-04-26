//Joao Lucas Lima de Melo
public class Contatos{
    private String nome;
    private String telefone;

    //contrutor
    public Contatos(String nome, String telefone){
        this.nome = nome;
        this.telefone = telefone;
    }

    //gets e sets
    public void setNome(String nome){
        this.nome = nome;
    }

    public void setTelefone(String telefone){
        this.telefone = telefone;
    }

    public String getNome(){
        return this.nome;
    }

    public String  getTelefone(){
        return this.telefone;
    }
}