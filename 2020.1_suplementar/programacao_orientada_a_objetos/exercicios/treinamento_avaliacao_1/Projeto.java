public class Projeto {
  
  private String nome;
  private String nomeCliente;
  private Tarefa[] tarefas;
  private int qtdTarefa=0;//qtd de tarefas corrente
  private float horaDeTrabalho; //valor da hora do projeto


 //construtor de projeto sem nehnuma tarefa
 public Projeto(String nome, String nomeCliente,float horaDeTrabalho, int qtdTarefas) {
        this.nome = nome;
        this.nomeCliente = nomeCliente;
        this.tarefas = new Tarefa[qtdTarefas];//sem nehuma tarefa ag. ft
        this.horaDeTrabalho = horaDeTrabalho;

    } 
  // construtor com exemplo de this, maximo de tarefas = 100    
  public Projeto(String nome, String nomeCliente, float horaDeTrabalho, String descricao){
    this(nome,nomeCliente,horaDeTrabalho,descricao,100);
  }
  //construtor Projeto com uma tarefa
  public Projeto(String nome, String nomeCliente,float horaDeTrabalho,String descricao, int qtdMAXTarefas){
    this.nome = nome;
    this.nomeCliente = nomeCliente;
    this.tarefas = new Tarefa[qtdMAXTarefas];
    tarefas[0] = new Tarefa(descricao);
    this. qtdTarefa++;

    this.horaDeTrabalho = horaDeTrabalho;
  }

  /*
  Gets e sets
  */

  public void setNome(String nome){
    this.nome = nome;
  }

  public void setNomeCliente(String nomeCliente){
    this.nomeCliente = nomeCliente;
  }

  public void setTarefas(Tarefa[] tarefas){
    this.tarefas = tarefas; 
  }

  public void setQtdTarefa(int qtdTarefa){
    this.qtdTarefa = qtdTarefa;
  }

  public void setHoraDeTrabalho(float horaDeTrabalho){
    this.horaDeTrabalho = horaDeTrabalho;
  }

  public String getNome(){
    return this.nome;
  }

  public String getNomeCliente(){
    return this.nomeCliente;
  }

  public Tarefa[] getTarefas(){
    return this.tarefas;
  }

  public int getQtdTarefa(){
    return this.qtdTarefa;
  }

  public float getHoraDeTrabalho(){
    return this.horaDeTrabalho;
  }

// public Projeto (String nome,.... Tarefa tarefa )
//Está errado em relação ao enunciado pois é agregação fraca 

  /*
  * Metodos
  */


//Questão 1
//exemplo adicional  
    // //Adiciona tarefa ( decricao, desenvolvedor )
    public boolean addTarefa(String descricao, String desenvolvedor){
      if(this.qtdTarefa < this.tarefas.length){
        Tarefa tarefa = new Tarefa(descricao, desenvolvedor);
        this.tarefas[this.qtdTarefa] = tarefa;
        this.qtdTarefa++;
        return true;
      }
        else
            return false;
    } 
//Metodo resposta q1.
     //Adiciona tarefa ( decricao, desenvolvedor,float horasGastas, String status,  )
  public boolean addTarefa(String descricao, String desenvolvedor, float horasGastas, String status){
        Tarefa tarefa;
        if(this.qtdTarefa < this.tarefas.length){
           if (status.equals("iniciada") || desenvolvedor == null){ //Iniciada ou executor nulo
             tarefa = new Tarefa(descricao);
           }
           else if(status.equals("delegada")){ //Tarefa delegada
            tarefa = new Tarefa(descricao,desenvolvedor);
           }
           else{ //Tarefa finalizada
            tarefa = new Tarefa(descricao,horasGastas,desenvolvedor,status);
           }
           this.tarefas[this.qtdTarefa] = tarefa;
           this.qtdTarefa++;;
           return true;
        }
        else
            return false;
    }
/*
    public void finalizarTarefa(String descrição, float horaGastas) {
    for(int i = 0; i < tarefas.length(); i++){
      if(tarefas[i] != null){
        if(tarefas[i].getStatus() ) 
      }
    }
  }
  */

  public boolean finalizarTarefa(float horasGastas, String descricao){
    for(int i = 0; i < this.qtdTarefa; i++){
      if(tarefas[i].getDescricao() == descricao){
        tarefas[i].setStatus("finalizada");
        tarefas[i].setHorasGastas(horasGastas);
        return true;
      }
    }
    return false;
  }

  
  public boolean projetoFinalizado(){
    for(int i = 0; i < this.qtdTarefa; i++){
      if(!this.tarefas[i].getStatus().equals("finalizada"))
        return false;
      }
    return true;
  }
 /* exemplo de outro for 
  public boolean projetoFinalizado() {
      for(Tarefa t : tarefas) {
        if (! t.getStatus().equals("finalizada")) {
          return false;
        }
      }
      return true;
  }*/
 //Questão 4
  public String valorProjeto(String nomeProjeto) {
    if(! this.nome.equals(nomeProjeto)) {
      return "Erro: projeto incorreto";
    }
    if (! projetoFinalizado()) {
      return "Projeto não finalizado";
    }
    double total = 0;
    //soma das horas gastas
    for(Tarefa t : tarefas) {
      total += t.getHorasGastas();
    }
    total = total * horaDeTrabalho;

    String saida = "projeto " + this.nome + ", Cliente: " + this.nomeCliente + ", Valor R$" + total;
    System.out.println(saida);
    return saida;
  } 
}