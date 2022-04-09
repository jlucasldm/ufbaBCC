import re

def paginas(texto, linhas_por_pagina, caracteres_por_linhas):
    linhas = 1
    paginas = 1
    teto = caracteres_por_linhas
    termino_palavra = [m.start() for m in re.finditer(' ', texto)]
    #print(termino_palavra)

    for i in termino_palavra:
        if i+1 >= teto:
            linhas += 1
            teto += caracteres_por_linhas
        if linhas != 0 and linhas % (linhas_por_pagina + 1) == 0:
            paginas += 1
            linhas = 0
        print(i+1, '\t', linhas, '\t', teto, '\t', paginas)
    
    return paginas

while 1: 
    try:
        palavras, linhas_por_pagina, caracteres_por_linhas = input().split()
        #cada palavra deve ser escrita em uma linha
        texto = input() + " "
        print(paginas(texto, int(linhas_por_pagina), int(caracteres_por_linhas)))         
    except EOFError: 
        break



#se mana piedade tem |20
#casado com quincas |19
#borba apenas me |16
#daria uma esperanca |20
#colateral