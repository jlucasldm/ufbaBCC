//package gui;

public class Poupanca extends Conta{
  private double rendimento;
  private double mes;

  public Poupanca(String nomeTitular, String agencia, double saldo, double rendimento, double mes){
    super(nomeTitular,agencia,saldo);
    this.rendimento = rendimento;
    this.mes = mes;
  }

  public boolean saque(double qtdSaque){
    if(qtdSaque > (getSaldo() + (rendimento * mes))){
      return false;
    }
    else{
      setSaldo((getSaldo() + (rendimento * mes)) - qtdSaque);
      return true;
    }
  }

  public String toString(){
    return super.toString() + ", " + this.rendimento;
  }
}