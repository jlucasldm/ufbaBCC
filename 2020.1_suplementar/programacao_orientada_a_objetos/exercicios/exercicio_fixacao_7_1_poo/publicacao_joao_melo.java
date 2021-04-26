//João Lucas Lima de Melo
public class Publicacao{
    private String titulo;
    private String anoPublicacao;
    private String veiculoPublicacao;
    private int qtdCopias;
    private static float periodoLocacao;

    public Publicacao(String titulo, String anoPublicacao, String veiculoPublicacao, int qtdCopias){
        this.titulo = titulo;
        this.anoPublicacao = anoPublicacao;
        this.veiculoPublicacao = veiculoPublicacao;
        this.qtdCopias = qtdCopias;
    }

    public void setTitulo(String titulo){
        this.titulo = titulo;
    }

    public void setAnoPublicacao(String anoPublicacao){
        this.anoPublicacao = anoPublicacao;
    }

    public void setVeiculoPublicacao(String veiculoPublicacao){
        this.veiculoPublicacao = veiculoPublicacao;
    }

    public void setQtdCopias(int qtdCopias){
        this.qtdCopias = qtdCopias;
    }

    public static void setPeriodoLocacao(float newPeriodoLocacao){
        periodoLocacao = newPeriodoLocacao;
    }

    public String getTitulo(){
        return this.titulo;
    }

    public String getAnoPublicacao(){
        return this.anoPublicacao;
    }

    public String getVeiculoPublicacao(){
        return this.veiculoPublicacao;
    }

    public int getQtdCopias(){
        return this.qtdCopias;
    }

    public static float getPeriodoLocacao(){
        return periodoLocacao;
    }
}