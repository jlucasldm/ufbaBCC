import java.util.ArrayList;

public class Biblioteca{
    private String nome;
    private String endereco;
    //private ArrayList<Publicacao> listaPublicacoes = new ArrayList<Publicacao>();
    private ArrayList<Livro> listaLivros = new ArrayList<Livro>();
    private ArrayList<Artigo> listaArtigos = new ArrayList<Artigo>();

    public Biblioteca(String nome, String endereco){
        this.nome = nome;
        this.endereco = endereco;
    }

    public void setNome(String nome){
        this.nome = nome;
    }

    public void setEndereco(String endereco){
        this.endereco = endereco;
    }

    public void setListaLivros(ArrayList<Livro> listaLivros){
        this.listaLivros = listaLivros;
    }

    public void setListaArtigos(ArrayList<Artigo> listaArtigos){
        this.listaArtigos = listaArtigos;
    }

    public String getNome(){
        return this.nome;
    }

    public String getEndereco(){
        return this.endereco;
    }

    public ArrayList<Livro> getListaLivros(){
        return this.listaLivros;
    }

    public ArrayList<Artigo> getListaArtigos(){
        return this.listaArtigos;
    }

    //metodos

    public void adicionarPublicacao(Livro livro){
        this.listaLivros.add(livro);
    }

    public void adicionarPublicacao(Artigo artigo){
        this.listaArtigos.add(artigo);
    }

    public void removerPublicacao(Livro livro){
        this.listaLivros.remove(livro);
    }

    public void removerPublicacao(Artigo artigo){
        this.listaArtigos.remove(artigo);
    }

    public boolean consultaPublicacao(Livro livro){
        for(Livro auxLivro : this.listaLivros){
            if(livro.getIsbn().equals(auxLivro.getIsbn())){
                System.out.println("Existem " + livro.getQtdCopias() + " cópia(s) do livro");
                return true;
            }
        }
        System.out.println("Não há cópias do livro");
        return false;
    }

    public boolean consultaPublicacao(Artigo artigo){
        for(Artigo auxArtigo : this.listaArtigos){
            if(artigo.getTitulo().equals(auxArtigo.getTitulo())){
                System.out.println("Existem " + artigo.getQtdCopias() + " cópia(s) do artigo");
                return true;
            }
        }
        System.out.println("Não há cópias do artigo");
        return false;
    }

    public boolean locarPublicacao(Livro livro){
        for(Livro auxLivro : this.listaLivros){
            if(livro.getIsbn().equals(auxLivro.getIsbn())){
                if(livro.getQtdCopias() == 0){
                    System.out.println("Não há cópias do livro");
                    return true;
                }else if(livro.getQtdCopias() == 1){
                    System.out.println("Há apenas uma cópia. Livro não pode ser locado");
                    return true;
                }else if(livro.getQtdCopias() == 2){
                    System.out.println("O livro será locado por um periodo de " + livro.getPeriodoLocacao()/2 + "dias");
                    livro.setQtdCopias(livro.getQtdCopias() - 1);
                    return true;
                }else{
                    System.out.println("O livro será locado por um periodo de " + livro.getPeriodoLocacao() + "dias");
                    livro.setQtdCopias(livro.getQtdCopias() - 1);
                    return true;
                }
            }
        }
        return false;
    }

    public boolean locarPublicacao(Artigo artigo){
        for(Artigo auxArtigo: this.listaArtigos){
            if(auxArtigo.getTitulo().equals(artigo.getTitulo())){
                if(artigo.getQtdCopias() == 0){
                    System.out.println("Não há cópias do artigo");
                    return true;
                }else if(artigo.getAnoPublicacao() == "2020"){
                    System.out.println("O artigo será locado por um periodo de " + artigo.getPeriodoLocacao()/4 + "dias");
                    artigo.setQtdCopias(artigo.getQtdCopias() - 1);
                    return true;
                }else{
                    System.out.println("O artigo será locado por um periodo de " + artigo.getPeriodoLocacao() + "dias");
                    artigo.setQtdCopias(artigo.getQtdCopias() - 1);
                    return true;
                }
            }
        }
        return false;
    }

    public boolean devolverPublicacao(Livro livro){
        for(Livro auxLivro : this.listaLivros){
            if(livro.getIsbn().equals(auxLivro.getIsbn())){
                livro.setQtdCopias(livro.getQtdCopias()+1);
                return true;
            }
        }
        this.listaLivros.add(livro);
        return true;
    }

    public boolean devolverPublicacao(Artigo artigo){
        for(Artigo auxArtigo : this.listaArtigos){
            if(artigo.getTitulo().equals(auxArtigo.getTitulo())){
                artigo.setQtdCopias(artigo.getQtdCopias()+1);
                return true;
            }
        }
        this.listaArtigos.add(artigo);
        return true;
    }
}