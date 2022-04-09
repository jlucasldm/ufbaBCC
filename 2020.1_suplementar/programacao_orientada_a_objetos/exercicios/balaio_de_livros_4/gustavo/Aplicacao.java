// Gustavo de Oliveira Ferreira

import java.util.Scanner;
import java.util.ArrayList;

public class Aplicacao {
    // ADICIONAR ASSINANTE

    // REMOVER ASSINANTE

    // ADICIONAR ANUNCIO DE ASSINANTE X

    // REMOVER ANUNCIO DE ASSINANTE X

    // MOSTRAR TODOS ANUNCIOS DE ASSINANTE X

    // MOSTRAR TODOS ANUNCIOS

    // MOSTRAR INFORMAÇÕES DE ASSINANTE X

    // CONSULTAR LIVRO DENTRE TODOS OS ANUNCIOS E MOSTRAR QUAIS ANUNCIO/ANUNCIANTES POSSUI ESTE LIVRO

    // CONTINUAR (S/N)

    public static void main(String[] args){
        ArrayList<Assinante> listaAssinantesTotais = new ArrayList<Assinante>();
        ArrayList<Anuncio> listaAnunciosTotais = new ArrayList<Anuncio>();

        while(true){
            System.out.println(
                "1. Adiconar Assinante\n" +
                "2. Remover Assinante\n" +
                "3. Adicionar Anuncio\n" +
                "4. Remover Anuncio\n" +
                "5. Mostrar Todos Anuncios\n" +
                "6. Mostrar Informações do Anuncioante\n" +
                "7. Consultar livro dentro dos os anuncios\n" +
                "8. Continuar (S/N)\n"
            );


            Scanner opcaoSC = new Scanner(System.in);
            int opcao = opcaoSC.nextInt();

            switch(opcao){
                case 1:
                    Scanner cpfSC = new Scanner(System.in);
                    Scanner nomeSC = new Scanner(System.in);
                    Scanner enderecoSC = new Scanner(System.in);
                    Scanner telefoneSC = new Scanner(System.in);

                    System.out.println("Para cadastrar um assinante digite as seguintes informações: ");

                    System.out.print("CPF: ");
                    String cpf = cpfSC.next();

                    System.out.print("Nome: ");
                    String nome = nomeSC.nextLine();

                    System.out.print("Endereço: ");
                    String endereco = enderecoSC.nextLine();

                    System.out.print("Telefone: ");
                    String telefone = telefoneSC.nextLine();

                    Assinante assinante = new Assinante(cpf, nome, endereco, telefone);
                    listaAnunciosTotais.add(assinante);

                    break;
                case 2:
                    System.out.print("Para remover um assinante digite o nome dele: ");
                    Scanner consultaSC = new Scanner(System.in);

                    for(int i = 0; i < listaAssinantesTotais.size(); i++){
                        if(listaAnunciosTotais.get(i).getNome() == consulta) {
                            listaAnunciosTotais.remove(i);
                            break;
                        }
                    }
                    break;

                case 3:
                    Scanner tituloSC = new Scanner(System.in);
                    Scanner isAtivoSC = new Scanner(System.in);
                    Scanner isTrocaSC = new Scanner(System.in);
                    Scanner qntdLivroSC = new Scanner(System.in);
                    Scanner precoSC = new Scanner(System.in);

                    System.out.println("Para adicionar um anuncio digite as seguintes informações: ");

                    System.out.print("Titulo do anuncio: ");
                    String tituloAnuncio = tituloSC.nextLine();

                    System.out.print("Está ativo (S/N): ");
                    String isAtivo = isAtivoSC.next();

                    System.out.print("É para troca (S/N): ");
                    String isTroca = isTrocaSC.next();
                    if(isTroca == "N") {
                        System.out.print("É para troca (S/N): ");
                        float preco = precoSC.nextFloat();
                    }
                    else {
                        preco = 0;
                    }

                    System.out.print("Quantos livros irá possuir? (Digite um inteiro)");
                    int qntdLivro = qntdLivroSC.nextInt();

                    Anuncio anuncio = new Anuncio(tituloAnuncio, preco, isAtivo);

                    for(int i = 0; i < preco; i++) {
                        Scanner nomeLivroSC = new Scanner(System.in);
                        System.out.print("Nome do livro: ");
                        String nomeLivro = nomeLivroSC.nextLine();

                        Scanner isbnSC = new Scanner(System.in);
                        System.out.print("ISBN: ");
                        String isbn = isbnSC.next();

                        Scanner materiaSC = new Scanner(System.in);
                        System.out.print("Materia do livro: ");
                        String materia = materiaSC.nextLine();

                        Scanner edicaoSC = new Scanner(System.in);
                        System.out.print("Edicao: ");
                        String edicao = edicaoSC.nextLine();

                        Scanner anoSC = new Scanner(System.in);
                        System.out.print("Ano: ");
                        int ano = anoSC.nextInt();

                        Scanner anoPublicacaoSC = new Scanner(System.in);
                        System.out.print("Ano da Publicação: ");
                        int anoPublicacao = anoPublicacaoSC.nextInt();

                        Livro newLivro = new Livro(nomeLivro, isbn, materia, edicao, ano, anoPublicacao);
                        anuncio.adicionarLivro(livro);
                    }

                    break;

                case 4:
                    break;

                case 5:
                    break;

                case 6:
                    break;

                case 7:
                    break;

                case 8:
                    break;

            }

        }


    }
}

