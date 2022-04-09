def passagem(n):
    n = n.replace('+', ' ').replace('=', ' ').split(' ')
    
    if n[0].isalpha():
        return int(n[2]) - int(n[1])
    elif n[1].isalpha():
        return int(n[2]) - int(n[0])
    else:
        return int(n[0]) + int(n[1])

while 1: 
    try: 
        print(passagem(input()))         
    except EOFError: 
        break