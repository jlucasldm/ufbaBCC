
public class Tarefa {

  private String descricao;
  private float horasGastas;
  private String executor;
  private String status;

 /*
 * Construtores
 */

//Com descricao
  public Tarefa(String descricao){
    this.descricao = descricao;
    this.executor = "";
    this.horasGastas = 0;
    this.status = "iniciada";
  }

//Com descricao e executor
public Tarefa(String descricao, String executor) {
		this.descricao = descricao;
		this.horasGastas = 0;
		this.executor = executor;
		this.status = "delegada";
	}

//Com todos os parametros
 public Tarefa(String descricao, float horasGastas, String executor, String status) {
        this.descricao = descricao;
        this.horasGastas = horasGastas;
        this.executor = executor;
        this.status = status;
  }

  public String getDescricao() {
    return this.descricao;
  }

  public float getHorasGastas() {
    return this.horasGastas;
  }

  public String getExecutor(){
    return this.executor;
  }

  public String getStatus() {
    return this.status;
  }

  public void setDescricao(String descricao){
    this.descricao = descricao;
  }

  public void setHorasGastas(float horasGastas) {
    this.horasGastas = horasGastas;
  }

  public void setExecutor(String executor){
    this.executor = executor;
  }

  public void setStatus(String status) {
    this.status = status;
  }

}
