def solucao(texto):
    html = ""
    i = 0
    b = 0
    for p in texto:
        if p == '_':
            i += 1
            if i % 2 == 1:
                html += '<i>'
            else:
                html += '</i>'
        elif p == '*':
            b += 1
            if b % 2 == 1:
                html += '<b>'
            else:
                html += '</b>'
        else:
            html += p

    return html

while 1: 
    try: 
        print(solucao(input()))         
    except EOFError: 
        break