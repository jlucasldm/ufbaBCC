//João Lucas Lima de Melo
public class AnuncioVenda extends Anuncio{
    private float preco;

    public AnuncioVenda(String tituloAnuncio, boolean ativo, Assinante assinante, Livro livro, float preco){
        super(tituloAnuncio, ativo, assinante, livro);
        this.preco = preco;
    }

    //gets e sets
    public void setPreco(float preco){
        this.preco = preco;
    }

    public float getPreco(){
        return this.preco;
    }

    public void setPreco(float preco, boolean ativo){
        this.preco = preco;
        this.setAtivo(ativo);
    }

    //metodos
    public String dadosAnuncio(){
        return "Titulo do anuncio: " + this.getTituloAnuncio() + "//Preco: " + this.getPreco() + "//Status: " + 
        this.getAtivo() + "//Assinante: " + this.getAssinante().getNome() + "//Titulo do Livro: " + this.getLivro().getTitulo() +
        "//Isbn: " + this.getLivro().getIsbn() + "//Materia: " + this.getLivro().getMateria() + "//Edicao: " + this.getLivro().getEdicao() + 
        "//Ano: " + this.getLivro().getAno() + "//Ano de Publicacao: " + this.getLivro().getAnoPublicacao();
    }

    public void imprimeDadosAnuncio(){
        System.out.println("Titulo do anuncio: " + this.getTituloAnuncio() + "\nPreco: " + this.getPreco() + "\nStatus: " + 
        this.getAtivo() + "\nAssinante: " + this.getAssinante().getNome() + "\nTitulo do Livro: " + this.getLivro().getTitulo() +
        "\nIsbn: " + this.getLivro().getIsbn() + "\nMateria: " + this.getLivro().getMateria() + "\nEdicao: " + this.getLivro().getEdicao() + 
        "\nAno: " + this.getLivro().getAno() + "\nAno de Publicacao: " + this.getLivro().getAnoPublicacao());
    }

    public boolean ehAnuncioTroca(){
        return false;
    }
}