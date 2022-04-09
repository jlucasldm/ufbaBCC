public class Titulo{
  private String nome;
  private String editora;
  private float preco;

  public Titulo(String nome, String editora, float preco){
    this.nome = nome;
    this.editora = editora;
    this.preco = preco;
  }

  public String getNome(){
    return this.nome;
  }
  public String getEditora(){
    return this.editora;
  }
  public float getPreco(){
    return this.preco;
  }

  public void setNome(String nome){
    this.nome = nome;
  }

  public void setEditora(String editora){
    this.editora = editora;
  }

  public void setPreco(float preco){
    this.preco = preco;
  }

  public String toString(){
    return this.nome + ", " + this.editora + ", " + this.preco;
  };

  public float calculaPrecoFinal() {
    return this.getPreco();
  }
  
}