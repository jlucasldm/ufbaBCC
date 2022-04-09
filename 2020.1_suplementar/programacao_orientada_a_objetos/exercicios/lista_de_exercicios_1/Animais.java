public class Animais{
    private String tipo;    //fazer um enum
    private String nome;
    private int idade;

    public Animais(String tipo, String nome, int idade){
        this.tipo = tipo;
        this.nome = nome;
        this.idade = idade;
    }

    //fazer gets e sets

    public int gramasConsumidosPorDia(){
        if(this.tipo == "mamifero"){
            return 2000;
        }else if(this.tipo == "ave"){
            return 100;
        }else{
            return 20;
        }
    }
}