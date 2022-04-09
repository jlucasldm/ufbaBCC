import java.util.ArrayList;

public class Agenda{
    private String nomeDono;
    private String endereco;
    private ArrayList<Contatos> listaContatos = new ArrayList<Contatos>();

    public Agenda(String nomeDono, String endereco){
        this.nomeDono = nomeDono;
        this.endereco = endereco;
    }

    public Agenda(String nomeDono, String endereco, ArrayList<Contatos> listaContatos){
        this.nomeDono = nomeDono;
        this.endereco = endereco;
        this.listaContatos = listaContatos;
    }

    public void setNomeDono(String nomeDono){
        this.nomeDono = nomeDono;
    }

    public void setEndereco(String endereco){
        this.endereco = endereco;
    }

    public void setListaContatos(ArrayList<Contatos> listaContatos){
        this.listaContatos = listaContatos;
    }

    public String getNomeDono(){
        return this.nomeDono;
    }

    public String getEndereco(){
        return this.endereco;
    }

    public ArrayList<Contatos> getListaContatos(){
        return this.listaContatos;
    }

    public void adicionarContato(Contatos contato){
        listaContatos.add(contato);
    }

    public boolean removeContatoNome(String nome){
        for(Contatos contato : listaContatos){
            if(contato.getNome() == nome){
                listaContatos.remove(contato);
                return true;
            }
        }
        return false;
    }

    public boolean removeContatoTelefone(String telefone){
        for(Contatos contato : listaContatos){
            if(contato.getTelefone() == telefone){
                listaContatos.remove(contato);
                return true;
            }
        }
        return false;
    }

    public boolean alterarNomeContato(String telefone, String nome){
        for(Contatos contato : listaContatos){
            if(contato.getTelefone() == telefone){
                contato.setNome(nome);
                return true;
            }
        }
        return false;
    }

    public void listarContatos(){
        for(Contatos contato : listaContatos){
            System.out.println("Nome: " + contato.getNome() + "Telefone: " + contato.getTelefone() + "\n");
        }
    }

    public int quantidadeContatos(){
        int qtd = 0;
        for(Contatos contato : listaContatos){
            qtd++;
        }
        return qtd;
    }
}