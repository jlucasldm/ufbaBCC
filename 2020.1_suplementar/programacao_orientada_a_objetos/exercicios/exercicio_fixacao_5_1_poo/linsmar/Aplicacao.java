import java.util.Scanner;
import java.util.ArrayList;
/**
 * Escreva a descrição da classe Aplicacao aqui.
 * 
 * @author (Linsmar da Silva Vital) 
 * @version (20201114)
 */

public class Aplicacao
{
    public static void main(String[] s){
        Scanner op = new Scanner(System.in);
        Scanner x = new Scanner(System.in);
        Scanner var = new Scanner(System.in);
        String sn = "teste";
        int option = 0;
        
        do {
            System.out.println(
            "1. Cadastrar Atendente. \n" + 
            "2. Matricular Aluno. \n" +
            "3. Listar Alunos Matriculados. \n" + 
            "4. Sair \n"
            );
            option = op.nextInt();
            switch(option){
                case 1:
                    System.out.println("Continuar? (S/N) \n");
                    sn = x.nextLine();
                    while(!sn.equals("N") && !sn.equals("S")){
                        System.out.println("Continuar? (Por favor, digite S para sim ou N para não) \n");
                        sn = x.nextLine();
                    }
                    if(sn.equals("S")){
                        System.out.println("Escreva o nome do curso: \n");
                        String curso = var.nextLine();
                        Atendente.criarAtendente(curso);
                        break;
                    }
                    break;
                case 2:
                    System.out.println("Continuar? (S/N) \n");
                    sn = x.nextLine();
                    while(!sn.equals("N") && !sn.equals("S")){
                        System.out.println("Continuar? (Por favor, digite S para sim ou N para não) \n");
                        sn = x.nextLine();
                    }
                    if(sn.equals("S")){
                        boolean notEquals = false;
                        System.out.println("Escreva o nome do curso: \n");
                        String curso = var.nextLine();
                        if (Atendente.getAtendentesExistentes().size() < 1) System.out.println("Não existem atendentes cadastrados");
                        for(int i = 0; i < Atendente.getAtendentesExistentes().size(); i++){
                            if (Atendente.getAtendentesExistentes().get(i).getCurso().equals(curso)){
                                System.out.println("Escreva o nome do aluno: \n");
                                String nome = var.nextLine();
                                Atendente.criarMatricula(nome,curso);
                                notEquals = false;
                                break;
                            }
                            else notEquals = true;
                        }
                        if (notEquals) System.out.println("Aguarde seu atendente chegar");
                    }
                    break;
                case 3:
                    System.out.println("Continuar? (S/N) \n");
                    sn = x.nextLine();
                    while(!sn.equals("N") && !sn.equals("S")){
                        System.out.println("Continuar? (Por favor, digite S para sim ou N para não) \n");
                        sn = x.nextLine();
                    }
                    if(sn.equals("S")){
                        System.out.println("------------");
                        for (int i = 0; i < Atendente.getAlunosMatriculados().size(); i++) {
                            System.out.println("Nome: " + Atendente.getAlunosMatriculados().get(i).getNome() + "\n" + 
                                               "Curso: " + Atendente.getAlunosMatriculados().get(i).getCurso() + "\n" + 
                                               "Matricula: " + Atendente.getAlunosMatriculados().get(i).getMatricula() + "\n" + 
                                               "------------\n"
                            );
                        }
                        System.out.println("-----FIM-----");
                    }
                    break;
                case 4:
                    break;
            }
        }while(option != 4);
    }
}
