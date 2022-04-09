public class Carteira{
    private int numero;
    private String status;  //ativa ou cancelada
    private String categoria;
    private int pontos;

    public Carteira(int numero, String status, String categoria, int pontos){
        this.numero = numero;
        this.status = status;
        this.categoria = categoria;
        this.pontos = pontos;
    }

    public void setNumero(int numero){
        this.numero = numero;
    }

    public void setStatus(String status){
        this.status = status;
    }

    public void setCategoria(String categoria){
        this.categoria = categoria;
    }

    public void setPontos(int pontos){
        this.pontos = pontos;
    }

    public int getNumero(){
        return this.numero;
    }

    public String getStatus(){
        return this.status;
    }

    public String getCategoria(){
        return this.categoria;
    }

    public int getPontos(){
        return this.pontos;
    }
}