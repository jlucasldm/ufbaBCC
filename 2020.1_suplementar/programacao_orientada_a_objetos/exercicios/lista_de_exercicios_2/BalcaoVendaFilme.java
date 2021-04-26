public class BalcaoVendaFilme{
    private String nomeFilme;
    private String valorIngresso;   //meia ou inteira
    private String poltrona;
    private String lanche;

    public BalcaoVendaFilme(String nomeFilme, String valorIngresso, String poltrona, String lanche){
        this.nomeFilme = nomeFilme;
        this.valorIngresso = valorIngresso;
        this.poltrona = poltrona;
        this.lanche = lanche;
    }

    public BalcaoVendaFilme(String nomeFilme, String valorIngresso){
        this.nomeFilme = nomeFilme;
        this.valorIngresso = valorIngresso;
        this.poltrona = "";
        this.lanche = "";
    }

    public BalcaoVendaFilme(String nomeFilme, String valorIngresso, String poltrona){
        this.nomeFilme = nomeFilme;
        this.valorIngresso = valorIngresso;
        this.poltrona = poltrona;
        this.lanche = "";
    }

    public BalcaoVendaFilme(String nomeFilme, String valorIngresso, String lanche){
        this.nomeFilme = nomeFilme;
        this.valorIngresso = valorIngresso;
        this.poltrona = "";
        this.lanche = lanche;
    }

}