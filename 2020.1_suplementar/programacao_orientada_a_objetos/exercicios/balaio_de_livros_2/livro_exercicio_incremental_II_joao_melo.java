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
        this.materia = materia;
        this.edicao = edicao;
        this.ano = ano;
        this.anoPublicacao = 2019;
    }

    public Livro(String titulo, int isbn, String materia, int edicao, int ano, int anoPublicacao){
        this.titulo = titulo;
        this.isbn = isbn;
        this.materia = materia;
        this.edicao = edicao;
        this.ano = ano;
        this.anoPublicacao = anoPublicacao;
    }
    
    //gets e sets
    public String getTitulo(){return titulo;}

    public int getIsbn(){return isbn;}
    
    public String getMateria(){return materia;}
    
    public int getEdicao(){return edicao;}
    
    public int getAno(){return ano;}
    
    public int getAnoPublicacao(){return anoPublicacao;}
    
    public void setTitulo(String t){
        this.titulo = t;
    }
    
    public void setIsbn(int i){
        this.isbn = i;
    }
    
    public void setMateria(String m){
        this.materia = m;
    }
    
    public void setEdicao(int e){
        this.edicao = e;
    }
    
    public void setAno(int a){
        this.ano = a;
    }
    
    public void setAnoPublicacao(int a){
        this.anoPublicacao = a;
    }

    //métodos
    public void consultaLivro(Livro livro)
    {
        // ponha seu código aqui
        System.out.println("Titulo: "+titulo+"\nIsbn: "+isbn+"\nMateria: "+materia+"\nEdicao: "+edicao+"\nAno: "+ano+"\nAno de publicacao: "+anoPublicacao);
        //return "Titulo: "+titulo+"Isbn: "+isbn+"Materia: "+materia+"Edicao: "+edicao+"Ano: "+ano+"Ano de publicacao: "+anoPublicacao;
    }
}
