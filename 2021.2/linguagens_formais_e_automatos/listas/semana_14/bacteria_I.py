while 1: 
    try:
        d = input()
        s = input()

        if d.count(s):
            print('Resistente')
        else:
            print('Nao resistente')         
    except EOFError: 
        break