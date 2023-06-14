"""
MATA59 - REDE DE COMPUTADORES - UNIVERSIDADE FEDERAL DA BAHIA
IMPLEMENTAÇÃO DE UMA APLICAÇÃO CLIENTE-SERVIDOR

Discentes: 
    João Lucas Melo
    Shaísta Câmara

Docente: Gustavo Figueredo


[RESUMO]

Este trabalho possui como finalidade a implementação de uma aplicação de
depósito de arquivo com recuperação. Através do modelo cliente-servidor, a 
aplicação fornece os seguintes serviços:
  i) depósito de arquivos
 ii) recuperação de arquivos
iii) remoção de arquivos

No modo de depósito, o cliente informa ao servidor o arquivo a ser 
depositado e o número de cópias. O servidor guarda a quantidade informada
de cópias do arquivo em locais (abstrações para dispositivos) distintos.

No modo de recuperação, o cliente informa ao servidor o nome do arquivo a
ser recuperado do servidor. O servidor encontrará o arquivo, de algum dos
possíveis locais onde ele esteja armazenado, e o devolve ao cliente.

No modo de remoção, o cliente informa ao servidor o nome do arquivo a ser
removido do servido. O servidor então remove o arquivo solicitado em todas
os locais (abstrações para dispositivos) onde exista uma cópia do mesmo.

A implementação do projeto se deu através da programação, em python, de 
dois algoritmos: server.py e client.py. Como referenciado em seus nomes, 
ambos atuam como instâncias do servidor e cliente da aplicação, 
respectivamente. 

Através do uso de sockets, cliente e servidor comunicam entre si por uma 
conexão TCP. A escolha do protocolo em detrimento do UDP foi consequência 
da necessidade do serviço de transferência confiável de dados (já que a 
aplicação manuseia arquivos, transferindo-os de um hospedeiro a outro). 
Como somente o TCP é capaz de fornecer esse serviço, provendo a garantia
de que os dados serão entregues de um host a outro na ordem correta e sem 
estarem corrompidos, a escolha desse protocolo foi fundamental.

Seguindo as especificações solicitadas e incorporando os conceitos vistos 
em sala de aula, foi possível desenvolver uma aplicação coesa do modelo
cliente-servidor básico, mas fundamental para consolidação das discussões 
da disciplina.


[FUNCIONAMENTO GERAL]
A aplicação consiste em dois programas, server.py e client.py. Python foi
escolhido como linguagem de programação para a implementação por sua
facilidade de manipulação e pela familiaridade dos autores do trabalho
com a tecnologia. Ambos os programas atuam como instâncias de um servidor 
e um cliente, respectivamente. 

Os processos se comunicam por uma conexão TCP através do uso de sockets.
Uma vez que se trata de uma aplicação que manuseia arquivos, transferindo
de um processo a outro, é fundamental que o protocolo da camada de
transporte forneça um serviço confiável de transferência de dados. Por
esse motivo, o TCP foi escolhido em detrimento do UDP.

Inicialmente, server.py deve ser executado para instancializar o servidor.
É solicitado no prompt a porta desejada para a criação do socket TCP. O 
endereço IP do servidor é atribuído ao IP do sistema final onde o processo
está sendo executado. Uma saída é printada no terminal no seguinte formato:
"[LISTENING] server is listening on IP: ***.***.***.***, Port: ****"
Nesse momento, o socket TCP é criado e o servidor é instancializado. O
servidor então fica à espera da conexão de um cliente.

Instancializado o servidor, client.py pode ser executado. É solicitado no
prompt o endereço IP e porta para o estabelecimento da conexão TCP entre
os processos. Ambas as informações foram dadas pelo retorno no terminal de
server.py. Além disso, um valor para o nome do cliente será solicitado. A
importância dessa variável será discutida mais adiante. 

Passados os valores de endereço IP e porta correspondentes ao servidor, e
ainda fornecido um nome do cliente, processos cliente e servidor 
estabelecerão uma conexão TCP.

Ao estabelecer a conexão, recebendo o nome do cliente, o processo servidor
atribui o valor recebido à variável client_name e informa o cliente que o
nome foi recebido com sucesso. A variável client_name será usada durante 
todas as operações solicitadas pelo cliente, uma vez que, por decisão de 
implementação, client_name é usado para nomear diretórios nos diferentes 
locais (abstrações de dispositivos) do servidor. Por exemplo, para um 
cliente cujo nome é "thomas", o servidor deverá, para um(s) certo(s) 
diretório(s), possuir uma instância de um diretório chamado "thomas", 
referente ao local onde os arquivos do cliente "thomas" deverão ser 
armazenados, recuperados ou removidos.

Após retornar ao cliente o recebimento de client_name, o processo servidor 
faz uma busca em seus locais por um diretório de nome client_name. O 
resultado é impresso no terminal e retornado ao cliente. Duas situações
podem ocorrer:
  i) não haver um diretório client_name no servidor / não haver dados no
     diretório client_name:
        . O processo servidor printa no prompt a mensagem:
        [WARNING] No files found to {client_name}
        . O processo cliente recebe do servidor a mensagem:
        No files to {client_name} found
 ii) haver um diretório client_name com arquivos:
        . O processo servidor recupera todos os arquivos no local 
        client_name e printa no prompt a mensagem (onde files é uma lista
        contendo os arquivos no local client_name):
        [SUCESS] {client_name}'s files found: {files}
        . O processo cliente recebe do servidor a mensagem (onde 
        files_itens são os arquivos no local client_name):
        Files to thomas found: {files_itens}

Após a interação, é requisitado ao cleinte, no prompt, um valor op 
sinalizando o serviço a ser executado pelo servidor. op pode ter três 
formatos:
  i) DEP := serviço de depósito
 ii) REC := serviço de recuperação
iii) DEL := serviço de remoção

Atribuído o valor da operação à op, é ainda requisitado do cliente os 
valores dos parâmetros das respectivas operações. São elas:
DEP := filename (nome do arquivo a ser depositado no servidor)
       copies (número de cópias a serem depositadas no servidor)
REC := filename (nome do arquivo a ser recuperado pelo servidor)
DEL := filename (nome do arquivo a ser removido do servidor)

Definida a operação e os respectivos argumentos necessários, o cliente
envia os dados através do socket TCP para o servidor, que retornará ao
cliente as respectivas mensagens de sucesso e dados correspondentes às
operações solicitadas (no caso de recuperação de arquivo). O funcionamento
de cada operação será melhor abordado mais adiante.

Finalizada a operação, o cliente encerra a conexão TCP e o servidor retorna
ao estado de escuta, esperando uma conexão de um novo cliente.


[OPERAÇÃO DE DEPÓSITO]
A aplicação fornece três serviços: depósito de um arquivo no servidor,
recuperação de um arquivo no servidor e serviço de remoção. O cliente
seleciona a operação desejada de acordo com sgeuinte o padrão de fomato:
DEP := filename (nome do arquivo a ser depositado no servidor)
       copies (número de cópias a serem depositadas no servidor)
REC := filename (nome do arquivo a ser recuperado pelo servidor)
DEL := filename (nome do arquivo a ser removido do servidor)

Selecionada a operação, o cliente atribui seu valor à variável op e a 
transmite ao servidor através da conexão TCP. Ao receber op, o servidor
retorna ao cliente a mensagem:
[{endereço da conexão}] Operation {op} received

O servidor, ao rebeber o valor DEP, invoca a função deposit() e aguarda 
conexão do cliente, que enviará os valores necessários para executar a 
operação. Os demais argumentos necessários são:
filename := nome do arquivo, no diretório atual do processo cliente, a
            ser depositado no servidor
  copies := número de cópias do arquivo a ser armazenadas no servidor

Cabe comentar que o arquivo enviado irá sobrescrever a cópia no servidor,
caso exista.

Definidos os parâmetros e armazenados nas suas respectivas variáveis, o
cliente, individualmente, os envia ao servidor pelo socket TCP. Ao 
receber os dados, o servidor envia as seguintes respostas ao cliente:
[SUCESS] Number of copies recieved: {copies}
[SUCESS] File name recieved: {filename}

Um terceiro parâmetro é enviado ao servidor, o arquivo no diretório atual
do processo cliente. O arquivo, cujo nome é filename, é aberto e 
atribuído à variável file em client.py. O processo cliente então envia
file para o servidor através do socket TCP.

Ao receber o arquivo, o servidor itera sobre file de blocos em blocos de 
bytes (definido pela variável global HEADER, atribuído a 1024 bytes). Os
dados iterados são atribuídos à uma variável local file_bytes. Dessa
forma, a função deposit() consegue, com êxito, ter acesso à uma cópia de
file antes de efetivamente instancializar o arquivo no servidor.

Tendo acesso ao conteúdo do arquivo, deposit() então itera sobre os 
diretórios do servidor, buscando pelo diretório client_name para uma
quantidade copies de locais (dispositivos) existentes. Cada local é
nomeado por um inteiro, a partir do índice 0. Caso não exista o diretório
client_name em todos os copies locais no servidor, então são criados os
locais:
.\\server\\0\\client_name
.\\server\\1\\client_name
...
.\\server\\copies\\client_name

Para cada client_name, nos locais 0 a copies, o servidor cria um arquivo
filename e atribui a ele o conteúdo de file_bytes. O processo então
informa ao cliente o sucesso da operação. O cliente, ao receber a 
confirmação da operação, encerra a conexão TCP com o servidor, que retorna
ao estado de escuta e espera de uma nova conexão.


[OPERAÇÃO DE RECUPERAÇÃO]
A aplicação fornece três serviços: depósito de um arquivo no servidor,
recuperação de um arquivo no servidor e serviço de remoção. O cliente
seleciona a operação desejada de acordo com sgeuinte o padrão de fomato:
DEP := filename (nome do arquivo a ser depositado no servidor)
       copies (número de cópias a serem depositadas no servidor)
REC := filename (nome do arquivo a ser recuperado pelo servidor)
DEL := filename (nome do arquivo a ser removido do servidor)

Selecionada a operação, o cliente atribui seu valor à variável op e a 
transmite ao servidor através da conexão TCP. Ao receber op, o servidor
retorna ao cliente a mensagem:
[{endereço da conexão}] Operation {op} received

O servidor, ao rebeber o valor REC, invoca a função recover() e aguarda 
conexão do cliente, que enviará os valores necessários para executar a 
operação. O demais argumento necessário é:
filename := nome do arquivo, no diretório atual do processo cliente, a
            ser depositado no servidor

Definido o parâmetro e armazenado na sua respectiva variável, o cliente
o envia ao servidor pelo socket TCP. Ao receber filename, o servidor 
envia a seguinte resposta ao cliente:
[SUCESS] File name recieved: {filename}

O servidor então busca por todos os diretórios do servidor, buscando 
pelo diretório client_name em todos os locais (dispositivos) existentes. 
Cada local é nomeado por um inteiro, a partir do índice 0. O endereço
segue o seguinte formato:
.\\server\\0\\client_name

Encontrado o diretório em algum dos locais do servidor, o processo então
abre o arquivo filename e envia segmentos de bytes do tamanho HEADER (por
padrão adotado pela implementação, atribuído a 1024 bytes) ao cliente. O
cliente, por sua vez, recebe cada segmento e atribuí a uma variável
file_bytes. Após o envio e recebimento de todos os segmentos de bytes do
arquivo no servidor, o cliente cria um arquivo de nome filename em seu
diretório atual e atribui file_bytes ao seu conteúdo.

Por fim, o servidor informa ao cliente o sucesso da operação. O cliente, 
ao receber a confirmação da operação, encerra a conexão TCP com o servidor, 
que retorna ao estado de escuta e espera de uma nova conexão.


[OPERAÇÃO DE REMOÇÃO]
A aplicação fornece três serviços: depósito de um arquivo no servidor,
recuperação de um arquivo no servidor e serviço de remoção. O cliente
seleciona a operação desejada de acordo com sgeuinte o padrão de fomato:
DEP := filename (nome do arquivo a ser depositado no servidor)
       copies (número de cópias a serem depositadas no servidor)
REC := filename (nome do arquivo a ser recuperado pelo servidor)
DEL := filename (nome do arquivo a ser removido do servidor)

Selecionada a operação, o cliente atribui seu valor à variável op e a 
transmite ao servidor através da conexão TCP. Ao receber op, o servidor
retorna ao cliente a mensagem:
[{endereço da conexão}] Operation {op} received

O servidor, ao rebeber o valor DEL, invoca a função delete() e aguarda 
conexão do cliente, que enviará o valore necessário para executar a 
operação. O demais argumento necessário é:
filename := nome do arquivo, no diretório atual do processo cliente, a
            ser depositado no servidor

Definido o parâmetro e armazenado na sua respectiva variável, o cliente
o envia ao servidor pelo socket TCP. Ao receber filename, o servidor 
envia a seguinte resposta ao cliente:
[SUCESS] File name recieved: {filename}

O servidor então busca por todos os diretórios do servidor, buscando 
pelo diretório client_name em todos os locais (dispositivos) existentes. 
Cada local é nomeado por um inteiro, a partir do índice 0. O endereço
segue o seguinte formato:
.\\server\\0\\client_name

Para cada local encontrado, o servidor checa a existência de filename no
diretório. Caso encontrado, o servidor remove o arquivo e retorna ao
cliente uma mensagem do tipo:
[SUCESS] File {filename} deleted

Caso o arquivo não seja encontrado em nenhum local, o servidor retorna ao
cliente uma mensagem do tipo:
[WARNING] FILE {filename} not found

O cliente, ao receber a confirmação da operação, encerra a conexão TCP com 
o servidor, que retorna ao estado de escuta e espera de uma nova conexão.

"""

