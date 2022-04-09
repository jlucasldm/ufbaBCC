from ctypes import sizeof
import tipoArquivo
import pickle
import sys

f = open("dados", "rb+")
r = tipoArquivo.Registro()
aux_data = tipoArquivo.DadosUsuario()

aux_data.chave = int(input("informe uma chave: "))
aux_data.nome = str(input("entre com um nome: "))
r.dados = aux_data
posarq = int(input("entre com a posicao do arquivo: "))

print("Armazenando registro no arquivo ...\n")
r.ocupado = True
f.seek(posarq*sys.getsizeof(r))

if f.write(pickle.dumps(r)):
    print("Registro armazenado com sucesso\n")
else:
    print("Erro no armazenamento do registro\n")

f.close()