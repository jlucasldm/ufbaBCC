import math
'''
//////// INTRODUÇÂO ////////
estatistica.py é uma biblioteca desenvolvida para executar operações e definir características a partir de
definições estatísticas. Qualquer arquivo que importe estatistica.py terá acesso às funções definidas neste
programa

Até o momento, são contemplados os seguintes conceitos:
    frequência total
    mediana
    média
    variância
    desvio padrão
    coeficiente de bowley
    assimetria
    quartil

Ao decorrer do semestre, novas funcionalidades serão implementadas



////// COMO UTILIZAR ///////
Para utilizar a biblioteca em seu projeto:
    1. importe o arquivo estatistica.py
    2. forneça, em forma de dicionário, os dados do gráfico em questão 
    na forma (característica : frequência) para cada dado
    3. utilize os métodos como bem entender!



// EXEMPLOS DE UTILIZAÇÂO //
Para os que não possuem familiaridade com a linguagem, uso de bibliotecas
ou outros conceitos, farei aqui uma descrição detalhada desse documento.
No entanto, partirei da ideia de que o leitor está habituado com o processo
de criar um arquivo .py, manipular variáveis, funções e executar um 
programa

1. importando estatistica.py
    Coloque este arquivo, estatística.py, no mesmo diretório (leia-se pasta)
    do arquivo do seu programa .py
        Por exemplo, se seu programa está na pasta documentos/estatística, se
        certifique que o arquivo estatistica.py também está dentro da pasta
        documentos/estatística
    
    No topo da página, escreva:
        import estatistica
    Isso será o suficiente para conseguir ter acesso a todas as funções desse
    arquivo

2. informando os dados do gráfico
    Todas as funções de estatistica.py correspondem a operações e identificação
    de características em um gráfico. Escolhi adotar a estrutura de dados 
    'dicionário' para inserir as principais informações do gráfico.

    Um dicionário é uma estrutura de dados declarada da forma:
        var = dict() ou
        var = {}
    onde os dados são pares 
        x:y
    sendo x chamado de "chave" (key) e y chamado de "valor" (value)
    Um exemplo de dicionário não-vazio seria:
        var = {3:7, 'azul':9, 0:'pedra'}  
    onde teríamos três elementos
        (3:7),
        ('azul':9),
        (0:'pedra')

    Para representar um gráfico em python, usando dicionário, decidi
    adotar o formato:
        (característica : frequência)
    onde tanto característica quanto frequência devem ser números
    inteiros* dos valores das características

    Dando um exemplo objetivo, suponhamos o gráfico xXy onde
    x = idade de crianças interessadas por cowboy bebop (característica)
    y = quantidade de indivíduos (frequência)
    
    7
    6             #
    5             #
    4         #   #
    3       # # # #
    2 #   # # # # #
    1 # # # # # # #
      3 4 5 6 7 8 9

    Para inserir esses valores no nosso código, iríamos declarar:
        data = {3:2, 4:1, 5:2, 6:3, 7:4, 8:3, 9:6}
    mantendo a relação (característica : frequência), inserindo os
    valores inteiros*

3. utilizando as funções
    Uma vez que estatistica.py foi importado no seu programa e o
    gráfico foi definido por meio de um dicionário, agora é só utilizar
    a função desejada e manipular seus retornos em seu código.

    Lembre-se que as funções possuem parâmetros específicos e as
    funções devem ser chamadas respeitando a sintaxe
        estatistica.funcao_que_voce_quer(parametro_rqeuisitado)

    Por exemplo, se tivermos um porgrama:
        import estatitica
        var = {3:2, 4:1, 5:2, 6:3, 7:4, 8:3, 9:6}
    e quisermos encontrar a frequência total do gráfico, precisamos
    chamar a função 
        frequencia_total(data)
    respeitando o requisito da sintaxe e do parâmetro requisitado da
    função
    
    Logo, teríamos o seguinte programa:
        import estatistica
        var = {3:2, 4:1, 5:2, 6:3, 7:4, 8:3, 9:6}
        freq_total = estatistica.frequencia_total(var)
        print(freq_total)   //vai printar a frequência total
    
    É muito importante se atentar a(os) qual(is) parâmetro(s) a função
    está requisitando. É possível ter essa informação consultando os
    comentários de cada função



//// EXEMPLO EM CÓDIGO ////
Esse foi o código que utilizei para a semana 2. Espero que sirva
de exemplo para implementação, caso ainda haja dúvidas sobre o uso
da biblioteca em um programa
    /////////////////////////////////////////////
    import estatistica

    data = {16:12, 17:8, 18:7, 19:14, 20:13, 21:6, 22:13, 23:9, 24:6, 25:6, 26:6}   #grafico {idade: frequencia}

    ordered_data = estatistica.ordered_data(data)
    mediana = estatistica.mediana(ordered_data)
    frequencia_total = estatistica.frequencia_total(data)
    media = estatistica.media(frequencia_total, data)
    variancia = estatistica.variancia(frequencia_total, media, data)
    desvio_padrao = estatistica.desvio_padrao(variancia)

    print("Mediana:\t\t", mediana)
    print("Frequencia Total:\t", frequencia_total)
    print("Media:\t\t\t", media)
    print("Variancia:\t\t", variancia)
    print("Desvio Padrao:\t\t", desvio_padrao)
    /////////////////////////////////////////////


*   até agora, só usamos variáveis quantitativas. Nem sei exatamente
    como é a abordagem desses conceitos para variáveis qualitativas.
    Devo estudar mais um pouco e resolver essa situação
    
'''
# Função auxiliar para garantir que a entrada de dados do gráfico esteja
# ordenada pelos valores das características (keys)
def ordenar_dict(data):
    aux = {}
    for i in sorted(data.keys()):
        aux[i] = data[i]
    return aux


