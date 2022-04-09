//João Lucas Lima de Melo
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

    //método para inserir uma instancia de Anuncio no arrayList da classe
    public void adicionarAnuncio(Anuncio anuncio){
        this.anuncios.add(anuncio);
    }

    //método que solicita dados do usuário para cirar uma instancia de Assinante, inserindo-a no arrayList da classe
    public static void cadastrarAssinante(){
        Scanner var = new Scanner(System.in);
        String cpf = "";
        String nome = "";
        String endereco = "";
        String telefone = "";

        System.out.println("Cpf do Assinante: \n");
        cpf = var.nextLine();
        System.out.println("Nome do Assinante: \n");
        nome = var.nextLine();
        System.out.println("Endereco do Assinante: \n");
        endereco = var.nextLine();
        System.out.println("Telefone do Assinante: \n");
        telefone = var.nextLine();
        
        Assinante cadastrado = new Assinante(cpf, nome, endereco, telefone);
        listaAssinantes.add(cadastrado);
        System.out.println("Assinante cadastrado\n");
    }

    //método para a remoção de uma instancia de Assinante do arrayList da classe, usando o nome como elemento de busca
    public static void removerAssinante(){
        Scanner var = new Scanner(System.in);
        String nome = "";

        System.out.print("Nome do assinante a ser removido: \n");
        nome = var.nextLine();
        
        for(Assinante assinante : listaAssinantes){
            if(assinante.getNome().equals(nome)){
                listaAssinantes.remove(assinante);
                break;
            }
        }
    }
}