import socket
import os

""" Definindo variáveis globais """
# Quantidade de blocos de bytes entre as comunicações
HEADER = 1024
# Formato de codificação/decodificação de mensagens
FORMAT = 'utf-8'

"""
Função principal. Em main(), o socket TCP será criado, as conexões cliente-servidor serão 
estabelecidas, operações serão invocadas, etc.
"""
def main():
    # Prompt para entrada do endereço IP, porta e nome do cliente
    SERVER = input("enter the ip address in the format x.x.x.x: ")
    PORT = int(input("enter the port: "))
    CLIENT_NAME = input("enter your name: ")

    # Atribuíndo o endereço da conexão TCP no endereço IP do servidor e na porta selecionada
    ADDR = (SERVER, PORT)
    
    # Criando o socket, instancializando o cliente e estabelecendo a conexão com o servidor
    client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    client.connect(ADDR)

    # Enviando CLIENT_NAME ao sercidor pelo socket
    send(client, CLIENT_NAME)

    # Recebendo resposta do servidor
    print(client.recv(HEADER).decode(FORMAT))

    # Recebendo a operação e invocando a função correspondente ao serviço solicitada
    op = input("enter a operation: ")
    if op == "DEP":
        deposit(client, op)
        pass
    elif op == "REC":
        recover(client, op)
        pass
    elif op == "DEL":
        delete(client, op)
        pass

    # Fechando conexão com o servidor
    client.close()

