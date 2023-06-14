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
removido do servidor. O servidor então remove o arquivo solicitado em todas
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
# Endereço IP do servidor, independente do sistema final onde server.py esteja sendo executado
SERVER = socket.gethostbyname(socket.gethostname()) 
# Formato de codificação/decodificação de mensagens
FORMAT = 'utf-8'
# Diretório raíz do servidor
DIRECTORY = '.\\server\\'


"""
Função principal. Em main(), o socket TCP será criado, as conexões cliente-servidor serão 
estabelecidas, operações serão invocadas, etc.
"""
def main():
    # Prompt para definir número de porta
    PORT = int(input("enter the port: "))
    # Atribuíndo o endereço da conexão TCP no endereço IP do servidor e na porta selecionada
    ADDR = (SERVER, PORT)

    # Criando o socket, instancializando o servidor e colocando-o no estado de espera por conexão
    server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server.bind(ADDR)
    server.listen()
    print(f"[LISTENING] server is listening on IP: {SERVER}, Port: {PORT}")

    while True:
        # Estabelecida uma conexão TCP com o cliente
        conn, addr = server.accept()
        print(f"[START] server is running. Accepted connection at address: \n{addr}")
        
        # Recebendo o nome do cliente e atribuindo-o a client_name
        msg_length = conn.recv(HEADER).decode(FORMAT)
        msg_length = int(msg_length)
        client_name = conn.recv(msg_length).decode(FORMAT)

        # Sinalizando recebimento
        print("[", addr, "] Message received. Client name: ", client_name)
        conn.send(f"[{addr}] Message received. Client name: {client_name}".encode(FORMAT))

        # Checagem de arquivos em .\server\{local}\client_name, para algum(ns) local(is) no servidor
        list_files(conn, client_name)
          
        # Recebendo op, o serviço a ser executado pelo servidpr
        msg_length = conn.recv(HEADER).decode(FORMAT)
        msg_length = int(msg_length)
        op = conn.recv(msg_length).decode(FORMAT)

        # Sinalizando recebimento
        print(f"[{addr}] Operation {op} received", op)
        conn.send(f"[{addr}] Operation {op} received".encode(FORMAT))

        # Invocando a função correspondente à operação solicitada
        if op == "DEP":
            deposit(conn, client_name)
        elif op == "REC":
            recover(conn, client_name)
        elif op == "DEL":
            delete(conn, client_name)

"""
Função para conuslta do diretório client_name em algum dos locais (dispotivos) do servidor.

Recebe como parâmetros o socket TCP conn e o nome do cliente client_name. 

Instancializa o diretório .\\server\\, caso não exista, e percorre por todos os locais 
(dispositivos) do servidor buscando pelo diretório client_name. Acessa todos os arquivos de 
propriedade do cliente e retorna a ele uma resposta sinalizando se existem ou não arquivos 
dele em algumdispotivivo do servidor.
"""
def list_files(conn, client_name):
    # Variável para armazenar possíveis arquivos do cliente
    file_list = []

    # Instancializndo DIRECTORY, caso não exista
    if not os.path.exists(DIRECTORY):
        os.makedirs(DIRECTORY)

    # Armazenando uma lista com todas os locais (máquinas) de DIRECTORY
    directories = os.listdir(DIRECTORY)
    
    # Para cada subpasta do servidor, vamos procurar o diretorio client_name
    for folder in directories:
        # Setando o path da subpasta folder
        folder_path = DIRECTORY + folder + "\\"
        # Retornando tudo do diretorio folder_path
        folder_files = os.listdir(folder_path)

        # Caso exista o diretório client_name no local (dispositivo) folder
        if client_name in folder_files:
            client_path = folder_path + client_name + "\\"
            client_files = os.listdir(client_path)

            # Pegando todos os arquivos em .\server\folder\client_name e armazenando na lista file_list
            for files in client_files:
                if files not in file_list:
                    file_list.append(files)

    # Colocar todos os arquivos do cliente em uma string
    files_found = ""
    if file_list:
        print(f"[SUCESS] {client_name}'s files found: {file_list}")
        for files in file_list:
            files_found += files + ","
        files_found = files_found[:-1]
    else:
        print(f"[WARNING] No files found to {client_name}")

    # Sinalizando o cliente o resultado da busca
    if files_found:
        conn.send(f"Files to {client_name} found: {files_found}".encode(FORMAT))
    else:
        conn.send(f"No files to {client_name} found".encode(FORMAT))

