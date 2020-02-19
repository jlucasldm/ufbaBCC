#include <stdio.h>
#include <string.h>

FILE * fp;

void gravaArquivo(char * f, int v) {
  char msg_maior[19], msg_menor[26];

  strcpy(msg_menor,"Valor menor ou igual a 100");
  strcpy(msg_maior,"Valor maior que 100");

  fp = fopen(f,"w");
  if (fp!=NULL) {
    if (v > 100)
      fwrite(msg_maior, 1, sizeof(msg_maior), fp);
    else
      fwrite(msg_menor, 1, sizeof(msg_menor), fp);
  }
  fclose(fp);
}

int main() {
  int valor1, valor2;

  printf("Informe um valor: ");
  scanf("%d", &valor1);
  printf("Informe outro valor: ");
  scanf("%d", &valor2);
  gravaArquivo("resultado.txt", (valor1*valor2));
  return 0;
}