"""
Função para solicitar ao servidor o serviço de depósito de arquivos em algum(ns) local(ais)
do servidor.

Recebe como parâmetros o socket TCP client e a operação op.

Solicita do usuário a entrada dos valores para o nome do arquivo a ser depositado filename
e a quantidade de cópias a serem depositadas copies. Recebidos os valores, envia os dados
para o servidor individualmente através da função auxiliar send(). Utiliza ainda a função
auxiliar send_file() para fazer o envio ao servidor do arquivo filename no diretório atual
do processo cliente.
"""
def deposit(client, op):
    # mandando op para o servidor
    send(client, op)

    # pegando os parametros para mandar ao servidor
    filename = input("enter the file name to deposit: ")
    copies = input("enter the number of copies: ")

    send(client, copies)
    send(client, filename)

    # Checando se o arquivo existe no diretório atual
    if filename not in os.listdir(os.getcwd()):
        print(f"[WARNING] FiLE {filename} not found in this directory")
        client.send(str(0).encode(FORMAT))
        return
    else:
        client.send(str(1).encode(FORMAT))

    send_file(client, filename)

"""
Função para solicitar ao servidor o serviço de recuperação de arquivos em algum(ns) local(ais)
do servidor.

Recebe como parâmetros o socket TCP client e a operação op.

Solicita do usuário a entrada do valor para o nome do arquivo a ser solicitado filename. 
Recebido o valor, o envia para o servidor através da função auxiliar send(). Utiliza ainda a 
função auxiliar recv_file() para receber do servidor o arquivo solicitado.
"""
def recover(client, op):
    # mandando para o servidor
    send(client, op)

    # pegando os parametros para mandar ao servidor
    filename = input("enter the file name to recover: ")

    send(client, filename)
    recv_file(client, filename)


