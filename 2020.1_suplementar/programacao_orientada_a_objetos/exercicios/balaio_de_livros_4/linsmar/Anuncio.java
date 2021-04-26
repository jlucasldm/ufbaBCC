
import java.util.ArrayList;
import java.util.Scanner;
/**
 * Escreva a descrição da classe Anuncio aqui.
 * 
 * @author (Linsmar da Silva Vital) 
 * @version (20201024)
 */
public class Anuncio
{
    private String titulo;
    private float preco;
    private boolean ativo;
    private Assinante assinante;
    private Livro livro;
    private static ArrayList<Anuncio> todosAnuncios = new ArrayList<Anuncio>();

    /**
     * COnstrutor para objetos da classe Anuncio
     */
    public Anuncio(String titulo, float preco, boolean ativo, Assinante assinante, Livro livro)
    {
        this.titulo = titulo;
        this.preco = preco;
        this.ativo = ativo;
        this.assinante = assinante;
        this.livro = livro;
    }
    public Anuncio(String titulo, boolean ativo, Assinante assinante, Livro livro)
    {
        this(titulo, 0, ativo, assinante, livro);
    }
    //Esse método é para cadastrar um novo anúncio pelo menu
    public static void cadastrarAnuncio(){
        Scanner var = new Scanner(System.in);
        if (Assinante.getTodosAssinantes().size() < 1) System.out.println("Não existem assinantes cadastrados para realizar um cadastro de anúncio");
        else if (Livro.getTodosLivros().size() < 1) System.out.println("Não existem livros cadastrados para realizar um cadastro de anúncio");
        else {
            boolean pass = false;//boolean para verificar se o assinante existe
            String nomeAssinante = "";
            Assinante assinante = new Assinante("","","","");
            System.out.println("Informe o nome do assinante: ");
            nomeAssinante = var.nextLine();
            for(int i = 0; i < Assinante.getTodosAssinantes().size(); i++){
                if (Assinante.getTodosAssinantes().get(i).getNome().equals(nomeAssinante)){
                    assinante = Assinante.getTodosAssinantes().get(i);
                    pass = true;
                }
                else System.out.println("Um assinante com esse nome não existe ");
            }
            if (pass){
                boolean secondPass = false;//segundo boolean para verificar se o livro existe
                Livro livro = new Livro("","","",0);
                String isbnLivro = "default";
                System.out.println("Informe o isbn do livro: ");
                isbnLivro = var.nextLine();
                for(int i = 0; i < Livro.getTodosLivros().size(); i++){
                    if (Livro.getTodosLivros().get(i).getIsbn().equals(isbnLivro)){
                        livro = Livro.getTodosLivros().get(i);
                        secondPass = true;
                    }
                    else System.out.println("Esse livro não existe ");
                }
                if (secondPass){
                    String titulo = "default";
                    float preco = 0;
                    boolean ativo = true;
                    System.out.println("Informe o título do anúncio: ");
                    titulo = var.nextLine();
                    System.out.println("Informe o preço (0 para gratuito): ");
                    preco = var.nextInt();
                    
                    
                    Anuncio novo = new Anuncio(titulo, preco, ativo, assinante, livro);
                    todosAnuncios.add(novo);
                    System.out.println("Anuncio criado");
                }
            }
        }
    }
    //Método para ver todos os anúncios pelo menu
    public static void verTodosAnuncios(){
        if (todosAnuncios.size() < 1) System.out.println("Não existem anúncios cadastrados");
        else{
            String ativado = "Sim";
            for(int i = 0; i < todosAnuncios.size(); i++){
                System.out.println("ID do Anúncio: " + i+1); //ID importante para os outros métodos
                todosAnuncios.get(i).getDados();
            }
            
        }
    }
    //Método para mudar se o anúncio está ativo ou não
    public static void mudarAtivo(){
        Scanner var = new Scanner(System.in);
        int id = -1;
        if (todosAnuncios.size() < 1) System.out.println("Não existem anúncios cadastrados");
        else{
            System.out.println("Informe o ID do anúncio: ");
            id = var.nextInt();
            if (todosAnuncios.size() >= id){
                if(todosAnuncios.get(id-1).getAtivo()){
                    todosAnuncios.get(id-1).setAtivo(!todosAnuncios.get(id-1).getAtivo());
                    System.out.println("Anúncio desativado");
                }
                else{
                    todosAnuncios.get(id-1).setAtivo(!todosAnuncios.get(id-1).getAtivo());
                    System.out.println("Anúncio ativado");
                }
            }
            else System.out.println("ID incorreto");
        }
    }
    //Método para ver informações do livro de um determinado anúncio
    public static void verLivro(){
        Scanner var = new Scanner(System.in);
        int id = -1;
        if (todosAnuncios.size() < 1) System.out.println("Não existem anúncios cadastrados");
        else{
            System.out.println("Informe o ID do anúncio: ");
            id = var.nextInt();
            if (todosAnuncios.size() >= id){
                todosAnuncios.get(id-1).getLivro().consulta(todosAnuncios.get(id-1).getLivro().getIsbn());
            }
            else System.out.println("ID incorreto");
        }
    }
    /**
     * 
     */
    public void getDados()
    {
        String a;
        String troca;
        if (this.ativo) a = "Sim";
        else a = "Não";
        if(this.preco == 0) troca = "Troca de livros";
        else troca = Float.toString(this.preco);
        System.out.println(
        "Titulo do anúncio: " + this.titulo + 
        "\nPreço: " + troca + 
        "\nAnúncio ativo?: " + a + 
        "\nAssinante: " + this.assinante.getNome() + 
        "\nLivro: " + this.livro.getTitulo() + 
        "\nISBN: " + this.livro.getIsbn() + 
        "\nDisciplina: " + this.livro.getMateria() + 
        "\nEdição: " + this.livro.getEdicao() + 
        "\nAno: " + this.livro.getAno() + 
        "\nAno de publicação " + this.livro.getAnoPublicacao() + 
        "\n---------");
    }
    public void setTitulo(String titulo){
        this.titulo = titulo;
    }
    public void setTitulo(String titulo, boolean ativo){
        this.titulo = titulo;
        this.ativo = ativo;
    }
    public String getTitulo(){
        return this.titulo;
    }
    public void setPreco(float preco){
        this.preco = preco;
    }
    public void setPreco(float preco, boolean ativo){
        this.preco = preco;
        this.ativo = ativo;
    }
    public float getPreco(){
        return this.preco;
    }
    public void setAtivo(boolean ativo){
        this.ativo = ativo;
    }
    public boolean getAtivo(){
        return this.ativo;
    }
    public void setAssinante(Assinante assinante){
        this.assinante = assinante;
    }
    public void setAssinante(Assinante assinante, boolean ativo){
        this.assinante = assinante;
        this.ativo = ativo;
    }
    public Assinante getAssinante(){
        return this.assinante;
    }
    public void setLivro(Livro livro){
        this.livro = livro;
    }
    public void setLivro(Livro livro, boolean ativo){
        this.livro = livro;
        this.ativo = ativo;
    }
    public Livro getLivro(){
        return this.livro;
    }
    public static ArrayList<Anuncio> getTodosAnuncios(){
        return todosAnuncios;
    }
}
