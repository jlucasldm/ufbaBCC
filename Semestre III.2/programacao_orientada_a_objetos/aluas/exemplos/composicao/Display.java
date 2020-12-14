
/**
 * Escreva a descrição da classe Display aqui.
 * 
 * @author (seu nome) 
 * @version (número de versão ou data)
 */
public class Display
{
    // variáveis de instância - substitua o exemplo abaixo pelo seu próprio
    private int dimH;
    private int dimV;
    private String textoIni;
    /**
     * COnstrutor para objetos da classe Display
     */
    public Display(int dimH, int dimV, String textoIni)
    {
        this.dimH= dimH;
        this.dimV= dimV;
        this.textoIni = textoIni; 
    }

    public int getDimH(){
      return this.dimH;   
    }
    public int getDimV(){
      return this.dimV;   
    }
    public String getTextoIni(){
      return this.textoIni;   
    }
    public void setDimH (int dimH) {
        this.dimH = dimH;
    }   
}
