//João Lucas Lima de Melo
import java.util.Scanner;
import java.util.ArrayList;

public class Aplicacao{
    private static ArrayList<AnuncioVenda> listaAnunciosVenda = new ArrayList<AnuncioVenda>();
    private static ArrayList<AnuncioTroca> listaAnunciosTroca = new ArrayList<AnuncioTroca>();

    //método que solicita dados do usuário para criar uma instancia de Anuncio, inserindo-a no arrayList da classe. 
    //É conferido a existencia do assinante e livros cadastrados.
    public static void cadastrarAnuncio(){
        Scanner var = new Scanner(System.in);
        if(Assinante.getListaAssinantes().size() < 1){
            System.out.println("Anuncio nao pode ser cadastrado. Nao existem assinantes\n");
        }else if(Livro.getListaLivros().size() < 1){
            System.out.println("Anuncio nao pode ser cadastrado. Não existem livros\n");
        }else{
            boolean assinanteExiste = false;
            String nomeAssinante = "";
            System.out.println("Nome do assinante: \n");
            nomeAssinante = var.nextLine();
            Assinante assinanteCadastrado = new Assinante("","","","");
            for(Assinante assinante : Assinante.getListaAssinantes()){
                if(assinante.getNome().equals(nomeAssinante)){
                    assinanteCadastrado = assinante;
                    assinanteExiste = true;
                }else{
                    System.out.println("O assinante nao esta cadastrado\n");
                }
            }
            if (assinanteExiste){
                boolean livroExiste = false;
                Livro livroCadastrado = new Livro("","","",0,0);
                String isbnLivro = "";
                System.out.println("Isbn do livro: \n");
                isbnLivro = var.nextLine();
                for(Livro livro : Livro.getListaLivros()){
                    if(livro.getIsbn().equals(isbnLivro)){
                        livroCadastrado = livro;
                        livroExiste = true;
                    }else{
                        System.out.println("O livro nao esta cadastrado\n");
                    }
                }
                if (livroExiste){
                    String titulo = "";
                    float preco = 0;
                    boolean ativo = true;
                    System.out.println("Titulo do anúncio: \n");
                    titulo = var.nextLine();
                    System.out.println("Preco do livro (se o anuncio for para troca, favor inserir o valor 0): \n");
                    preco = var.nextFloat();
                    
                    if(preco != 0){
                        AnuncioVenda cadastrado = new AnuncioVenda(titulo, ativo, assinanteCadastrado, livroCadastrado, preco);
                        listaAnunciosVenda.add(cadastrado);
                        System.out.println("Anuncio de venda criado\n");
                    }else{
                        AnuncioTroca cadastrado = new AnuncioTroca(titulo, ativo, assinanteCadastrado, livroCadastrado);
                        listaAnunciosTroca.add(cadastrado);
                        System.out.println("Anuncio de troca criado\n");
                    }
                }
            }
        }
    }

    //metodo para remover uma instancia de Anuncio do arrayList da classe, usando o titulo como chave de busca
    public static void removerAnuncio(){
        Scanner var = new Scanner(System.in);
        String titulo = "";
        String ehTroca = "";

        System.out.print("Titulo do anuncio a ser removido: \n");
        titulo = var.nextLine();
        System.out.print("Trata-se de um anuncio de troca? (s/n)");
        ehTroca = var.nextLine();

        if(ehTroca.equals("s")){
            for(Anuncio anuncio : listaAnunciosTroca){
                if(anuncio.getTituloAnuncio().equals(titulo)){
                    listaAnunciosTroca.remove(anuncio);
                    break;
                }
            }
        }else{
            for(Anuncio anuncio : listaAnunciosVenda){
                if(anuncio.getTituloAnuncio().equals(titulo)){
                    listaAnunciosVenda.remove(anuncio);
                    break;
                }
            }
        }
        
    }

    //metodo para percorrer o arrayList da classe, iterando sobre as instancias de anuncios e imprimindo suas informações
    public static void showAnuncios(){
        if(listaAnunciosVenda.size() < 1 && listaAnunciosTroca.size() < 1){
            System.out.println("Não existem anúncios cadastrados\n");
        }else if(listaAnunciosVenda.size() < 1){
            System.out.println("//Anuncios de troca//\n");
            for(AnuncioTroca anuncio : listaAnunciosTroca){
                anuncio.imprimeDadosAnuncio();
            }
            System.out.println("//Nao existem anuncios de venda//\n");
        }else if(listaAnunciosTroca.size() < 1){
            System.out.println("//Anuncios de venda//\n");
            for(AnuncioVenda anuncio : listaAnunciosVenda){
                anuncio.imprimeDadosAnuncio();
            }
            System.out.println("//Nao existem anuncios de troca//\n");
        }else{
            System.out.println("//Anuncios de troca//\n");
            for(AnuncioTroca anuncio : listaAnunciosTroca){
                anuncio.imprimeDadosAnuncio();
            }
            System.out.println("//Anuncios de venda//\n");
            for(AnuncioVenda anuncio : listaAnunciosVenda){
                anuncio.imprimeDadosAnuncio();
            }
        }
    }

    //sobrecarga para garantir as opões de impressao individuais dos anuncios de troca e venda
    public static void showAnuncios(boolean ehTroca){
        if(ehTroca == false){
            if(listaAnunciosVenda.size() < 1){
                System.out.println("Não existem anúncios cadastrados\n");
            }else{
                System.out.println("//Anuncios de venda//\n");
                for(AnuncioVenda anuncio : listaAnunciosVenda){
                    anuncio.imprimeDadosAnuncio();
                }
            }
        }else{
            if(listaAnunciosTroca.size() < 1){
                System.out.println("Não existem anúncios cadastrados\n");
            }else{
                System.out.println("//Anuncios de troca//\n");
                for(AnuncioTroca anuncio : listaAnunciosTroca){
                    anuncio.imprimeDadosAnuncio();
                }
            }
        }
    }

    //aplicação do programa
    public static void main(){
        int opcao = 0;
        Scanner var = new Scanner(System.in);

        do{
            System.out.println(
            "1. Cadastrar Assinante \n" + 
            "2. Cadastrar Livro \n" + 
            "3. Cadastrar Anúncio \n" + 
            "4. Remover Assinante \n" + 
            "5. Remover Livro \n" + 
            "6. Remover Anuncio \n" + 
            "7. Exibir Todos Anuncios \n" +
            "8. Exibir Anuncios Venda \n" +
            "9. Exibi Anuncios Troca \n" + 
            "10. Sair");

            opcao = var.nextInt();
            switch(opcao){
                case 1:
                    Assinante.cadastrarAssinante();
                    break;
                case 2:
                    Livro.cadastrarLivro();
                    break;
                case 3:
                    Aplicacao.cadastrarAnuncio();
                    break;
                case 4:
                    Assinante.removerAssinante();
                    break;
                case 5:
                    Livro.removerLivro();
                    break;
                case 6:
                    Aplicacao.removerAnuncio();
                case 7:
                    Aplicacao.showAnuncios();
                    break;
                case 8:
                    Aplicacao.showAnuncios(false);
                    break;
                case 9:
                    Aplicacao.showAnuncios(true);
                    break;
            }
        }while(opcao != 10);
    }
}