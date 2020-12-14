public class Curso{
    private String id;
    private String nome;
    private String area;
    private int qtdVagas;
    private float taxaMatricula;
    
    public Curso(String id, String nome, String area, int qtdVagas, float taxaMatricula){
        this.id = id;
        this.nome = nome;
        this.area = area;
        this.qtdVagas = qtdVagas;
        this.taxaMatricula = taxaMatricula;
    }

    public void setId(String id){
        this.id = id;
    }

    public void setNome(String nome){
        this.nome = nome;
    }

    public void setArea(String area){
        this.area = area;
    }

    public void setQtdVagas(int qtdVagas){
        this.qtdVagas = qtdVagas;
    }

    public void setTaxaMatricula(float taxaMatricula){
        this.taxaMatricula = taxaMatricula;
    }

    public String getId(){
        return this.id;
    }

    public String getNome(){
        return this.nome;
    }

    public String getArea(){
        return this.area;
    }

    public int getQtdVagas(){
        return this.qtdVagas;
    }

    public float getTaxaMatricula(){
        return this.taxaMatricula;
    }
}