def solucao(sequence, op):
    count = 0
    r = 0
    for i in sequence:
        if i == 'W' and r != 0:
            count += 2
            r = 0
        elif i == 'W' and r == 0:
            count += 1    
        elif i == 'R':
            r += 1
            if r == op:
                count += 1
                r = 0
    if r != 0:
        count += 1
    return count

while 1: 
    try:
        sequence = input()
        op = int(input())
        print(solucao(sequence, op))         
    except EOFError: 
        break
