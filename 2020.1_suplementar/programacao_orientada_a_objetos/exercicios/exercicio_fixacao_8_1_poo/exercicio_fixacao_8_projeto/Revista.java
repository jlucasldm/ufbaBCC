public class Revista extends Titulo {
  private int periodicidade;
  private static final float iss = (float)0.01;
  private static final float valorPosDesconto = (float)0.98;
  
  public Revista(String nome, String editora, float preco, int periodicidade) {
    super(nome, editora, preco);
    this.periodicidade = periodicidade;
  }

  public int getPeriodicidade() {
    return this.periodicidade;
  }

  public void setPeriodicidade(int periodicidade) {
    this.periodicidade = periodicidade;
  }

  public static boolean mesmaEditora(Revista revista1, Revista revista2){
    if (revista1.getEditora().equals(revista2.getEditora())) {
      return true;
    } else {
      return false;
    }
  }

  public float calculaPrecoFinal(boolean ehVip){
    if(ehVip == true){
      return this.getPreco()*(1+Revista.iss)*(Revista.valorPosDesconto);
    }else{
      return this.getPreco()*(1+Revista.iss);
    }
  }

  public String toString() {
    return super.toString() + ", periodicidade(dias): " + this.periodicidade;
  }

  public String emitirNota(boolean ehVip){
        return "Livraria: " + AplicacaoLivraria.getNomeLivraria() + "\n" + 
        "Titulo: " + this.getNome() + "\n" +
        "Valor a ser pago: " + this.calculaPrecoFinal(ehVip) + "\n";
    }
}