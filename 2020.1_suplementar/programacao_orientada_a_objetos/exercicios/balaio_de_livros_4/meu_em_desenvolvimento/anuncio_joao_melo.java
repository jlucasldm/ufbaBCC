//João Lucas Lima de Melo
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
        System.out.println("Titulo do anuncio: " + this.tituloAnuncio + "\nPreco: " + this.preco + "\nStatus: " + 
        this.ativo + "\nAssinante: " + this.assinante.getNome() + "\nTitulo do Livro: " + this.livro.getTitulo() +
        "\nIsbn: " + this.livro.getIsbn() + "\nMateria: " + this.livro.getMateria() + "\nEdicao: " + this.livro.getEdicao() + 
        "\nAno: " + this.livro.getAno() + "\nAno de Publicacao: " + this.livro.getAnoPublicacao());
    }

    public boolean ehAnuncioTroca(){
        if(this.condicao == "troca"){
            return true;
        }else{
            return false;
        }
    }

    //método que solicita dados do usuário para criar uma instancia de Anuncio, inserindo-a no arrayList da classe. 
    //É conferido a existencia do assinante e livros cadastrados.
    public static void cadastrarAnuncio(){
        Scanner var = new Scanner(System.in);
        if(Assinante.getListaAssinantes().size() < 1){
            System.out.println("Anuncio nao pode ser cadastrado. Nao existem assinantes\n");
        }else if(Livro.getListaLivros().size() < 1){
            System.out.println("Anuncio nao pode ser cadastrado. Não existem livros\n");
        }else{
            boolean assinanteExiste = false;
            String nomeAssinante = "";
            System.out.println("Nome do assinante: \n");
            nomeAssinante = var.nextLine();
            Assinante assinanteCadastrado = new Assinante("","","","");
            for(Assinante assinante : Assinante.getListaAssinantes()){
                if(assinante.getNome().equals(nomeAssinante)){
                    assinanteCadastrado = assinante;
                    pass = true;
                }else{
                    System.out.println("O assinante nao esta cadastrado\n");
                }
            }
            if (assinanteExiste){
                boolean livroExiste = false;
                Livro livroCadastrado = new Livro("","","",0,0);
                String isbnLivro = "";
                System.out.println("Isbn do livro: \n");
                isbnLivro = var.nextLine();
                for(Livro livro : Livro.getListaLivros()){
                    if(livro.getIsbn().equals(isbnLivro)){
                        livroCadastrado = livro;
                        secondPass = true;
                    }else{
                        System.out.println("O livro nao esta cadastrado\n");
                    }
                }
                if (livroExiste){
                    String titulo = "";
                    float preco = 0;
                    boolean ativo = true;
                    System.out.println("Titulo do anúncio: \n");
                    titulo = var.nextLine();
                    System.out.println("Preco do livro: \n");
                    preco = var.nextInt();
                    
                    
                    Anuncio cadastrado = new Anuncio(titulo, preco, ativo, assinanteCadastrado, livroCadastrado);
                    listaAnuncios.add(cadastrado);
                    System.out.println("Anuncio criado\n");
                }
            }
        }
    }

    //metodo para remover uma instancia de Anuncio do arrayList da classe, usando o titulo como chave de busca
    public static void removerAnuncio(){
        Scanner var = new Scanner(System.in);
        String titulo = "";

        System.out.print("Titulo do anuncio a ser removido: \n");
        titulo = var.nextLine();
        
        for(Anuncio anuncio : listaAnuncios){
            if(anuncio.getTituloAnuncio().equals(titulo)){
                listaAnuncios.remove(anuncio);
                break;
            }
        }
    }

    //metodo para percorrer o arrayList da classe, iterando sobre as instancias de anuncios e imprimindo suas informações
    public static void showAnuncios(){
        if(listaAnuncios.size() < 1){
            System.out.println("Não existem anúncios cadastrados\n");
        }else{
            for(Anuncio anuncio : listaAnuncios){
                anuncio.imprimeDadosAnuncio();
            }
        }
    }

}