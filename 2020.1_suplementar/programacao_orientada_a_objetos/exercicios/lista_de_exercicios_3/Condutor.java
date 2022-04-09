public class Condutor{
    private String nome;
    private int identificacao;
    private Carteira carteira;

    public Condutor(String nome, int identificacao, Carteira carteira){
        this.nome = nome;
        this.identificacao = identificacao;
        this.carteira = carteira;
    }

    public Condutor(String nome, int identificacao){
        this.nome = nome;
        this.identificacao = identificacao;
    }

    public Condutor(String nome, int identificacao, int numero, String status, String categoria, int pontos){
        this.nome = nome;
        this.identificacao = identificacao;
        this.carteira = new Carteira(numero, status, categoria, pontos);
    }

    public void setNome(String nome){
        this.nome = nome;
    }

    public void setIdentificacao(int identificacao){
        this.identificacao = identificacao;
    }

    public void setCarteira(Carteira carteira){
        this.carteira = carteira;
    }

    public String getNome(){
        return this.nome;
    }

    public int getIdentificacao(){
        return this.identificacao;
    }

    public Carteira getCarteira(){
        return this.carteira;
    }

    public void modificarCategoria(String categoria){
        this.carteira.setCategoria(categoria);
    }

    public void incluirPontos(int pontos){
        this.carteira.setPontos(this.carteira.getPontos()+pontos);
        if(this.carteira.getPontos() > 30){
            this.carteira.setStatus("cancelada");
        }else{
            this.carteira.setStatus("ativa");
        }
    }

    public int consultarPontos(){
        return this.carteira.getPontos();
    }

    public boolean estaCancelada(){
        if(this.carteira.getStatus() == "cancelada" || this.carteira.getPontos() > 30){
            return true;
        }else{
            return false;
        }
    }
}