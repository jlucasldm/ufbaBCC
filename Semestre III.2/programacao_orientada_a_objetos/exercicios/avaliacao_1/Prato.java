//Joao Lucas Lima de Melo
public class Prato{
    private String nome;
    private float valor;
    private String tipo;    //principal, sobremesa, etc

    public Prato(String nome, float valor, String tipo){
        this.nome = nome;
        this.valor = valor;
        this.tipo = tipo;
    }

    public Prato(String nome, float valor){
        this.nome = nome;
        this.valor = valor;
        this.tipo = "principal";
    }

    public void setNome(String nome){
        this.nome = nome;
    }

    public void setValor(float valor){
        this.valor = valor;
    }

    public void setTipo(String tipo){
        this.tipo = tipo;
    }

    public String getNome(){
        return this.nome;
    }

    public float getValor(){
        return this.valor;
    }

    public String getTipo(){
        return this.tipo;
    }
}