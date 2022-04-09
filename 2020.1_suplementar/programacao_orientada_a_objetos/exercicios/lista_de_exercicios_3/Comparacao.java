public class Comparacao{
    private float valor;

    public Comparacao(float valor){
        this.valor = valor;
    }

    public void setValor(float valor){
        this.valor = valor;
    }

    public float getValor(){
        return this.valor;
    }

    public boolean entradaIgualClasse(float valor){
        if(this.valor == valor){
            return true;
        }else{
            return false;
        }
    }

    public boolean entradaIgualEntrada(float valor1, float valor2){
        if(valor1 == valor2){
            return true;
        }else{
            return false;
        }
    }

    public boolean entradaMenorQueClasse(float valor){
        if(this.valor >= valor){
            return true;
        }else{
            return false;
        }
    }

    public boolean entradaMaiorQueEntrada(float valor1, float valor2){
        if(valor1 > valor2){
            return true;
        }else{
            return false;
        }
    }
}