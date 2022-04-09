'''
print("2i difere de 2i+2")
for i in range (1, 50):
    print("i:", i, "\t2i:", 2*i, "\t2i+2:", (2*i)+2)

print("\n2i difere de 2i-1")
for i in range (1, 50):
    print("i:", i, "\t2i:", 2*i, "\t2i-1:", (2*i)-1)

print("\ni difere de i+2")
for i in range (1, 50):
    print("i:", i, "\ti+2:", i+2)
'''

testes = []

def caso_testes(caracteres):
    for i in range(1, caracteres):
        formatter ='0'+str(i)+'b'
        for j in range(2**i):
            testes.append(format(j, formatter))

    #print(testes)
    return testes

print(caso_testes(8))
