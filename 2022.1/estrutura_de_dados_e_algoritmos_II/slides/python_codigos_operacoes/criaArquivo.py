import tipoArquivo
import pickle

print("Criando arquivo \"dados\" ...\n")

f = open("dados", "wb")

if f:
    print("Arquivo \"dados\" criado com sucesso.\n")
else:
    print("Erro na criacao do arquivo \"dados\".")
    exit(-1)

print("Inicializando o arquivo ...\n")

r = tipoArquivo.Registro()
r.ocupado = False

for i in range(tipoArquivo.MTAMARQUIVO):
    f.write(pickle.dumps(r))

f.close()