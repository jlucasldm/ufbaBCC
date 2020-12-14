import java.util.ArrayList;

public class Artigo extends Publicacao{
    private String autores;
    private String resumo;

    public Artigo(String titulo, String anoPublicacao, String veiculoPublicacao, int qtdCopias, String autores, String resumo){
        super(titulo, anoPublicacao, veiculoPublicacao, qtdCopias);
        this.autores = autores;
        this.resumo = resumo;
    }

    public void setAutores(String autores){
        this.autores = autores;
    }

    public void setResumo(String resumo){
        this.resumo = resumo;
    }

    public String getAutores(){
        return this.autores;
    }

    public String getResumo(){
        return this.resumo;
    }
}