# Recebe o dicionário com os valores do gráfico
# Retorna uma lista com todos os valores das características ordenados crescentemente
def ordered_data(data):
    data = ordenar_dict(data)
    ordered_data = []
    for i in data:
        for j in range(data[i]):
            ordered_data.append(i)
    return ordered_data

# Recebe o dicionário com os valores do gráfico
# Retorna a frequência total
def frequencia_total(data):
    data = ordenar_dict(data)
    aux = 0
    for i in data:
        aux += data[i]
    return aux

# Recebe a lista com todos os valores ds características ordenados crescentemente
# Retorna o valor da mediana
def mediana(ordered_data):
    return ordered_data[int(math.floor(len(ordered_data)/2)) - 1]

# Recebe a frequência total e o dicionário com os valores do gráfico
# Retorna o valor da média das características
def media(frequencia_total, data):
    data = ordenar_dict(data)
    aux = 0
    for i in data:
        aux += i * data[i]
    aux /= frequencia_total
    return aux

# Recebe a frequência total, a média e o dicionário com os valores do gráfico
# Retorna a variância
def variancia(frequencia_total, media, data):
    data = ordenar_dict(data)
    aux = 0
    for i in data:
        aux += data[i] * ((i - media)**2)
    aux /= frequencia_total
    return aux

# Recebe a variância
# Retorna o desvio padrão
def desvio_padrao(variancia):
    return math.sqrt(variancia)


#############################################################
####################   SEMANA 3    ##########################
#############################################################

# Recebe os valores dos quartis 1, 2 e 3
# Retorna o coeficiente de bowley
def coef_bowley(q1, q2, q3):
    return float((q3 - 2*q2 + q1)/(q3 - q1))

# Recebe os valores dos quartis 1, 2 e 3
# Retorna, em texto, a assimetria do gráfico
def assimetria(q1, q2, q3):
    if (q2 - q1) < (q3 - q2):
        return 'assimetria a direita'
    elif (q2 - q1) > (q3 - q2):
        return 'assimetria a esquerda'
    else:
        return 'simetrica'

# Recebe a lista com todos os valores ds características ordenados crescentemente,
# o comprimento dessa lista e o número desejado do cálculo sobre o gráfico (como 
# 0.25, 0.50, 0.75)
# Retorna o valor do quartil
def quartil(ordered_data, len_ordered_data, qnt_quartil):
    aux = (len_ordered_data + 1) * qnt_quartil
    if aux % int(aux) == 0:
        return ordered_data[int(aux) - 1]
    else:
        low = int(math.floor(aux))
        high = int(math.ceil(aux))
        return (ordered_data[low - 1] + ordered_data[high - 1])/2