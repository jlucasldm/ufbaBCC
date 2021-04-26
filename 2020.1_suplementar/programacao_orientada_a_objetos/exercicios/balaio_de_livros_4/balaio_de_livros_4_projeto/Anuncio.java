import java.util.Scanner;
import java.util.ArrayList;

public class Anuncio{
    private String tituloAnuncio;
    private float preco;    //0 se for troca
    private boolean ativo;  //ativo ou inativo
    private String condicao;    //troca ou venda;
    private Assinante assinante;
    private Livro livro;
    private static ArrayList<Anuncio> listaAnuncios = new ArrayList<Anuncio>();

    public Anuncio(String tituloAnuncio, float preco, boolean ativo, Assinante assinante, Livro livro){
        this.tituloAnuncio = tituloAnuncio;
        this.preco = preco;
        this.ativo = ativo;
        if(this.preco == 0){
            this.condicao = "troca";
        }else{
            this.condicao = "venda";
        }
        this.assinante = assinante;
        this.assinante.adicionarAnuncio(this);
        this.livro = livro;
    }

    public Anuncio(String tituloAnuncio, boolean ativo, Assinante assinante, Livro livro){
        this.tituloAnuncio = tituloAnuncio;
        this.ativo = ativo;
        this.condicao = "troca";
        this.assinante = assinante;
        this.assinante.adicionarAnuncio(this);
        this.livro = livro;
    }
    
    /*
    Gets e sets
    */

    public void setTituloAnuncio(String tituloAnuncio){
        this.tituloAnuncio = tituloAnuncio;
    }

    public String getTituloAnuncio(){
        return this.tituloAnuncio;
    }

    public void setPreco(float preco){
        this.preco = preco;
        if(this.preco == 0){
            this.condicao = "troca";
        }else{
            this.condicao = "venda";
        }
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

    public void setCondicao(String condicao){
        this.condicao = condicao;
    }

    public String getCondicao(){
        return this.condicao;
    }

    public void setAssinante(Assinante assinante){
        this.assinante = assinante;
        this.assinante.adicionarAnuncio(this);
    }

    public Assinante getAssinante(){
        return this.assinante;
    }

    public void setLivro(Livro livro){
        this.livro = livro;
    }

    public Livro getLivro(){
        return this.livro;
    }

    public static void setListaAnuncios(ArrayList<Anuncio> lista){
        listaAnuncios = lista;
    }

    public static ArrayList<Anuncio> getListaAnuncios(){
        return listaAnuncios;
    }

    //////////////////////////////////////////////////////////////////////////////////////////////////////////

    public void setTituloAnuncio(String tituloAnuncio, boolean ativo){
        this.tituloAnuncio = tituloAnuncio;
        this.ativo = ativo;
    }

    public void setPreco(float preco, boolean ativo){
        this.preco = preco;
        if(this.preco == 0){
            this.condicao = "troca";
        }else{
            this.condicao = "venda";
        }
        this.ativo = ativo;
    }

    public void setCondicao(String condicao, boolean ativo){
        this.condicao = condicao;
        this.ativo = ativo;
    }

    public void setAssinante(Assinante assinante, boolean ativo){
        this.assinante = assinante;
        this.assinante.adicionarAnuncio(this);
        this.ativo = ativo;
    }

    public void setLivro(Livro livro, boolean ativo){
        this.livro = livro;
        this.ativo = ativo;
    }

    /*
    Metodos
    */

    public String dadosAnuncio(){
        return "Titulo do anuncio: " + this.tituloAnuncio + "//Preco: " + this.preco + "//Status: " + 
        this.ativo + "//Assinante: " + this.assinante.getNome() + "//Titulo do Livro: " + this.livro.getTitulo() +
        "//Isbn: " + this.livro.getIsbn() + "//Materia: " + this.livro.getMateria() + "//Edicao: " + this.livro.getEdicao() + 
        "//Ano: " + this.livro.getAno() + "//Ano de Publicacao: " + this.livro.getAnoPublicacao();
    }

    public void imprimeDadosAnuncio(){
        System.out.println("Titulo do anuncio: " + this.tituloAnuncio + "//Preco: " + this.preco + "//Status: " + 
        this.ativo + "//Assinante: " + this.assinante.getNome() + "//Titulo do Livro: " + this.livro.getTitulo() +
        "//Isbn: " + this.livro.getIsbn() + "//Materia: " + this.livro.getMateria() + "//Edicao: " + this.livro.getEdicao() + 
        "//Ano: " + this.livro.getAno() + "//Ano de Publicacao: " + this.livro.getAnoPublicacao());
    }

    public boolean ehAnuncioTroca(){
        if(this.condicao == "troca"){
            return true;
        }else{
            return false;
        }
    }

    public static void cadastrarAnuncio(){
        Scanner var = new Scanner(System.in);
        if(Assinante.getListaAssinantes().size() < 1){
            System.out.println("Anuncio nao pode ser cadastrado. Nao existem assinantes");
        }else if(Livro.getListaLivros().size() < 1){
            System.out.println("Anuncio nao pode ser cadastrado. Não existem livros");
        }else{
            boolean pass = false;//boolean para verificar se o assinante existe
            String nomeAssinante = "";
            System.out.println("Nome do assinante: ");
            nomeAssinante = var.nextLine();
            Assinante assinanteCadastrado = new Assinante("","","","");
            for(Assinante assinante : Assinante.getListaAssinantes()){
                if(assinante.getNome().equals(nomeAssinante)){
                    assinanteCadastrado = assinante;
                    pass = true;
                }else{
                    System.out.println("O assinante nao esta cadastrado");
                }
            }
            if (pass){
                boolean secondPass = false;//segundo boolean para verificar se o livro existe
                Livro livroCadastrado = new Livro("","","",0,0);
                String isbnLivro = "default";
                System.out.println("Isbn do livro: ");
                isbnLivro = var.nextLine();
                for(Livro livro : Livro.getListaLivros()){
                    if(livro.getIsbn().equals(isbnLivro)){
                        livroCadastrado = livro;
                        secondPass = true;
                    }else{
                        System.out.println("O assinante nao esta cadastrado");
                    }
                }
                if (secondPass){
                    String titulo = "";
                    float preco = 0;
                    boolean ativo = true;
                    System.out.println("Titulo do anúncio: ");
                    titulo = var.nextLine();
                    System.out.println("Preco do livro: ");
                    preco = var.nextInt();
                    
                    
                    Anuncio cadastrado = new Anuncio(titulo, preco, ativo, assinanteCadastrado, livroCadastrado);
                    listaAnuncios.add(cadastrado);
                    System.out.println("Anuncio criado");
                }
            }
        }
    }

    public static void removerAnuncio(){
        Scanner var = new Scanner(System.in);
        String titulo = "";

        System.out.print("Titulo do anuncio a ser removido: ");
        titulo = var.nextLine();
        
        for(Anuncio anuncio : listaAnuncios){
            if(anuncio.getTituloAnuncio().equals(titulo)){
                listaAnuncios.remove(anuncio);
                break;
            }
        }
    }

    public static void showAnuncios(){
        if(listaAnuncios.size() < 1){
            System.out.println("Não existem anúncios cadastrados");
        }else{
            for(Anuncio anuncio : listaAnuncios){
                anuncio.imprimeDadosAnuncio();
            }
        }
    }

}