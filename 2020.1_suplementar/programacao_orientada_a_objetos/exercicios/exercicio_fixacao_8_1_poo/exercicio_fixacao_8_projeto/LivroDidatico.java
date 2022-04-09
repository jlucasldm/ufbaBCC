public class LivroDidatico extends Livro{
  private String area;
  private final static float iss = (float)0.005;
  private final static float valorPosDesconto = (float)0.9;

  public LivroDidatico(String nome, String autor, String editora, String resumo, float preco , String area){
    super(resumo, autor, nome, editora, preco);
    this.area = area;
  }

  public String getArea(){
    return area;
  }

  public void setArea(String area){
    this.area = area;
  }

  public float calculaPrecoFinal(boolean ehVip) {
    if(ehVip == true){
      return this.getPreco()*(1+LivroDidatico.iss)*(LivroDidatico.valorPosDesconto);
    }else{
      return this.getPreco()*(1+LivroDidatico.iss);
    }
  }

  public String emitirNota(boolean ehVip){
        return "Livraria: " + AplicacaoLivraria.getNomeLivraria() + "\n" + 
        "Titulo: " + this.getNome() + "\n" +
        "Valor a ser pago: " + this.calculaPrecoFinal(ehVip) + "\n";
    }
}