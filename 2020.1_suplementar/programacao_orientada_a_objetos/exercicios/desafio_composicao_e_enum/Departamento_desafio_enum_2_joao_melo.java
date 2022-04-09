//João Lucas Lima de Melo
public class Departamento{
    private SiglaDepartamento siglaDepartamento;
    private String nome;
    private String numero;

    //construtor
    public Departamento(SiglaDepartamento siglaDepartamento){
        this.siglaDepartamento = siglaDepartamento;
        this.nome = siglaDepartamento.getName();

        if(siglaDepartamento == siglaDepartamento.DCC){
            this.numero = "1";
        }else if(siglaDepartamento == siglaDepartamento.DMAT){
            this.numero = "2";
        }else if(siglaDepartamento == siglaDepartamento.DFIS){
            this.numero = "3";
        }else if(siglaDepartamento == siglaDepartamento.DMU){
            this.numero = "4";
        }
    }

    //gets e sets
    public void setNome(String nome){
        this.nome = nome;
    }

    public void setNumero(String numero){
        this.numero = numero;
    }

    public void setSiglaDepartamento(SiglaDepartamento siglaDepartamento){
        this.siglaDepartamento = siglaDepartamento;
    }

    public String getNome(){
        return this.nome;
    }

    public String getNumero(){
        return this.numero;
    }

    public SiglaDepartamento getSiglaDepartamento(){
        return this.siglaDepartamento;
    }
}