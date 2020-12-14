//João Lucas Lima de Melo
import java.util.Scanner;
import java.util.ArrayList;

public class AplicacaoLivraria{
    private static ArrayList<Livro> listaLivros = new ArrayList<Livro>();
    private static ArrayList<LivroDidatico> listaLivrosDidaticos = new ArrayList<LivroDidatico>();
    private static ArrayList<Revista> listaRevistas = new ArrayList<Revista>();
    private static String nomeLivraria = "";

    public static void setNomeLivraria(String nome){
        nomeLivraria = nome;
    }

    public static String getNomeLivraria(){
        return nomeLivraria;
    }
    
    public static void criarRevista(){
        Scanner var = new Scanner(System.in);
        String nome = "";
        System.out.println("Nome da revista: ");
        nome = var.nextLine();

        String editora = "";
        System.out.println("Nome da editora: ");
        editora = var.nextLine();

        float preco = 0;
        System.out.println("Preco da revista: ");
        preco = var.nextFloat();

        int periodicidade = 0;
        System.out.println("Periodicidade da revista: ");
        periodicidade = var.nextInt();

        Revista criada = new Revista(nome, editora, preco, periodicidade);
        listaRevistas.add(criada);
        System.out.println("Revista criada\n");
    }

    public static void criarLivroDidatico(){
        Scanner var = new Scanner(System.in);
        String nome = "";
        System.out.println("Nome do livro didatico: ");
        nome = var.nextLine();

        String autor = "";
        System.out.println("Nome do autor: ");
        autor = var.nextLine();

        String editora = "";
        System.out.println("Nome da editora: ");
        editora = var.nextLine();

        String resumo = "";
        System.out.println("Resumo do livro didatico: ");
        resumo = var.nextLine();

        float preco = 0;
        System.out.println("Preco do livro didatico: ");
        preco = var.nextFloat();

        String area = "";
        System.out.println("Area do livro didatico: ");
        area = var.nextLine();

        LivroDidatico criada = new LivroDidatico(nome, autor, editora, resumo, preco, area);
        listaLivrosDidaticos.add(criada);
        System.out.println("Livro didatico criado\n");
    }

    public static void criarLivro(){
        Scanner var = new Scanner(System.in);
        String nome = "";
        System.out.println("Nome do livro: ");
        nome = var.nextLine();

        String autor = "";
        System.out.println("Nome do autor: ");
        autor = var.nextLine();

        String editora = "";
        System.out.println("Nome da editora: ");
        editora = var.nextLine();

        String resumo = "";
        System.out.println("Resumo do livro: ");
        resumo = var.nextLine();

        float preco = 0;
        System.out.println("Preco do livro: ");
        preco = var.nextFloat();

        //String resumo, String autor,String nome, String editora, float preco
        Livro criada = new Livro(resumo, autor, nome, editora, preco);
        listaLivros.add(criada);
        System.out.println("Livro criado\n");
    }

    public static boolean consultaResumoLivro(){
        Scanner var = new Scanner(System.in);
        String nome = "";
        System.out.println("Nome do livro a ser consultado: ");
        nome = var.nextLine();

        for(Livro livro : listaLivros){
            if(livro.getNome().equals(nome)){
                System.out.println(livro.getResumo());
                return true;
            }
        }

        for(LivroDidatico livroDidatico : listaLivrosDidaticos){
            if(livroDidatico.getNome().equals(nome)){
                System.out.println(livroDidatico.getResumo());
                return true;
            }
        }

        return false;
    }

    public static boolean checarEditorasRevistas(){
        Scanner var = new Scanner(System.in);
        String nomeRevista1 = "";
        System.out.println("Nome da primeira revista: ");
        nomeRevista1 = var.nextLine();
        
        String nomeRevista2 = "";
        System.out.println("Nome da segunda revista: ");
        nomeRevista2 = var.nextLine();

        Revista revista1 = new Revista("", "", 0, 0);
        Revista revista2 = new Revista("", "", 0, 0);

        for(Revista aux : listaRevistas){
            if(aux.getNome().equals(nomeRevista1)){
                revista1 = aux;
            }else if(aux.getNome().equals(nomeRevista2)){
                revista2 = aux;
            }
        }

        if(revista1.getNome().equals(nomeRevista1) && revista2.getNome().equals(nomeRevista2)){
            if(Revista.mesmaEditora(revista1, revista2) == true){
                System.out.println("As editoras sao iguais");
            }else{
                System.out.println("As editoras sao diferentes");
            }
            return true;
        }else{
            return false;
        }
    }