"""
Função para atender o serviço de depósito de arquivos do cliente em algum(ns) local(is)
do servidor. 

Recebe como parâmetros o socket TCP conn e o nome do cliente client_name.

Se comunica com o cliente para receber outros três parâmetros, a quantidade de cópias
do arquivo(s) a ser(em) depositado(s) copies, o nome do arquivo a ser copiado filename
e o conteúdo, em bytes, do arquivo (recebido de blocos em blocos de tamanho HEADER de 
dados). Recebidos os dados, os atribui à variável file_bytes. Instancializa uma 
quantidade copies de locais (dispositivos) no servidor com subpasta de nome client_name,
caso não exista. Em cada um desses diretórios, cria um arquivo de nome filename e
atribui a ele o conteúdo de file_bytes.

Para cada recebimento de dados, sinaliza ao cliente o sucesso da operação.
"""
def deposit(conn, client_name):
    # Recebendo o numero de copias do arquivo a ser depositado, copies
    msg_length = conn.recv(HEADER).decode(FORMAT)
    msg_length = int(msg_length)
    copies = conn.recv(msg_length).decode(FORMAT)
    copies = int(copies)

    # Sinalizando recebimento
    print(f"[SUCESS] Number of copies recieved: {copies}")
    conn.send(f"[SUCESS] Number of copies recieved: {copies}".encode(FORMAT))

    # Recebendo o nome do arquivo a ser depositado no servidor, filename
    msg_length = conn.recv(HEADER).decode(FORMAT)
    msg_length = int(msg_length)
    filename = conn.recv(msg_length).decode(FORMAT)

    # Sinalizando recebimento
    print(f"[SUCESS] File name recieved: {filename}")
    conn.send(f"[SUCESS] File name recieved: {filename}".encode(FORMAT))

    # Recebendo resposta se o arquivo a ser depositado existe no diretório do cliente
    found = conn.recv(HEADER).decode(FORMAT)

    if int(found) == 0:
        print(f"[WARNING] File {filename} does'nt exists on client's directory")
        return

    # Recebendo os dados de filename
    file_bytes = bytes()
    while True:
        bytes_read = conn.recv(HEADER)
        if not bytes_read:
            break
        file_bytes += bytes_read

    # Instancializa todas as copies máquinas no servidor (criando diretórios de nome 0, 1, ..., copies)
    # e criando a subpasta client_name em cada uma delas, caso não exista. Para cada instância do local
    # client_name, cria um arquivo de nome filename e atribui a ele os dados de file_bytes
    for instance in range(copies):
        if not os.path.exists(DIRECTORY + str(instance) + "\\" + client_name + "\\"):
            os.makedirs(DIRECTORY + str(instance) + "\\" + client_name + "\\")
        f = open(DIRECTORY + str(instance) + "\\" + client_name + "\\" + filename, "wb")
        f.write(file_bytes)
        f.close()

    # Sinalizando sucesso da operação
    conn.send(f"[SUCESS] File {filename} created".encode(FORMAT))
    print(f"[SUCESS] File {filename} created")


