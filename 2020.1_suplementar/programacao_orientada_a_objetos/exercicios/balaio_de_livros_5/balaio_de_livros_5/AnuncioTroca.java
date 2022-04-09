import java.util.ArrayList;

public class AnuncioTroca extends Anuncio{
    private static ArrayList<Livro> listaLivrosTroca = new ArrayList<Livro>(); //colecao de livros desejados como troca aos anunciados

    public AnuncioTroca(String tituloAnuncio, boolean ativo, Assinante assinante, Livro livro){
        super(tituloAnuncio, ativo, assinante, livro);
    }

    public static void setListaLivrosTroca(ArrayList<Livro> lista){
        listaLivrosTroca = listaLivrosTroca;
    }

    public static ArrayList<Livro> getListaLivrosTroca(){
        return listaLivrosTroca;
    }

    public boolean ehAnuncioTroca(){
        return true;
    }

    public static void adicionarLivroTroca(Livro livro){
        listaLivrosTroca.add(livro);
    }

    public static boolean removerLivroTroca(Livro livro){
        for(Livro aux : listaLivrosTroca){
            if(aux.getIsbn().equals(livro.getIsbn())){
                listaLivrosTroca.remove(livro);
                return true;
            }
        }
        return false;
    }

    public String dadosAnuncio(){
        return "Titulo do anuncio de troca: " + this.getTituloAnuncio() + "//Status: " + 
        this.getAtivo() + "//Assinante: " + this.getAssinante().getNome() + "//Titulo do Livro: " + this.getLivro().getTitulo() +
        "//Isbn: " + this.getLivro().getIsbn() + "//Materia: " + this.getLivro().getMateria() + "//Edicao: " + this.getLivro().getEdicao() + 
        "//Ano: " + this.getLivro().getAno() + "//Ano de Publicacao: " + this.getLivro().getAnoPublicacao() + "//Lista de Livros para Troca:" + listaLivrosTroca;
    }

    public void imprimeDadosAnuncio(){
        System.out.println("Anuncio de Troca\nTitulo do anuncio: " + this.getTituloAnuncio() + "\nStatus: " + 
        this.getAtivo() + "\nAssinante: " + this.getAssinante().getNome() + "\nTitulo do Livro: " + this.getLivro().getTitulo() +
        "\nIsbn: " + this.getLivro().getIsbn() + "\nMateria: " + this.getLivro().getMateria() + "\nEdicao: " + this.getLivro().getEdicao() + 
        "\nAno: " + this.getLivro().getAno() + "\nAno de Publicacao: " + this.getLivro().getAnoPublicacao());
    }
}