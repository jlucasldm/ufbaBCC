//package gui;

import com.sun.jdi.DoubleType;

public abstract class Conta{
  private String nomeTitular;
  private String agencia;
  private double saldo;

  protected Conta(String nomeTitular, String agencia, double saldo){
        this.nomeTitular = nomeTitular;
        this.agencia = agencia;
        this.saldo = saldo;
  }

  public abstract boolean saque(double qtdSaque);

  public boolean deposito(double qtdDeposito){
    this.saldo = qtdDeposito;
    return true;
  }

  public String getNomeTitular(){
    return this.nomeTitular;
  }

  public void setNomeTitular(String nomeTitular){
    if(!(nomeTitular instanceof String)){
      throw new IllegalArgumentException("Apenas permitido String");
    }else{
      this.nomeTitular = nomeTitular;
    }
  }

  public String getAgencia(){
    return this.agencia;
  }

  public void setAgencia(String agencia){
    if (!(agencia instanceof String)) {
      throw new IllegalArgumentException("Apenas permitido String");
    } else {
      this.agencia = agencia;
    }
  }

  public double getSaldo(){
    return this.saldo;
  }

  public void setSaldo(Double saldo){
    if (!( saldo instanceof Double)) {
      throw new IllegalArgumentException("Apenas permitido double");
    } else {
      this.saldo = saldo;
    }
  }
}