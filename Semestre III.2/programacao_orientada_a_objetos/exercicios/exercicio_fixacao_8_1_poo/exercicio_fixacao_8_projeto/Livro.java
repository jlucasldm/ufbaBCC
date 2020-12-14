//Mauricio que fezzzzzzzzz 
public class Livro extends Titulo {
    private String resumo;
    private String autor;
    private final static float iss = (float)0.08;
    private final static float valorPosDesconto = (float)0.97;

    /*
    * Construtores
    */ 
    public Livro(String resumo, String autor,String nome, String editora, float preco) {
        super(nome, editora, preco);
        this.resumo = resumo;
        this.autor = autor;
    }

    /*
    * Getters
    */
    public String getResumo() {
        return resumo;
    }

    public String getAutor() {
        return autor;
    }

    public static float getIss(){ return Livro.iss;}

    public static float getDesconto(){ return Livro.valorPosDesconto;}

    /*
    * Setters
    */
    public void setResumo(String resumo) {
        this.resumo = resumo;
    }

    public void setAutor(String autor) {
        this.autor = autor;
    }

    /*
    * Metodos
    */
    @Override
    public String toString() {
        return "Livro{" +
                "resumo='" + this.getResumo() + '\'' +
                ", autor='" + this.getAutor() + '\'' +
                '}';
    }

    //Retorna o preço final com o imposto
    public float calculaPrecoFinal(boolean ehVip){
        if(ehVip == true){
          return this.getPreco()*(1+Livro.iss)*Livro.valorPosDesconto;
        }
        else{
          return this.getPreco()*(1+Livro.iss);
        }
    }

    public String emitirNota(boolean ehVip){
        return "Livraria: " + AplicacaoLivraria.getNomeLivraria() + "\n" + 
        "Titulo: " + this.getNome() + "\n" +
        "Valor a ser pago: " + this.calculaPrecoFinal(ehVip) + "\n";
    }
} //Mau: Isso que eu fiz faz sentido?