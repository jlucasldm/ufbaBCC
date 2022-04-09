def solucao( linhas_por_pagina, caracteres_por_linhas, texto):
    paginas = 1
    linha = 0
    index = 0
    i = 0

    while i < len(texto):
        while texto[i] == " " and (index == 0 or index == caracteres_por_linhas):
            i += 1
        if index == caracteres_por_linhas:
            linha += 1
            index = 0
        if linha == linhas_por_pagina:
            paginas += 1
            linha = 0
        i += 1
        index += 1

    return str(paginas)

while 1: 
    try:
        palavras, linhas_por_pagina, caracteres_por_linhas = input().split()
        #cada palavra deve ser escrita em uma linha
        texto = input()
        print(solucao(int(linhas_por_pagina), int(caracteres_por_linhas), texto))         
    except EOFError: 
        break