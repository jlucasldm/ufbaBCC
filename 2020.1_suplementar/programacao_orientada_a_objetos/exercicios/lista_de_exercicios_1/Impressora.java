public class Impressora {
    private String fabricante;
    private String modelo;
    private int capacidadeImpressao;
    private String tecnologia;
    private float velocidade;

    public Impressora(String fabricante, String modelo, int capacidadeImpressao, String tecnologia, float velocidade){
        this.fabricante = fabricante;
        this.modelo = modelo;
        this.capacidadeImpressao = capacidadeImpressao;
        this.tecnologia = tecnologia;
        this.velocidade = velocidade;
    }

    public void setFabricante(String fabricante){
        this.fabricante = fabricante;
    }

    public void setModelo(String modelo){
        this.modelo = modelo;
    }

    public void setCapacidadeImpressao(int capacidadeImpressao){
        this.capacidadeImpressao = capacidadeImpressao;
    }

    public void setTecnologia(String tecnologia){
        this.tecnologia = tecnologia;
    }

    public void setVelocidade(float velocidade){
        this.velocidade = velocidade;
    }

    public String getFabricante(){
        return this.fabricante;
    }

    public String getModelo(){
        return this.modelo;
    }

    public int getCapacidadeImpressao(){
        return this.capacidadeImpressao;
    }

    public String getTecnologia(){
        return this.tecnologia;
    }

    public float getVelocidade(){
        return this.velocidade;
    }

    public float tempoImpressao(int numeroPaginas){
        return numeroPaginas/this.velocidade;
    }

    public void imprimir(String texto){
        System.out.println(texto);
        this.capacidadeImpressao--;
    }
}