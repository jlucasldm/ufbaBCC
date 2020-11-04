//Joao Lucas Lima de Melo
public class Cliente{
    private String nome;
    private String cpf;
    private int acompanhantes;
    private float conta;
    private int qtdPratosConsumidos;
    private Prato[] pratos;    //maximo de trinta

    public Cliente(String nome, String cpf, int acompanhantes){
        this.nome = nome;
        this.cpf = cpf;
        this.acompanhantes = acompanhantes;
        this.conta = 0;
        this.qtdPratosConsumidos = 0;
        this.pratos = new Prato[30];
    }

    public Cliente(String nome, String cpf){
        this.nome = nome;
        this.cpf = cpf;
        this.acompanhantes = 1;
        this.conta = 0;
        this.qtdPratosConsumidos = 0;
        this.pratos = new Prato[30];
    }

    //gets e sets

    public void setNome(String nome){
        this.nome = nome;
    }

    public void setCpf(String cpf){
        this.cpf = cpf;
    }

    public void setAcompanhantes(int acompanhantes){
        this.acompanhantes = acompanhantes;
    }

    public void setConta(float conta){
        this.conta = conta;
    }

    public void setQtdPratosConsumidos(int qtdPratosConsumidos){
        this.qtdPratosConsumidos = qtdPratosConsumidos;
    }

    public void setPratos(Prato[] pratos){
        this.pratos = pratos;
    }

    public String getNome(){
        return this.nome;
    }

    public String getCpf(){
        return this.cpf;
    }

    public float getAcompanhantes(){
        return this.acompanhantes;
    }

    public float getConta(){
        return this.conta;
    }

    public int getQtdPratosConsumidos(){
        return this.qtdPratosConsumidos;
    }

    public Prato[] getPratos(){
        return this.pratos;
    }

    //metodos

    public void imprimirConta(){
        System.out.println("Cliente: "+this.nome+"\nCpf: "+this.cpf);
        for(int i = 0; i < this.pratos.length; i++){
            if(this.pratos[i] != null){
               System.out.println("\nPrato: "+this.pratos[i].getNome()+"--------Valor: "+this.pratos[i].getValor());
            }
        }
        System.out.println("\nTotal: "+this.conta);
    }

    public boolean fazerPedido(Prato prato){
        for(int i = 0; i < this.pratos.length; i++){
            if(this.pratos[i] == null){
                this.pratos[i] = prato;
                this.qtdPratosConsumidos++;
                this.conta += this.pratos[i].getValor();
                return true;
            }
        }
        return false;
    }

    public boolean fazerPedido(Prato prato, int qtdPrato){
        int qtdRestante = 0;
        for(int i = 0; i < this.pratos.length; i++){
            if(this.pratos[i] == null){
                qtdRestante++;
            }
        }
        if(qtdRestante >= qtdPrato){
            int adicionar = qtdPrato;
            for(int i = 0; i < this.pratos.length; i++){
                if(this.pratos[i] == null){
                    this.pratos[i] = prato;
                    this.qtdPratosConsumidos++;
                    this.conta += this.pratos[i].getValor();
                    adicionar--;
                    if(adicionar == 0){
                        return true;
                    }
                }
            }
        }
        return false;
    }
}