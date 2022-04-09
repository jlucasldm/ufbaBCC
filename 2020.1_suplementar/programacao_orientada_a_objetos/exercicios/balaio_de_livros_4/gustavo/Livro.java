// Gustavo de Oliveira Ferreira

public class Livro {

    private String titulo;
    private String isbn;
    private String edicao;
    private int ano;
    private int anoPublicacao;
    private MateriaEnum materia;

    public Livro(String titulo, String isbn, MateriaEnum materia, String edicao, int ano, int anoPublicacao){
        this.titulo = titulo;
        this.isbn = isbn;
        this.materia = materia;
        this.edicao = edicao;
        this.ano = ano;
        this.anoPublicacao = anoPublicacao;
    }

    // public Livro(String titulo, String isbn, MateriaEnum materia, String edicao, int ano){
    //     this(titulo, isbn, materia, edicao, ano, 2019);
    // }

    public String consultaLivro(String identificador){

        char[] identificadorChar = identificador.toCharArray();
        boolean flag = true;

        for(int i = 0; i < identificadorChar.length; i++){
            if(!Character.isDigit(identificadorChar[i])){
                flag = false;
                break;
            }
        }

        if(flag){
            if(identificador.equals(this.isbn)){
                return "De acordo com o código ISBN dado, estas são as informações sobre o livro:\n" + "Título: " + this.titulo + "\nISBN: "+ this.isbn +"\nMatéria: " + this.materia + "\nEdição: " + this.edicao + "\nAno: " + this.ano+"\nAno de publicação: " + this.anoPublicacao;
            }
            else {
                return "Não há nenhum livro com este código ISBN";
            }
        }
        else {
            if(identificador.equals(this.titulo)){
                return "De acordo com o título dado, estas são as informações sobre o livro:\n" + "Título: " + this.titulo + "\nISBN: "+ this.isbn +"\nMatéria: " + this.materia + "\nEdição: " + this.edicao + "\nAno: " + this.ano+"\nAno de publicação: " + this.anoPublicacao;
            }
            else {
                return "Não há nenhum livro com este título";
            }
        }
    }

    public String getTitulo() {
        return this.titulo;
    }

    public void setTitulo(String titulo) {
        this.titulo = titulo;
    }

    public String getIsbn() {
        return this.isbn;
    }

    public void setIsbn(String isbn) {
        this.isbn = isbn;
    }

    public String getEdicao() {
        return this.edicao;
    }

    public void setEdicao(String edicao) {
        this.edicao = edicao;
    }

    public int getAno() {
        return this.ano;
    }

    public void setAno(int ano) {
        this.ano = ano;
    }

    public int getAnoPublicacao() {
        return this.anoPublicacao;
    }

    public void setAnoPublicacao(int anoPublicacao) {
        this.anoPublicacao = anoPublicacao;
    }

    public MateriaEnum getMateria() {
        return this.materia;
    }

    public void setMateria(MateriaEnum materia) {
        this.materia = materia;
    }

}