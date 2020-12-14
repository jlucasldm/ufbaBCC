
public class Conta
{
    private Pessoa titular;
    private int numero;
    private int agencia;
    private float saldo;
    
    public Conta(Pessoa titular, int numero, int agencia, float saldo)
    {
        this.titular =titular;
        this.numero = numero;
        this.agencia = agencia;
        this.saldo = saldo;
    }
    public void consutaSaldo () {
        
        System.out.println ("=== Cliente ===");
        System.out.println (this.titular.toString());
        System.out.println ("=== Dados da Conta ===");
        System.out.println ("Agencia : "+this.agencia+" Numero: "+ this.numero);
        System.out.println ("Saldo : ="+ this.saldo);
    }
    public boolean saque(float valor)
    {
        if(valor <= saldo)
        {
            saldo = saldo - valor;
            return true;
        }
        return false;
    }
    
    public void deposito(float valor)
    {
        saldo = saldo + valor;
    }  
    
    public float getSaldo()
    {
        return saldo;
    }
}

