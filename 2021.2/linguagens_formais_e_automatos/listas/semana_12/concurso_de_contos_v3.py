import math

def solucao(n, l, c, texto):
    pagina = 0
    while len(texto) > 0:
      pagina += 1/l
      if len(texto) <= c:
        break
      if texto[c-1] == ' ':
        texto = texto[c:]
      elif texto[c] == ' ':
        texto = texto[c+1:]
      else:
        linhas = texto[:c].rfind(' ')
        if linhas == 0:
          pagina -= 1/l
        texto = texto[linhas+1:]
    print(math.ceil(round(pagina, 5)))


while 1:
  try:
    texto = str(input())
    n, l, c = [int(i) for i in texto.split(' ')]
    texto = str(input())
    solucao(n, l, c, texto)
    
  except EOFError:
    break