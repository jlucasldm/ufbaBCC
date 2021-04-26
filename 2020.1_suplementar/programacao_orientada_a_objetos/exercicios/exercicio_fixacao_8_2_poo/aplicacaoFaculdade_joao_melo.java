import java.util.Scanner;
import java.util.ArrayList;

public class AplicacaoFaculdade{
    private static ArrayList<CursoGraduacao> listaCursosGraduacao = new ArrayList<CursoGraduacao>();
    private static ArrayList<CursoPosGraduacao> listaCursosPosGraduacao = new ArrayList<CursoPosGraduacao>();

    public static void criarCursoGraduacao(){
        Scanner var = new Scanner(System.in);
        String id = "";
        System.out.println("Id do curso: ");
        id = var.nextLine();

        String nome = "";
        System.out.println("Nome do curso: ");
        nome = var.nextLine();

        String area = "";
        System.out.println("Area: ");
        area = var.nextLine();

        int qtdVagas = 0;
        System.out.println("Quantidade de vagas: ");
        qtdVagas = var.nextInt();

        int qtdDisciplinasObrigatorias = 0;
        System.out.println("Quantidade de disciplinas obrigatorias: ");
        qtdDisciplinasObrigatorias = var.nextInt();

        int qtdDisciplinasOptativas = 0;
        System.out.println("Quantidade de disciplinas optativas: ");
        qtdDisciplinasOptativas = var.nextInt();

        CursoGraduacao criada = new CursoGraduacao(id, nome, area, qtdVagas, qtdDisciplinasObrigatorias, qtdDisciplinasOptativas);
        listaCursosGraduacao.add(criada);
        System.out.println("Curso criado\n");
    }

    public static void criarCursoPosGraduacao(){
        Scanner var = new Scanner(System.in);
        String id = "";
        System.out.println("Id do curso: ");
        id = var.nextLine();

        String nome = "";
        System.out.println("Nome do curso: ");
        nome = var.nextLine();

        String area = "";
        System.out.println("Area: ");
        area = var.nextLine();

        int qtdVagas = 0;
        System.out.println("Quantidade de vagas: ");
        qtdVagas = var.nextInt();

        int cargaHorariaMax = 0;
        System.out.println("Carga horaria maxima: ");
        cargaHorariaMax = var.nextInt();

        CursoPosGraduacao criada = new CursoPosGraduacao(id, nome, area, qtdVagas, cargaHorariaMax);
        listaCursosPosGraduacao.add(criada);
        System.out.println("Curso criado\n");
    }

    public static boolean consultarInformacoesCurso(){
        Scanner var = new Scanner(System.in);
        String id = "";
        System.out.println("Id do curso: ");
        id = var.nextLine();

        for(CursoGraduacao aux : listaCursosGraduacao){
            if(aux.getId().equals(id)){
                System.out.println(aux.consultaCurso() + "\n");
                return true;
            }
        }

        for(CursoPosGraduacao aux : listaCursosPosGraduacao){
            if(aux.getId().equals(id)){
                System.out.println(aux.consultaCurso() + "\n");
                return true;
            }
        }

        return false;
    }

    public static boolean consultarPrecoCurso(){
        Scanner var = new Scanner(System.in);
        String id = "";
        System.out.println("Id do curso: ");
        id = var.nextLine();

        String convenio = "";
        System.out.println("Possui convenio? (s/n): ");
        convenio = var.nextLine();

        if(convenio.equals("n")){
            for(CursoGraduacao aux : listaCursosGraduacao){
                if(aux.getId().equals(id)){
                    System.out.println("Valor cheio: " + aux.getTaxaMatricula() + "\n");
                    System.out.println("Valor com desconto: " + aux.getTaxaMatricula()*90/100 + "\n");
                    return true;
                }
            }

            for(CursoPosGraduacao aux : listaCursosPosGraduacao){
                if(aux.getId().equals(id)){
                    System.out.println("Valor cheio: " + aux.getTaxaMatricula() + "\n");
                    System.out.println("Valor com desconto: " + aux.getTaxaMatricula()*95/100 + "\n");
                    return true;
                }
            }
        }else{
            for(CursoGraduacao aux : listaCursosGraduacao){
                if(aux.getId().equals(id)){
                    System.out.println("Valor com desconto do convenio: " + aux.getTaxaMatricula()*95/100 + "\n");
                    System.out.println("Valor com desconto do conveio e pre-matricula: " + aux.getTaxaMatricula()*90/100*95/100 + "\n");
                    return true;
                }
            }

            for(CursoPosGraduacao aux : listaCursosPosGraduacao){
                if(aux.getId().equals(id)){
                    System.out.println("Valor com desconto do convenio: " + aux.getTaxaMatricula()*94/100 + "\n");
                    System.out.println("Valor com desconto do convenio e pre-matricula: " + aux.getTaxaMatricula()*95/100*94/100 + "\n");
                    return true;
                }
            }
        }

        return false;
    }

    public static void main(){
        int opcao = 0;
        Scanner var = new Scanner(System.in);

        do{
            System.out.println(
            "1. Criar curso de graduacao \n" +
            "2. Criar curso de pos graduacao \n" +
            "3. Consultar informacoes de um curso \n" +
            "4. Consultar preco do curso \n" +
            "5. Sair");

            opcao = var.nextInt();
            switch(opcao){
                case 1:
                    AplicacaoFaculdade.criarCursoGraduacao();
                    break;
                case 2:
                    AplicacaoFaculdade.criarCursoPosGraduacao();
                    break;
                case 3:
                    AplicacaoFaculdade.consultarInformacoesCurso();
                    break;
                case 4:
                    AplicacaoFaculdade.consultarPrecoCurso();
                    break;
            }
        }while(opcao != 5);
    }
}