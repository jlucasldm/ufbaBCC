public class Cliente{
    private String nome;
    private int idade;

    public Cliente(String nome, int idade){
        this.nome = nome;
        this.idade = idade;
    }

    public void setNome(String nome){
        this.nome = nome;
    }

    public void setIdade(int idade){
        this.idade = idade;
    }

    public String getNome(){
        return this.nome;
    }

    public int getIdade(){
        return this.idade;
    }

    public float valorIngresso(String dia){
        if(dia == "quarta" || dia == "quinta" || this.idade > 65 || this.idade < 14){
            return 8;
        }else{
            return 16;
        }
    }
}