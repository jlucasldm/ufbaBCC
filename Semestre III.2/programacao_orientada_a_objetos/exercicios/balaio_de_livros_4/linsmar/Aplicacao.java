import java.util.Scanner;
import java.util.ArrayList;
/**
 * Classe para o menu com o método main
 * 
 * @author (Linsmar da Silva Vital) 
 * @version (20201121)
 */

public class Aplicacao
{
    public static void main(){
        int option = 0;
        Scanner var = new Scanner(System.in);
        do{
            System.out.println(
            "--------------- \n" + 
            "1. Cadastrar Assinante. \n" + 
            "2. Cadastrar Livro. \n" +
            "3. Cadastrar Anúncio. \n" + 
            "4. Ver Livro do anúncio \n" + 
            "5. Desativar/ativar anúncio \n" + 
            "6. Ver todos os anúncios \n" + 
            "7. Sair \n"
            );
            option = var.nextInt();
            switch(option){
                case 1:
                    Assinante.cadastrarAssinante();
                    break;
                case 2:
                    Livro.cadastrarLivro();
                    break;
                case 3:
                    Anuncio.cadastrarAnuncio();
                    break;
                case 4:
                    Anuncio.verLivro();
                    break;
                case 5:
                    Anuncio.mudarAtivo();
                    break;
                case 6:
                    Anuncio.verTodosAnuncios();
                    break;
            }
        }while(option != 7);
    }
}
