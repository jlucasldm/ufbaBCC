import java.util.Scanner;
import java.util.ArrayList;

public class Aplicacao{
    public static void main(){
        //Scanner operacao = new Scanner(System.in);
        ArrayList<Atendente> atendentes = new ArrayList<Atendente>();
        int stop = 0;
        
        while(stop != 1){
            System.out.println("1. Cadastrar Atendente\n2. Matricular Aluno\n3. Lisar Alunos Matriculados\n4. Sair\n");
            String opcao = Keyboard.readString();
            if(opcao == "1"){
                System.out.println("Nome do curso: \n");
                String curso = Keyboard.readString();
                Atendente atendente = new Atendente(curso);
                atendentes.add(atendente);
            }
            else if(opcao == "2"){
                System.out.println("Nome do aluno: \n");
                String nome = Keyboard.readString();
                System.out.println("Curso do aluno: \n");
                String curso = Keyboard.readString();
                int matriculado = 0;
                for(Atendente atendente : atendentes){
                    if(curso == atendente.getCurso()){
                        atendente.matriculaAluno(nome);
                        matriculado = 1;
                        break;
                    }
                }
                if(matriculado == 0){
                    System.out.println("Aguarde seu atendente chegar\n");
                }
            }
            else if(opcao == "3"){
                for(Atendente atendente : atendentes){
                    for(Aluno aluno : atendente.getAlunos()){
                        System.out.println("Aluno: " + aluno.getNome() +
                        "\nCurso: " + aluno.getCurso() +
                        "\nMatricula " + aluno.getMatricula() + "\n");
                    }
                }
            }
            else if(opcao == "4"){
                System.out.println("Sair? (y/n)\n");
                String caractere = Keyboard.readString();
                if(caractere == "y"){
                    stop = 1;
                }
            }
            else{
                System.out.println("Opcao invalida\n");
            }
        }
    }
}