import java.util.ArrayList;
import java.util.Scanner;
/**
 * Escreva a descrição da classe Livro aqui.
 * 
 * @author (Linsmar da Silva Vital) 
 * @version (20200925)
 */
public class Livro
{
    // variáveis de instância - substitua o exemplo abaixo pelo seu próprio
    private String titulo;
    private String isbn;
    private String materia;
    private int edicao;
    private int ano;
    private int anoPublicacao;
    private static ArrayList<Livro> todosLivros = new ArrayList<Livro>();

    /**
     * COnstrutor para objetos da classe Livro
     */
    public Livro(String titulo, String isbn, String materia, int edicao, int ano, int anoPublicacao)
    {
        int x = 0;
        this.titulo = titulo;
        this.isbn = isbn;
        this.edicao = edicao;
        this.ano = ano;
        this.anoPublicacao = anoPublicacao;
        this.materia = materia;
    }  
    public Livro(String titulo, String isbn, String materia, int edicao, int anoPublicacao)
    {
        this(titulo, isbn, materia, edicao, 2019, anoPublicacao);
    }
    public Livro(String titulo, String isbn, String materia, int edicao)
    {
        this(titulo, isbn, materia, edicao, 2019);
    }

    /**
     * 
     */
    //Método para cadastrar livro pelo menu
    public static void cadastrarLivro(){
        Scanner var = new Scanner(System.in);
        String titulo = "default";
        String isbn = "default";
        String materia = "default";
        int edicao = 0;
        int ano = 0;
        int anoPublicacao = 0;
        System.out.println("Informe o titulo: ");
        titulo = var.nextLine();
        System.out.println("Informe o isbn: ");
        isbn = var.nextLine();
        System.out.println("Escolha a matéria do livro: ");
        int op = 0;
        System.out.println(
            "1. Português \n" + 
            "2. Matemática \n" +
            "3. Ciências \n" + 
            "4. História \n" + 
            "5. Geografia \n" + 
            "6. Inglês \n" + 
            "7. Espanhol \n"
        );
        op = var.nextInt();
        switch(op){
            case 1:
                materia = Disciplina.PT.getNome();
                break;
            case 2:
                materia = Disciplina.MAT.getNome();
                break;
            case 3:
                materia = Disciplina.CIE.getNome();
                break;
            case 4:
                materia = Disciplina.HIS.getNome();
                break;
            case 5:
                materia = Disciplina.GEO.getNome();
                break;
            case 6:
                materia = Disciplina.ING.getNome();
                break;
            case 7:
                materia = Disciplina.ESP.getNome();
                break;
        }
        System.out.println("Informe a edição: ");
        edicao = var.nextInt();
        System.out.println("Informe o ano: ");
        ano = var.nextInt();
        System.out.println("Informe o ano de publicação: ");
        anoPublicacao = var.nextInt();
        
        Livro novo = new Livro(titulo, isbn, materia, edicao, ano, anoPublicacao);
        todosLivros.add(novo);
        System.out.println("Livro criado");
    }
    public void consulta(String isbn)
    {
        if (this.isbn == isbn){
            System.out.println("------\n" + "Consulta do Livro:\n" + "Titulo: " + this.titulo + "\nISBN: " + this.isbn +
             "\nMatéria: " + this.materia + "\nEdição: " + this.edicao + "\nAno: " + this.ano + "\nAno de Publicação: "
              + this.anoPublicacao);
        }
        else System.out.println("ISBN incorreto");
    }
    public void consultaTitulo(String titulo)
    {
        if (this.isbn == isbn){
            System.out.println("------\n" + "Consulta:\n" + "Titulo: " + this.titulo + "\nISBN: " + this.isbn +
             "\nMatéria: " + this.materia + "\nEdição: " + this.edicao + "\nAno: " + this.ano + "\nAno de Publicação: "
              + this.anoPublicacao);
        }
        else System.out.println("Titulo incorreto");
    }
    public String getTitulo() {
        return this.titulo;
    }
    public String getIsbn() {
        return this.isbn;
    }
    public String getMateria() {
        return this.materia;
    }
    public int getEdicao() {
        return this.edicao;
    }
    public int getAno() {
        return this.ano;
    }
    public int getAnoPublicacao() {
        return this.anoPublicacao;
    }
    public static ArrayList<Livro> getTodosLivros() {
        return todosLivros;
    }
    
    public void setTitulo(String titulo) {
        this.titulo = titulo;
    }
    public void setIsbn(String isbn) {
        this.isbn = isbn;
    }
    public void setMateria(String materia) {
        this.materia = materia;
    }
    public void setEdicao(int edicao) {
        this.edicao = edicao;
    }
    public void setAno(int ano) {
        this.ano = ano;
    }
    public void setAnoPublicacao(int anoPublicacao) {
        this.anoPublicacao = anoPublicacao;
    }
}
