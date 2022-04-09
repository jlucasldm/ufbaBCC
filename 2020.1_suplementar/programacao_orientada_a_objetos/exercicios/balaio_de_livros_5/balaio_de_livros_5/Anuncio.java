//João Lucas Lima de Melo
import java.util.Scanner;
import java.util.ArrayList;

public class Anuncio{
    private String tituloAnuncio;
    private boolean ativo;  //ativo ou inativo
    private Assinante assinante;
    private Livro livro;
    //private static ArrayList<Anuncio> listaAnuncios = new ArrayList<Anuncio>();

    public Anuncio(String tituloAnuncio, boolean ativo, Assinante assinante, Livro livro){
        this.tituloAnuncio = tituloAnuncio;
        this.ativo = ativo;
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

    public void setAtivo(boolean ativo){
        this.ativo = ativo;
    }

    public boolean getAtivo(){
        return this.ativo;
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

    /*
    public static void setListaAnuncios(ArrayList<Anuncio> lista){
        listaAnuncios = lista;
    }

    public static ArrayList<Anuncio> getListaAnuncios(){
        return listaAnuncios;
    }
    */

    //////////////////////////////////////////////////////////////////////////////////////////////////////////

    public void setTituloAnuncio(String tituloAnuncio, boolean ativo){
        this.tituloAnuncio = tituloAnuncio;
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

    /*
    public boolean ehAnuncioTroca(){
        if(this.condicao == "troca"){
            return true;
        }else{
            return false;
        }
    }
    */

}