

/**
 * Escreva a descrição da classe Celular aqui.
 * 
 * @author (seu nome) 
 * @version (número de versão ou data)
 */
public class Celular
{
    // variáveis de instância - substitua o exemplo abaixo pelo seu próprio
    private String modelo;
    private int numDiscado;
    private Display display;

    /**
     * COnstrutor para objetos da classe Celular
     */
    public Celular(String modelo, int numDiscado, Display display)
    {
       this.modelo = modelo;
       this.numDiscado = numDiscado;
       this.display = display;
    }
    public Celular(String modelo, int numDiscado, int dimH, int dimV, String texto)
    {
       this.modelo = modelo;
       this.numDiscado = numDiscado;
       this.display = new Display (dimH, dimV,texto);
    }
    
    public String getTextoIni(){
       return this.display.getTextoIni(); 
    }
}