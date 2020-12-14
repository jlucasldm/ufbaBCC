import java.util.Scanner;
import java.util.Random;
import java.io.*;

public class Main {
  public static void main(String[] args) throws IOException {
    int N;
    String [] nomes = new String[20];
    String [] sobrenomes = new String[20];

    FileInputStream stream = new FileInputStream("nomes.txt");
    InputStreamReader reader = new InputStreamReader(stream);
    BufferedReader bufferReader = new BufferedReader(reader);
    
    for(int i = 0; i < 20; i++){
      nomes[i] = bufferReader.readLine();
    }

    stream = new FileInputStream("sobrenomes.txt");
    reader = new InputStreamReader(stream);
    bufferReader = new BufferedReader(reader);

    for(int i = 0; i < 20; i++){
      sobrenomes[i] = bufferReader.readLine();
    }

    Scanner ler = new Scanner(System.in);

    N = ler.nextInt();

    Random gerador = new Random();

    BufferedWriter bufferWriter = new BufferedWriter(new FileWriter("saida.txt"));

    for(int i = 0; i < N; i++){
      String linha;
      String nome;
      String sobrenome;
      int idade = gerador.nextInt(100);
      
      int numeroGerado = gerador.nextInt(20);
      nome = nomes[numeroGerado];
      sobrenome = sobrenomes[numeroGerado];
      linha = nome + " " + sobrenome + " " + idade + "\n";
      bufferWriter.append(linha);
    }
    bufferWriter.close();
    ler.close();
    bufferReader.close();
  }
}