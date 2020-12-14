import java.util.Scanner;
import java.util.ArrayList;

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
    private String isbn;
    private String materia;
    private int edicao;
    private int ano;
    private int anoPublicacao;
    private static ArrayList<Livro> listaLivros = new ArrayList<Livro>();

    /**
     * COnstrutor para objetos da classe livro
     */
    public Livro(String titulo, String isbn, String materia, int edicao, int ano){
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

    public Livro(String titulo, String isbn, String materia, int edicao, int ano, int anoPublicacao){
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
        return this.titulo;
    }

    public String getIsbn(){
        return this.isbn;
    }
    
    public String getMateria(){
        return this.materia;
    }
    
    public int getEdicao(){
        return this.edicao;
    }
    
    public int getAno(){
        return this.ano;
    }
    
    public int getAnoPublicacao(){
        return this.anoPublicacao;
    }

    public static ArrayList<Livro> getListaLivros(){
        return listaLivros;
    }
    
    public void setTitulo(String titulo){
        this.titulo = titulo;
    }
    
    public void setIsbn(String isbn){
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

    public static void setListaLivros(ArrayList<Livro> lista){
        listaLivros = lista;
    }

    //métodos
    public String consultaLivro(){
        return "Titulo: "+this.titulo+"//Isbn: "+this.isbn+"//Materia: "+this.materia+"//Edicao: "+this.edicao+"//Ano: "+this.ano+"//Ano de publicacao: "+this.anoPublicacao;
    }

    public static void cadastrarLivro(){
        Scanner var = new Scanner(System.in);
        String titulo = "";
        String materia = "";
        String isbn = "";
        int edicao = 0;
        int ano = 0;
        int anoPublicacao = 0;

        System.out.println("Titulo do livro: ");
        titulo = var.nextLine();
        System.out.println("Isbn do livro: ");
        isbn = var.nextLine();
        System.out.println("Materia do livro (favor inserir a opcao numerica correspondente): ");
        int op = 0;
        System.out.println("1. Portugues \n" + "2. Matematica \n" + "3. Ciencias \n" + 
            "4. História \n" + "5. Geografia \n" + "6. Ingles \n" + "7. Espanhol \n");
        op = var.nextInt();
        switch(op){
            case 1:
                materia = Materia.PT.getName();
                break;
            case 2:
                materia = Materia.MAT.getName();
                break;
            case 3:
                materia = Materia.CIEN.getName();
                break;
            case 4:
                materia = Materia.HIST.getName();
                break;
            case 5:
                materia = Materia.GEO.getName();
                break;
            case 6:
                materia = Materia.ING.getName();
                break;
            case 7:
                materia = Materia.ESP.getName();
                break;
        }
        System.out.println("Edição do livro: ");
        edicao = var.nextInt();
        System.out.println("Ano do livro: ");
        ano = var.nextInt();
        System.out.println("Ano de publicação do livro: ");
        anoPublicacao = var.nextInt();
        
        Livro cadastrado = new Livro(titulo, isbn, materia, edicao, ano, anoPublicacao);
        listaLivros.add(cadastrado);
        System.out.println("Livro cadastrado");
    }

    public static void removerLivro(){
        Scanner var = new Scanner(System.in);
        String isbn = "";

        System.out.print("Isbn do livro a ser removido: ");
        isbn = var.nextLine();
        
        for(Livro livro : listaLivros){
            if(livro.getIsbn().equals(isbn)){
                listaLivros.remove(livro);
                break;
            }
        }
    }
}
