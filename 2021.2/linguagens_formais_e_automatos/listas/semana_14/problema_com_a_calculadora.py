n = int(input())

for i in range(n):
    data = input()
    total = 0
    numero = ''

    for char in range(len(data)):
        # print(char)
        # print(len(data)-1)
        if ord(data[char]) >= 48 and ord(data[char]) <= 57:
            numero += data[char]
            #print('numero:', numero)
        elif ord(data[char]) < 48 or ord(data[char]) > 57 and numero != '':
            total += int(numero)
            #print(numero)
            numero = ''
        if char == (len(data) - 1) and numero != '':
            #print('dale')
            total += int(numero)

    print(total)


# Ab23s249ttu21
# At01v021kkk12
# xx14l134mjm01