"""
Função para atender o serviço de recuperação de arquivos do cliente no servidor. 

Recebe como parâmetros o socket TCP conn e o nome do cliente client_name.

Se comunica com o cliente para receber o nome do arquivo a ser recuperado filename. 
Recebido o dado, itera sobre todos os locais do servidor buscando um diretório de nome
client_name. Se encontrado, checa a existência do arquivo filename na lista de
arquivos no diretório. Se encontrado, itera sobre os dados de filename e envia ao
cliente de blocos em blocos de dados de tamanho HEADER (definido pela aplicação como
1024 bytes).

Para cada recebimento de dados, sinaliza ao cliente o sucesso da operação.
"""
def recover(conn, client_name):
    # Recebendo o nome do arquivo a ser depositado no servidor, filename
    msg_length = conn.recv(HEADER).decode(FORMAT)
    msg_length = int(msg_length)
    filename = conn.recv(msg_length).decode(FORMAT)

    # Sinalizando recebimento
    print(f"[SUCESS] File name recieved: {filename}")
    conn.send(f"[SUCESS] File name recieved: {filename}".encode(FORMAT))

    # Instancializndo DIRECTORY, caso não exista
    if not os.path.exists(DIRECTORY):
        os.makedirs(DIRECTORY)

    # Armazenando uma lista com todas os locais (máquinas) de DIRECTORY
    directories = os.listdir(DIRECTORY)

    # Para cada subpasta do servidor, vamos procurar o diretorio client_name
    for folder in directories:
        # Setando o path da subpasta folder
        folder_path = DIRECTORY + folder + "\\"
        # Retornando tudo do diretorio folder_path
        folder_files = os.listdir(folder_path)

        # Caso exista o diretório client_name no local (dispositivo) folder
        if client_name in folder_files:
            client_path = folder_path + client_name + "\\"
            client_files = os.listdir(client_path)

            # Caso o arquivo filename existe no local, seus dados são lidos e enviados ao cliente
            # de blocos em blocos de bytes de tamanho HEADER
            if filename in client_files:
                f = open(client_path + "\\" + filename, "rb")
                file_size = os.path.getsize(client_path + "\\" + filename)
                conn.send(str(file_size).encode(FORMAT))
                while True:
                    bytes_read = f.read(HEADER)
                    if not bytes_read:
                        break
                    conn.send(bytes_read)
                f.close()
                return

    return


"""
Função para atender o serviço de remoção de arquivos do cliente no servidor. 

Recebe como parâmetros o socket TCP conn e o nome do cliente client_name.

Se comunica com o cliente para receber o nome do arquivo a ser removido filename. 
Recebido o dado, itera sobre todos os locais do servidor buscando todos os diretóriod 
de nome client_name. Para cada instância encontrada, caso exista o arquivo filename,
o remove do local.

Para cada recebimento de dados, sinaliza ao cliente o sucesso da operação.

Após a remoção, sinaliza o cliente o sucesso da operação.
"""
def delete(conn, client_name):
    # Recebendo o nome do arquivo a ser removido, copies
    msg_length = conn.recv(HEADER).decode(FORMAT)
    msg_length = int(msg_length)
    filename = conn.recv(msg_length).decode(FORMAT)

    # Sinalizando recebimento
    print(f"[SUCESS] File name recieved: {filename}")
    conn.send(f"[SUCESS] File name recieved: {filename}".encode(FORMAT))

    # Setando a variável de sinalização de remoção
    removed = False

    # Instancializndo DIRECTORY, caso não exista
    if not os.path.exists(DIRECTORY):
        os.makedirs(DIRECTORY)

    # Armazenando uma lista com todas os locais (máquinas) de DIRECTORY
    directories = os.listdir(DIRECTORY)

    # Para cada subpasta do servidor, vamos procurar o diretorio client_name
    for folder in directories:
        # Setando o path da subpasta folder
        folder_path = DIRECTORY + folder + "\\"
        # Retornando tudo do diretorio folder_path
        folder_files = os.listdir(folder_path)

        # Caso exista o diretório client_name no local (dispositivo) folder
        if client_name in folder_files:
            client_path = folder_path + client_name + "\\"
            client_files = os.listdir(client_path)

            # Caso o arquivo existe no local, ele é removido
            if filename in client_files:
                os.remove(client_path + "\\" + filename)
                removed = True
        
    # Sinalizando sucesso da operação
    if removed:
        print(f"[SUCESS] File {filename} deleted")
        conn.send(f"[SUCESS] File {filename} deleted".encode(FORMAT))
    else:
        print(f"[WARNING] FiLE {filename} not found")
        conn.send(f"[WARNING] FiLE {filename} not found".encode(FORMAT))



# Executando a aplicação principal
main()