#include <stdio.h>
#include <stdlib.h>

int consultaRegistro(int pos)
{

	FILE *f;

	if (!(f = fopen("dados", "r+")))
	{
		printf("Erro na abertura do arquivo \"dados\" - Programa abortado\n");
		exit(-1);
	}

	int i;
	bool found = false;
	Registro r;
	fseek(f, 0, SEEK_SET);

	fseek(f, (pos) * sizeof(Registro), SEEK_SET);
	fread(&r, sizeof(Registro), 1, f);

	if (r.ocupado == 1)
	{
		return 1;
	}
	else{
		return 0;
	}
}
