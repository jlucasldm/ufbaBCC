public class Televisao{
    private String marca;
    private String modelo;
    private int status; //ligado ou desligado
    private int canalAtual;
    private String senha;
    private int hora;

    public Televisao(String marca, String modelo, int status, int canalAtual, String senha, int hora){
        this.marca = marca;
        this.modelo = modelo;
        this.status = status;
        this.canalAtual = canalAtual;
        this.senha = senha;
        this.hora = hora;
    }

    //gets e sets

    public void ligarTVManual(){
        this.status = 1;
    }

    public void ligarTVRede(int canal, String senha){
        if(this.senha == senha){
            this.status = 1;
            this.canalAtual = canal;
        }
    }

    public void agendarGravacao(int canal, int horaProgramada){
        if(this.hora == horaProgramada){
            this.status = 1;
            this.canalAtual = canal;
        }
    }

}