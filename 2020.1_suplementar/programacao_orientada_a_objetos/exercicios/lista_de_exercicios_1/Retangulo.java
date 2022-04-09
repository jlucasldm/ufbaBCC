public class Retangulo{
    private float comprimento;
    private float largura;

    public Retangulo(float comprimento, float largura){
        if(comprimento>0){
            this.comprimento = comprimento;
        }else{
            this.comprimento = 1;
        }

        if(largura>0){
            this.largura = largura;
        }else{
            this.largura = 1;
        }
    }

    public void setComprimento(float comprimento){
        this.comprimento = comprimento;
    }

    public void setLargura(float largura){
        this.largura = largura;
    }

    public float getComprimento(){
        return this.comprimento;
    }

    public float getLargura(){
        return this.largura;
    }

    public float perimetro(){
        return (2*comprimento)+(2*largura);
    }

    public float area(){
        return comprimento*largura;
    }
}