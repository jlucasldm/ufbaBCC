import java.util.Scanner;
import java.util.ArrayList;

public class Aplicacao{

    public static void main(){
        int option = 0;
        Scanner var = new Scanner(System.in);
        do{
            System.out.println("1. Cadastrar Assinante \n" + 
            "2. Cadastrar Livro \n" + "3. Cadastrar Anúncio \n" + 
            "4. Remover Assinante \n" + "5. Remover Livro \n" + 
            "6. Remover Anuncio \n" + "7. Exibir Anuncios \n" + "8. Sair");
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
                    Assinante.removerAssinante();
                    break;
                case 5:
                    Livro.removerLivro();
                    break;
                case 6:
                    Anuncio.removerAnuncio();
                case 7:
                    Anuncio.showAnuncios();
                    break;
            }
        }while(option != 8);
    }
}
