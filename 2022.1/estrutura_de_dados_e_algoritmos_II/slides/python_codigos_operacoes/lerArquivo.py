import tipoArquivo
import sys
f = open("dados", "rb")

f.seek(0)

for i in range(tipoArquivo.MTAMARQUIVO):
    r = f.read(sys.getsizeof(r))
    print("Registro " + str(i) + "\n")
    if r.ocupado:
        print("Ocupado: sim\n")
        print("chave: " + str(r.dados.chave) + "\n")
        print("Nome: " + str(r.dados.nome) + "\n")
    else:
        print("Ocupado: nao\n")

f.close()