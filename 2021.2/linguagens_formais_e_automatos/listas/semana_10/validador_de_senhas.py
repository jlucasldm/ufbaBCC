def validar(senha):
    maiuscula = 0
    minuscula = 0
    numero = 0
    
    for i in senha:
        if ord(i) >= 48 and ord(i) <= 57:
            numero += 1
        elif ord(i) >= 65 and ord(i) <= 90:
            maiuscula += 1
        elif ord(i) >= 97 and ord(i) <= 122:
            minuscula += 1

    if (len(senha) >= 6 and len(senha) <= 32) and (maiuscula + minuscula + numero == len(senha)) and maiuscula >= 1 and minuscula >= 1 and numero >= 1:
        return 'Senha valida.'
    else:
        return 'Senha invalida.'

while 1: 
    try: 
        print(validar(input()))         
    except EOFError: 
        break