// Gustavo de Oliveira Ferreira

import java.util.ArrayList;

public class Assinante {

    private String cpf;
    private String nome;
    private String endereco;
    private String telefone;
    private ArrayList<Anuncio> anunciosAssinante;

    public Assinante(String cpf, String nome, String endereco, String telefone, ArrayList<Anuncio> anunciosAssinante) {
        this.cpf = cpf;
        this.nome = nome;
        this.endereco = endereco;
        this.anunciosAssinante = anunciosAssinante;

        if(telefone.length() != 9 && telefone.length() != 11){
            System.out.println("O número não está no formato correto, tente novamento");
        }
        else {
            this.telefone = ((telefone.length() == 9) ? "71" + telefone : telefone);
        }
    }

    public Assinante(String cpf, String nome, String endereco, String telefone) {
        this(cpf, nome, endereco, telefone, new ArrayList<Anuncio>());
    }

    public String consultaAssinante(String identificador) {

        char[] identificadorChar = identificador.toCharArray();
        boolean flag = true;

        for(int i = 0; i < identificadorChar.length; i++){
            if(!Character.isDigit(identificadorChar[i])){
                flag = false;
                break;
            }
        }

        if(flag){
            String aux = ((identificador.length() == 11) ? identificador : "71" + identificador);
            if(aux.equals(this.telefone)){
                return "De acordo com o número dado, estas são as informações sobre o assinante:\n" + "Nome: " + this.nome + "\nCPF: " + this.cpf + "\nEndereço: " + this.endereco + "\nTelefone: " + this.telefone;
            }
            else {
                return "Não há nenhum assinante com este número";
            }
    }
        else {
            if(identificador.equals(this.nome)){
                return "De acordo com o nome dado, estas são as informações sobre o assinante:\n" + "Nome: " + this.nome + "\nCPF: " + this.cpf + "\nEndereço: " + this.endereco + "\nTelefone: " + this.telefone;
                }
            else {
                return "Não há nenhum assinante com este nome";
            }
        }

    }

    public int existeAssinante(String identificador) {

        char[] identificadorChar = identificador.toCharArray();
        boolean flag = true;

        for(int i = 0; i < identificadorChar.length; i++){
            if(!Character.isDigit(identificadorChar[i])){
                flag = false;
                break;
            }
        }

        if(flag){
            String aux = ((identificador.length() == 11) ? identificador : "71" + identificador);
            if(aux.equals(this.telefone)){
                return 1;
            }
            else {
                return 0;
            }
    }
        else {
            if(identificador.equals(this.nome)){
                return 1;
                }
            else {
                return 0;
            }
        }

    }


    public void adicionarAnuncio(Anuncio anuncio, Assinante selfAssinante){
        this.anunciosAssinante.add(anuncio);
        anuncio.setAnunciante(selfAssinante);
    }

    public void removerAnuncio(String tituloAnuncio){
        int length = anunciosAssinante.size();
        for(int i = 0; i < length; i++){
            if(anunciosAssinante.get(i).getTituloAnuncio() == tituloAnuncio) {
                this.anunciosAssinante.remove(i);
                break;
            }
        }
    }

    public String getCpf() {
        return this.cpf;
    }

    public void setCpf(String cpf) {
        this.cpf = cpf;
    }

    public String getNome() {
        return this.nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getEndereco() {
        return this.endereco;
    }

    public void setEndereco(String endereco) {
        this.endereco = endereco;
    }

    public String getTelefone() {
        return this.telefone;
    }

    public void setTelefone(String telefone) {
        this.telefone = telefone;
    }

    public ArrayList<Anuncio> getAnunciosAssinante() {
        return this.anunciosAssinante;
    }

    public void setAnunciosAssinante(ArrayList<Anuncio> anunciosAssinante) {
        this.anunciosAssinante = anunciosAssinante;
    }

}