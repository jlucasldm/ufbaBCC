import java.util.Scanner;
import java.util.ArrayList;

public class Assinante
{
    // variáveis de instância
    private String cpf;
    private String nome;
    private String endereco;
    private String telefone;
    private ArrayList<Anuncio> anuncios;
    //private Anuncio[] anuncios;
    private static ArrayList<Assinante> listaAssinantes = new ArrayList<Assinante>();

    /*
    Construtor para objetos da classe Assinante
    */

    public Assinante(String cpf, String nome, String endereco, String telefone)
    {
        // inicializa variáveis de instância
        this.cpf = cpf;
        this.nome = nome;
        this.endereco = endereco;
        if(telefone.length() <= 9){
            this.telefone = "71"+telefone;
        }else{
            this.telefone = telefone;
        }
        //this.anuncios = new Anuncio[100];
        this.anuncios = new ArrayList<Anuncio>();
    }
    
    //gets e sets
    public String getCpf(){
        return this.cpf;
    }
    
    public String getNome(){
        return this.nome;
    }
    
    public String getEndereco(){
        return this.endereco;
    }
    
    public String getTelefone(){
        return this.telefone;
    }

    /*
    public Anuncio[] getAnuncios(){
        return this.anuncios;
    }
    */

    public ArrayList<Anuncio> getAnuncios(){
        return this.anuncios;
    }

    public static ArrayList<Assinante> getListaAssinantes(){
        return listaAssinantes;
    }
    
    public void setCpf(String cpf){
        this.cpf = cpf;
    }
    
    public void setNome(String nome){
        this.nome = nome;
    }
    
    public void setEndereco(String endereco){
        this.endereco = endereco;
    }
    
    public void setTelefone(String telefone){
        if(telefone.length() <= 9){
            this.telefone = "71"+telefone;
        }else{
            this.telefone = telefone;
        }
    }

    /*
    public void setAnuncios(Anuncio anuncios){
        for(int i = 0; i < this.anuncios.length; i++){
            if(this.anuncios[i] == null){
                this.anuncios[i] = anuncios;
                break;
            }
        }
    }*/

    public void setAnuncios(ArrayList<Anuncio> anuncios){
        this.anuncios = anuncios;
    }

    public static void setListaAssinantes(ArrayList<Assinante> lista){
        listaAssinantes = lista;
    }

    //métodos
    public String consultaAssinante(){
        return "Cpf: "+this.cpf+"//Nome: "+this.nome+"//Endereco: "+this.endereco+"//Telefone: "+this.telefone;
    }

    public void adicionarAnuncio(Anuncio anuncio){
        this.anuncios.add(anuncio);
    }

    public static void cadastrarAssinante(){
        Scanner var = new Scanner(System.in);
        String cpf = "";
        String nome = "";
        String endereco = "";
        String telefone = "";

        System.out.println("Cpf do Assinante: ");
        cpf = var.nextLine();
        System.out.println("Nome do Assinante: ");
        nome = var.nextLine();
        System.out.println("Endereco do Assinante: ");
        endereco = var.nextLine();
        System.out.println("Telefone do Assinante: ");
        telefone = var.nextLine();
        
        Assinante cadastrado = new Assinante(cpf, nome, endereco, telefone);
        listaAssinantes.add(cadastrado);
        System.out.println("Assinante cadastrado");
    }

    public static void removerAssinante(){
        Scanner var = new Scanner(System.in);
        String nome = "";

        System.out.print("Nome do assinante a ser removido: ");
        nome = var.nextLine();
        
        for(Assinante assinante : listaAssinantes){
            if(assinante.getNome().equals(nome)){
                listaAssinantes.remove(assinante);
                break;
            }
        }
    }
}
