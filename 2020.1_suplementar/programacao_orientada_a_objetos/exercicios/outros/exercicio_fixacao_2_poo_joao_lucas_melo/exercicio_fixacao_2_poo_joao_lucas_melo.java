public class Livro
{
    String titulo;
    int isbn;
    String materia;
    int edicao;
    int anoPublicacao;
    int ano;
    
    public Livro(String titulo, int isbn, String materia, int edicao, int anoPublicacao){
        this.titulo = titulo;
        this.isbn = isbn;
        this.materia = materia;
        this.edicao = edicao;
        this.anoPublicacao = anoPublicacao;
        this.ano = 2019;
    }
    
    public Livro(String titulo, int isbn, String materia, int edicao, int anoPublicacao, int ano){
        this.titulo = titulo;
        this.isbn = isbn;
        this.materia = materia;
        this.edicao = edicao;
        this.anoPublicacao = anoPublicacao;
        this.ano = ano;
    }

    String informacoesLivro(){
        return titulo + " " + isbn + " " + materia + " " + edicao + " " + anoPublicacao + " " + ano;
    }
}
