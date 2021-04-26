public class Array{

    private String[] vetorTemperaturas;

    //construtores
    public Array(String[] vetorTemperaturas){
        this.vetorTemperaturas = vetorTemperaturas;
    }

    public Array(int tamanho){
        this.vetorTemperaturas = new String[tamanho];
    }

    //gets e sets
    public void setVetorTemperaturas(String[] vetorTemperaturas){
        this.vetorTemperaturas = vetorTemperaturas;
    }

    public String[] getVetorTemperaturas(){
        return this.vetorTemperaturas;
    }

    //metodos
    public void adicionarTemperatura(String temperatura){
        for(int i = 0; i < this.vetorTemperaturas.length; i++){
            if(this.vetorTemperaturas[i] == null){
                this.vetorTemperaturas[i] = temperatura;
                break;
            }
        }
    }

    public void removerTemperatura(String temperatura){
        for(int i = 0; i < this.vetorTemperaturas.length; i++){
            if(this.vetorTemperaturas[i] == temperatura){
                this.vetorTemperaturas[i] = null;
                break;
            }
        }
    }

    public String maximaTemperatura(){
        ordenarCrescentemente();
        String max = "";
        for(int i = 0; i < this.vetorTemperaturas.length; i++){
            if(this.vetorTemperaturas[i] != null){
                max = this.vetorTemperaturas[i];
            }
        }
        return max;
    }

    public String minimaTemperatura(){
        ordenarCrescentemente();
        String min = "";
        for(int i = 0; i < this.vetorTemperaturas.length; i++){
            if(this.vetorTemperaturas[i] != null){
                min = this.vetorTemperaturas[i];
                break;
            }
        }
        return min;
    }

    public String amplitudeTermica(){
        float minTemperatura = Float.parseFloat(minimaTemperatura());
        float maxTemperatura = Float.parseFloat(maximaTemperatura());
        float amplitude = maxTemperatura - minTemperatura;

        return Float.toString(amplitude);
    }
    
    public String mediaTemperatura(){
        float total = 0;
        int qtdDados = 0;
        for(int i = 0; i < this.vetorTemperaturas.length; i++){
            if(this.vetorTemperaturas[i] != null){
                total += Float.parseFloat(this.vetorTemperaturas[i]);
                qtdDados++;
            }
        }
        return Float.toString(total/qtdDados);
    }

    public void ordenarCrescentemente(){
        for(int i = 0; i < this.vetorTemperaturas.length; i ++){
            if(this.vetorTemperaturas[i] != null){
                for(int j = 0; j < this.vetorTemperaturas.length; j++){
                    if(this.vetorTemperaturas[j] != null){
                        float dadoI = Float.parseFloat(vetorTemperaturas[i]);
                        float dadoJ = Float.parseFloat(vetorTemperaturas[j]);
                        if(dadoI < dadoJ){
                            String aux = vetorTemperaturas[i];
                            vetorTemperaturas[i] = vetorTemperaturas[j];
                            vetorTemperaturas[j] = aux;
                        }
                    }
                }
            }
        }
    }
}