"""
Função para solicitar ao servidor o serviço de remoção de arquivos em todos os locais do 
servidor.

Recebe como parâmetros o socket TCP client e a operação op.

Solicita do usuário a entrada do valor para o nome do arquivo a ser removido filename. 
Recebido o valor, o envia para o servidor através da função auxiliar send().
"""
def delete(client, op):
    # mandando para o servidor
    send(client, op)

    # pegando os parametros para mandar ao servidor
    filename = input("enter the file name to delete: ")
    
    send(client, filename)


"""
Função auxiliar para receber do servidor a resposta da operação de list_files().
"""
def list_files(client):
    msg_length = client.recv(HEADER).decode(FORMAT)
    msg_length = int(msg_length)
    files = client.recv(msg_length).decode(FORMAT)
    print(files)

"""
Função auxiliar para enviar mensagens aos servidor por meio de uma conexão TCP já
estabelecida.

Recebe como parâmetros o socket TCP client e a mensagem a ser enviada.

Codifica a mensagem para o padrão apropriado de comunicação da conexão TCP, de
acordo com o formato FORMAT pré-definido e iteração de dados a HEADER bytes por
vez. Após a codificação, envia a mensagem ao servidor.
"""
def send(client, msg):
    # Formatando a mensagem
    message = msg.encode(FORMAT)
    msg_length = len(message)
    send_length = str(msg_length).encode(FORMAT)
    send_length += b' ' * (HEADER - len(send_length))

    # Enviando a mensagem
    client.send(send_length)
    client.send(message)
    print(client.recv(HEADER).decode(FORMAT))


