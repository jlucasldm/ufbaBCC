import java.util.ArrayList;
import java.util.Scanner;
/**
 * Escreva a descrição da classe Assinante aqui.
 * 
 * @author (Linsmar da Silva Vital) 
 * @version (20200925)
 */
public class Assinante
{
    // variáveis de instância - substitua o exemplo abaixo pelo seu próprio
    private String cpf;
    private String nome;
    private String endereco;
    private String telefone;
    private ArrayList<Anuncio> anuncios;
    private static ArrayList<Assinante> todosAssinantes = new ArrayList<Assinante>();

    /**
     * COnstrutor para objetos da classe Assinante
     */
    public Assinante(String cpf, String nome, String endereco, String telefone)
    {
        String ddd = "71";
        this.cpf = cpf;
        this.nome = nome;
        this.endereco = endereco;
        if (telefone.length() < 11) this.telefone = ddd.concat(telefone);
        else this.telefone = telefone;
        this.anuncios = new ArrayList<Anuncio>();
    }

    /**
     * 
     */
    //Método para cadastrar um novo assinante pelo menu
    public static void cadastrarAssinante(){
        Scanner var = new Scanner(System.in);
        String cpf = "default";
        String nome = "default";
        String endereco = "default";
        String telefone = "default";
        System.out.println("Informe seu cpf: ");
        cpf = var.nextLine();
        System.out.println("Informe seu nome: ");
        nome = var.nextLine();
        System.out.println("Informe seu endereço: ");
        endereco = var.nextLine();
        System.out.println("Informe seu telefone: ");
        telefone = var.nextLine();
        
        Assinante novo = new Assinante(cpf, nome, endereco, telefone);
        todosAssinantes.add(novo);
        System.out.println("Assinante criado");
    }
    public void consulta(String valor)
    {
        if (nome.equals(valor)){
                System.out.println("------\n" + "Consulta:\n" + "Nome: " + this.nome + "\nCPF: " + this.cpf +
             "\nEndereço: " + this.endereco + "\nTelefone: " + this.telefone);
        }
        else {
            if (telefone.equals(valor)){
                    System.out.println("------\n" + "Consulta:\n" + "Nome: " + this.nome + "\nCPF: " + this.cpf +
                 "\nEndereço: " + this.endereco + "\nTelefone: " + this.telefone);
            }
            else System.out.println("Nome/telefone incorreto");
        }
    }
    public String getCpf() {
        return this.cpf;
    }
    public String getNome() {
        return this.nome;
    }
    public String getEndereco() {
        return this.endereco;
    }
    public String getTelefone() {
        return this.telefone;
    }
    public ArrayList<Anuncio> getAnuncios(){
        return this.anuncios;
    }
    public static ArrayList<Assinante> getTodosAssinantes(){
        return todosAssinantes;
    }
    
    public void setCpf(String cpf) {
        this.cpf = cpf;
    }
    public void setNome(String nome) {
        this.nome = nome;
    }
    public void setEndereco(String endereco) {
        this.endereco = endereco;
    }
    public void setTelefone(String telefone) {
        this.telefone = telefone;
    }
    public void setAnuncios(ArrayList<Anuncio> a){
        this.anuncios = a;
    }
}
