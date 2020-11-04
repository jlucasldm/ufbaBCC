public class Anuncio{
    private String tituloAnuncio;
    private float preco;    //0 se for troca
    private boolean ativo;  //ativo ou inativo
    private String condicao;    //troca ou venda;
    private Assinante assinante;
    private Livro livro;

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
        this.assinante.setAnuncios(this);
        this.livro = livro;
    }

    public Anuncio(String tituloAnuncio, boolean ativo, Assinante assinante, Livro livro){
        this.tituloAnuncio = tituloAnuncio;
        this.ativo = ativo;
        this.condicao = "troca";
        this.assinante = assinante;
        this.assinante.setAnuncios(this);
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
        this.assinante.setAnuncios(this);
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
        this.assinante.setAnuncios(this);
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

    public boolean ehAnuncioTroca(){
        if(this.condicao == "troca"){
            return true;
        }else{
            return false;
        }
    }

}