
/**
* Enumeration class Disciplina - write a description of the enum class here
* 
* @author (Linsmar da Silva Vital)
* @version (20201025)
*/
public enum Disciplina{
    PT("Português"), 
    MAT("Matemática"), 
    CIE("Ciências"), 
    HIS("História"),
    GEO("Geografia"),
    ING("Inglês"),
    ESP("Espanhol");
    
    public String nome;
    
    Disciplina(String nome){
        this.nome = nome;
    }
    public String getNome(){
        return this.nome;
    }
}
