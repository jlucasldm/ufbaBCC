public class Automovel{
    private String tipoCombustivel;
    private String fabricante;
    private int ano;
    private String modelo;

    public Automovel(String tipoCombustivel, String fabricante, int ano, String modelo){
        this.tipoCombustivel = tipoCombustivel;
        this.fabricante = fabricante;
        this.ano = ano;
        this.modelo = modelo;
    }

    //precisa colocar os gets e sets
    public void setTipoCombustivel(String tipoCombustivel){
        this.tipoCombustivel = tipoCombustivel;
    }

    public String getTipoCombustivel(){
        return this.tipoCombustivel;
    }

    public float combustivelParaViajar(float quilometragem){
        if(this.tipoCombustivel == "gasolina"){
            return quilometragem/12;
        }else if(this.tipoCombustivel == "alcool"){
            return quilometragem/15;
        }else{
            return (quilometragem/30)+(quilometragem/24);
        }
    }
}