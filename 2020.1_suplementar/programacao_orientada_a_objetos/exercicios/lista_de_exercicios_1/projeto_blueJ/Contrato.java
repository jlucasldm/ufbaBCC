public class Contrato{
    private int numero;
    private float valorAluguel;
    private int meses;
    private int prestacoesPagas;
    private int prestacoesAtrasadas;
    private float juros;    //juros por prestacao atrasada
    private int mesesParaDespejo;
    private String situacao;    //ativo ou inativo
    private Fiador fiador;

    public Contrato(int numero, float valorAluguel, int meses, int prestacoesPagas, int prestacoesAtrasadas, float juros, int mesesParaDespejo, String situacao, Fiador fiador){
        this.numero = numero;
        this.valorAluguel = valorAluguel;
        this.meses = meses;
        this.prestacoesPagas = prestacoesPagas;
        this.prestacoesAtrasadas = prestacoesAtrasadas;
        this.juros = juros;
        this.mesesParaDespejo = mesesParaDespejo;
        this.fiador = fiador;
        if(this.fiador.getRendaMensal()*3 <= this.valorAluguel){
            this.situacao = "inativo";
        }else{
            this.situacao = situacao;
        }
    }

    public Contrato(int numero, float valorAluguel, int meses, int prestacoesPagas, int prestacoesAtrasadas, float juros, int mesesParaDespejo, String situacao, String nome, int cpf, float rendaMensal){
        this.numero = numero;
        this.valorAluguel = valorAluguel;
        this.meses = meses;
        this.prestacoesPagas = prestacoesPagas;
        this.prestacoesAtrasadas = prestacoesAtrasadas;
        this.juros = juros;
        this.mesesParaDespejo = mesesParaDespejo;
        this.fiador = new Fiador(nome, cpf, rendaMensal);
        if(this.fiador.getRendaMensal()*3 <= this.valorAluguel){
            this.situacao = "inativo";
        }else{
            this.situacao = situacao;
        }
    }

    public void setNumero(int numero){
        this.numero = numero;
    }

    public int getNumero(){
        return this.numero;
    }

    public void setValorAluguel(float valorAluguel){
        this.valorAluguel = valorAluguel;
    }

    public float getValorAluguel(){
        return this.valorAluguel;
    }

    public void setMeses(int meses){
        this.meses = meses;
    }

    public int getMeses(){
        return this.meses;
    }

    public void setPrestacoesPagas(int prestacoesPagas){
        this.prestacoesPagas = prestacoesPagas;
    }

    public int getPrestacoesPagas(){
        return this.prestacoesPagas;
    }

    public void setPrestacoesAtrasadas(int prestacoesAtrasadas){
        this.prestacoesAtrasadas = prestacoesAtrasadas;
    }

    public int getPrestacoesAtrasadas(){
        return this.prestacoesAtrasadas;
    }

    public void setJuros(float juros){
        this.juros = juros;
    }

    public float getJuros(){
        return this.juros;
    }

    public void setMesesParaDespejo(int mesesParaDespejo){
        this.mesesParaDespejo = mesesParaDespejo;
    }

    public int getMesesParaDespejo(){
        return this.mesesParaDespejo;
    }

    public void setSituacao(String situacao){
        this.situacao = situacao;
    }

    public String getSituacao(){
        return this.situacao;
    }

    public void setFiador(Fiador fiador){
        this.fiador = fiador;
        if(this.fiador.getRendaMensal()*3 <= this.valorAluguel){
            this.situacao = "inativo";
        }
    }

    public void setFiador(String nome, int cpf, float rendaMensal){
        this.fiador = new Fiador(nome, cpf, rendaMensal);
        if(this.fiador.getRendaMensal()*3 <= this.valorAluguel){
            this.situacao = "inativo";
        }
    }

    public Fiador getFiador(){
        return this.fiador;
    }

    public float prestacaoSemJuros(){
        return this.valorAluguel;
    }

    public float prestacaoUmMesAtraso(){
        return this.valorAluguel+(this.valorAluguel*this.juros/100);
    }

    public void pagarPrestacaoSemJuros(){
        this.prestacoesPagas++;
    }

    public boolean despejo(){
        if(this.meses - this.prestacoesPagas <= 6){
            return false;
        }else if(this.prestacoesAtrasadas >= this.mesesParaDespejo){
            return true;
        }else{
            return false;
        }
    }

    public void modificarRendaFiador(float renda){
        this.fiador.setRendaMensal(renda);
        if(this.fiador.getRendaMensal()*3 <= this.valorAluguel){
            this.situacao = "inativo";
        }
    }

}