"""
Função auxiliar para enviar um arquivo ao servidor por meio de uma conexão TCP já
estabelecida.

Recebe como parâmetros o socket TCP client e o nome do arquivo filename.

Abre o arquivo filename no atual diretório do processo cliente, lê uma quantidade
HEADER de bytes e envia ao servidor a quantidade de dados iterada. Após o envio de
todos os segmentos de dados, fecha o arquivo.
"""
def send_file(client, filename):
    f = open(filename, "rb")

    while True:
        bytes_read = f.read(HEADER)
        if not bytes_read:
            break
        client.send(bytes_read)
    f.close()

"""
Função auxiliar para receber um arquivo ao servidor por meio de uma conexão TCP já
estabelecida.

Recebe como parâmetros o socket TCP client e o nome do arquivo filename.

Abre o arquivo filename no atual diretório do processo cliente, recebe do servidor
uma quantidade HEADER de bytes e armazena na variável file_bytes. file_bytes recebe
dados até o fim da recepção de segmentos de bytes provindas do servidor. Após isso,
os dados de file_bytes são atribuídos a filename e o arquivo é fechado
"""
def recv_file(client, filename):
    # Abrindo arquivo filename
    f = open(filename, "wb")

    # Tamanho do arquivo, variável auxiliar para determinar parada de recebimento 
    # de dados
    filesize = client.recv(HEADER).decode(FORMAT)
    filesize = int(filesize)

    # Recebendo dados e escrevendo em filename
    while filesize > 0:
        bytes_read = client.recv(HEADER)
        f.write(bytes_read)
        filesize -= HEADER
    
    f.close()

# Executando a aplicação principal
main()
