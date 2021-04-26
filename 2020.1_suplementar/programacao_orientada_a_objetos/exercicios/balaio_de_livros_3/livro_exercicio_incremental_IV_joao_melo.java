enum Materia {
    PT("Portugues"),
    MAT("Matematica"),
    CIEN("Ciencias"),
    HIST("Historia"),
    GEO("Geografia"),
    ING("Ingles"),
    ESP("Espanhol");
    
    private String name;

    Materia(String name) {
        this.name = name;
    }

    public String getName() {
        return this.name;
    }
}

public class Livro
{
    // variáveis de instância
    private String titulo;
    private int isbn;
    private String materia;
    private int edicao;
    private int ano;
    private int anoPublicacao;

    /**
     * COnstrutor para objetos da classe livro
     */
    public Livro(String titulo, int isbn, String materia, int edicao, int ano){
        // inicializa variáveis de instância
        this.titulo = titulo;
        this.isbn = isbn;
        for(int i = 0; i < 7; i++){
            if(materia == Materia.values()[i].getName()){
                this.materia = materia;
            }
        }
        this.edicao = edicao;
        this.ano = ano;
        this.anoPublicacao = 2019;
    }

    public Livro(String titulo, int isbn, String materia, int edicao, int ano, int anoPublicacao){
        this.titulo = titulo;
        this.isbn = isbn;
        for(int i = 0; i < 7; i++){
            if(materia == Materia.values()[i].getName()){
                this.materia = materia;
            }
        }
        this.edicao = edicao;
        this.ano = ano;
        this.anoPublicacao = anoPublicacao;
    }
    
    //gets e sets
    public String getTitulo(){
        return titulo;
    }

    public int getIsbn(){
        return isbn;
    }
    
    public String getMateria(){
        return materia;
    }
    
    public int getEdicao(){
        return edicao;
    }
    
    public int getAno(){
        return ano;
    }
    
    public int getAnoPublicacao(){
        return anoPublicacao;
    }
    
    public void setTitulo(String titulo){
        this.titulo = titulo;
    }
    
    public void setIsbn(int isbn){
        this.isbn = isbn;
    }
    
    public void setMateria(String materia){
        for(int i = 0; i < 7; i++){
            if(materia == Materia.values()[i].getName()){
                this.materia = materia;
            }
        }
    }
    
    public void setEdicao(int edicao){
        this.edicao = edicao;
    }
    
    public void setAno(int ano){
        this.ano = ano;
    }
    
    public void setAnoPublicacao(int anoPublicacao){
        this.anoPublicacao = anoPublicacao;
    }

    //métodos
    public String consultaLivro(){
        return "Titulo: "+this.titulo+"//Isbn: "+this.isbn+"//Materia: "+this.materia+"//Edicao: "+this.edicao+"//Ano: "+this.ano+"//Ano de publicacao: "+this.anoPublicacao;
    }
}
