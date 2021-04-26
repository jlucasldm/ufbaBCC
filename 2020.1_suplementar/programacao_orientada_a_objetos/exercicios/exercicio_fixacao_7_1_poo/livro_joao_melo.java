//João Lucas Lima de Melo
public class Livro extends Publicacao{
    private String isbn;

    public Livro(String titulo, String anoPublicacao, String veiculoPublicacao, int qtdCopias, String isbn){
        super(titulo, anoPublicacao, veiculoPublicacao, qtdCopias);
        this.isbn = isbn;
    }

    public void setIsbn(String isbn){
        this.isbn = isbn;
    }

    public String getIsbn(){
        return isbn;
    }
}