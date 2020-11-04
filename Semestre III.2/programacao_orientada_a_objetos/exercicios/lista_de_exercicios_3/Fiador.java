public class Fiador{
    private String nome;
    private int cpf;
    private float rendaMensal;

    public Fiador(String nome, int cpf, float rendaMensal){
        this.nome = nome;
        this.cpf = cpf;
        this.rendaMensal = rendaMensal;
    }

    public void setNome(String nome){
        this.nome = nome;
    }

    public void setCpf(int cpf){
        this.cpf = cpf;
    }

    public void setRendaMensal(float rendaMensal){
        this.rendaMensal = rendaMensal;
    }

    public String getNome(){
        return this.nome;
    }

    public int getCpf(){
        return this.cpf;
    }

    public float getRendaMensal(){
        return this.rendaMensal;
    }
}