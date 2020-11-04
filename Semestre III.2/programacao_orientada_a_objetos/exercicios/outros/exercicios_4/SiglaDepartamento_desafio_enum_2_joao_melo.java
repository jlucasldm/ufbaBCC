//João Lucas Lima de Melo
public enum SiglaDepartamento{
    DCC("Departamento de Ciencia da Computacao"),
    DMAT("Departamento de Matematica"),
    DFIS("Departamento de Fisica"),
    DMU("Departamento de Musica");
    
    private String name;

    SiglaDepartamento(String name) {
        this.name = name;
    }

    public String getName() {
        return this.name;
    }
}