    public static boolean consultarDadosLivros(){
        Scanner var = new Scanner(System.in);
        String nome = "";
        System.out.println("Nome do livro a ser consultado: ");
        nome = var.nextLine();

        Livro livro = new Livro("", "", "", "", 0);

        for(Livro aux : listaLivros){
            if(aux.getNome().equals(nome)){
                livro = aux;
            }
        }

        if(livro.getNome().equals(nome)){
            System.out.println(livro.toString());
            return true;
        }else{
            return false;
        }
    }

    public static boolean consultarPrecoTitulo(){
        Scanner var = new Scanner(System.in);
        String nome = "";
        System.out.println("Nome do titulo a ser consultado: ");
        nome = var.nextLine();
        int flag = 0;

        Livro livro = new Livro("", "", "", "", 0);
        LivroDidatico livroDidatico = new LivroDidatico("", "", "", "", 0, "");
        Revista revista = new Revista("", "", 0, 0);

        for(Livro aux : listaLivros){
            if(aux.getNome().equals(nome)){
                livro = aux;
                flag = 1;
            }
        }

        for(LivroDidatico aux : listaLivrosDidaticos){
            if(aux.getNome().equals(nome)){
                livroDidatico = aux;
                flag = 2;
            }
        }

        for(Revista aux : listaRevistas){
            if(aux.getNome().equals(nome)){
                revista = aux;
                flag = 3;
            }
        }

        if(flag == 1){
            System.out.println(livro.calculaPrecoFinal(false));
            return true;
        }else if(flag == 2){
            System.out.println(livroDidatico.calculaPrecoFinal(false));
            return true;
        }else if(flag == 3){
            System.out.println(revista.calculaPrecoFinal(false));
            return true;
        }else{
            return false;
        }
    }

    public static boolean emitirNotaFiscal(){
        Scanner var = new Scanner(System.in);
        String nome = "";
        System.out.println("Nome do titulo a ser consultado: ");
        nome = var.nextLine();
        int flag = 0;

        Livro livro = new Livro("", "", "", "", 0);
        LivroDidatico livroDidatico = new LivroDidatico("", "", "", "", 0, "");
        Revista revista = new Revista("", "", 0, 0);

        for(Livro aux : listaLivros){
            if(aux.getNome().equals(nome)){
                livro = aux;
                flag = 1;
            }
        }

        for(LivroDidatico aux : listaLivrosDidaticos){
            if(aux.getNome().equals(nome)){
                livroDidatico = aux;
                flag = 2;
            }
        }

        for(Revista aux : listaRevistas){
            if(aux.getNome().equals(nome)){
                revista = aux;
                flag = 3;
            }
        }

        String ehVip = "";
        System.out.println("O cliente possui cartao vip? (s/n): ");
        ehVip = var.nextLine();

        if(flag == 1){
            if(ehVip.equals("s")){
                System.out.println(livro.emitirNota(true));
                return true;
            }else{
                System.out.println(livro.emitirNota(false));
                return true;
            }
        }else if(flag == 2){
            if(ehVip.equals("s")){
                System.out.println(livroDidatico.emitirNota(true));
                return true;
            }else{
                System.out.println(livroDidatico.emitirNota(false));
                return true;
            }
        }else if(flag == 3){
            if(ehVip.equals("s")){
                System.out.println(revista.emitirNota(true));
                return true;
            }else{
                System.out.println(revista.emitirNota(false));
                return true;
            }
        }else{
            return false;
        }
    }


    //aplicação do programa
    public static void main(){
        int opcao = 0;
        Scanner var = new Scanner(System.in);

        do{
            System.out.println(
            "1. Criar revista \n" +
            "2. Criar livro didatico \n" +
            "3. Criar livro \n" +
            "4. Consultar resumo de um livro \n" +
            "5. Verificar se duas revistas possuem editoras iguais \n" +
            "6. Checar dados de um livro \n" +
            "7. Consultar preco de um titulo \n" +
            "8. Emitir nota fiscal \n" +
            "9. Sair");

            opcao = var.nextInt();
            switch(opcao){
                case 1:
                    AplicacaoLivraria.criarRevista();
                    break;
                case 2:
                    AplicacaoLivraria.criarLivroDidatico();
                    break;
                case 3:
                    AplicacaoLivraria.criarLivro();
                    break;
                case 4:
                    AplicacaoLivraria.consultaResumoLivro();
                    break;
                case 5:
                    AplicacaoLivraria.checarEditorasRevistas();
                    break;
                case 6:
                    AplicacaoLivraria.consultarDadosLivros();
                    break;
                case 7:
                    AplicacaoLivraria.consultarPrecoTitulo();
                    break;
                case 8:
                    AplicacaoLivraria.emitirNotaFiscal();
                    break;
            }
        }while(opcao != 9);
    }
}