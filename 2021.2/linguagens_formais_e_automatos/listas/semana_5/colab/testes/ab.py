def caso_testes(caracteres):
    testes =[]
    for i in range(1, caracteres):
        formatter ='0'+str(i)+'b'
        for j in range(2**i):
            testes.append((format(j, formatter).replace('0', 'a').replace('1', 'b')))

    #print(testes)
    return testes
