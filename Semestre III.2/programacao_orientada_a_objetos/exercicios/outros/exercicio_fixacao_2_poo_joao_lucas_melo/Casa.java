
/**
 * Escreva a descrição da classe casa aqui.
 * 
 * @author (seu nome) 
 * @version (número de versão ou data)
 */
public class Casa
{
    // variáveis de instância - substitua o exemplo abaixo pelo seu próprio
    private int numero;
    private String cor;
    private int qtdQuartos;
    
    /**
     * COnstrutor para objetos da classe casa
     */
    public Casa(int n, String c, int qtd)
    {
        // inicializa variáveis de instância
        numero = n;
        cor = c;
        qtdQuartos = qtd;
    }

    /**
     * Exemplo de método - substitua este comentário pelo seu próprio
     * 
     * @param  y   exemplo de um parâmetro de método
     * @return     a soma de x com y 
     */
    public int getNumero()
    {
        // ponha seu código aqui
        return numero;
    }
    public int getQuartos(){
        return qtdQuartos;
    }
    public String getCor(){
        return cor;
    }
    public void setCor(String c){
        cor = c;
    }
}
