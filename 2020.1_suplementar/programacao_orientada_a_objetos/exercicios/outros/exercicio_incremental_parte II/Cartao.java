public class Cartao
{
    private Destinatario destinatario;
    private String emissario;
    private String mensagem;
    private String horarioEntrega;
    private String custo;

    public Cartao(Destinatario destinatario, String emissario, String mensagem, String horarioEntrega, String custo){
        this.destinatario = destinatario;
        this.emissario = emissario;
        this.mensagem = mensagem;
        this.horarioEntrega = horarioEntrega;
        this.custo = custo;
    }

    public Cartao(String nome, String endereco, String horarioEntrega){
        this.destinatario = new Destinatario(nome, endereco);
        this.emissario = "";
        this.mensagem = "";
        this.horarioEntrega = horarioEntrega;
        this.custo = "";
    }

    public Cartao(String nome, String endereco){
        this.destinatario = new Destinatario(nome, endereco);
        this.emissario = "";
        this.mensagem = "";
        this.horarioEntrega = "0000";
        this.custo = "";
    }

    public void setDestinatario(Destinatario destinatario){
        this.destinatario = destinatario;
    }

    public void setEmissario(String emissario){
        this.emissario = emissario;
    }

    public void setMensagem(String mensagem){
        this.mensagem = mensagem;
    }

    public void setHorarioEntrega(String horarioEntrega){
        this.horarioEntrega = horarioEntrega;
    }

    public void setCusto(String custo){
        this.custo = custo;
    }

    public Destinatario getDestinatario(){
        return this.destinatario;
    }

    public String getEmissario(){
        return this.emissario;
    }

    public String getMensagem(){
        return this.mensagem;
    }

    public String getHorarioEntrega(){
        return this.horarioEntrega;
    }

    public String getCusto(){
        return this.custo;
    }

    public void mostraDadosCartao(){
        System.out.println(
        "Destinatário: " + this.destinatario.getNome() +
        "\nEndereco: " + this.destinatario.getEndereco()+
        "\nEmissario: " + this.emissario +
        "\nMensagem: " + this.mensagem +
        "\nHorario de Entrega: " + this.horarioEntrega +
        "\nCusto: " + this.custo);
    }
}