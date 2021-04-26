
/**
 * Escreva a descrição da classe Pessoa aqui.
 * 
 * @author (seu nome) 
 * @version (número de versão ou data)
 */
public class Pessoa
{
    // variáveis de instância - substitua o exemplo abaixo pelo seu próprio
    private int cpf;
    private String nome;
    private String endereco;

    /**
     * COnstrutor para objetos da classe Pessoa
     */
    public Pessoa(int cpf, String nome, String endereco)
    {
       this.cpf=cpf;
       this.nome=nome;
       this.endereco=endereco;
    }
    public String toString(){
        return("Nome : "+this.nome + " Cpf : "+ this.cpf + " Endereço = "+this. endereco); 
    }
    public int getCpf()
    {
        
        return this.cpf;
    }
    
}
