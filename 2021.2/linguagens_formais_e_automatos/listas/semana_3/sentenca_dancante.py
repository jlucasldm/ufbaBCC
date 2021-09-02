def solucao(s):
    upper = True
    res = ''

    for i in range(len(s)):
        if not s[i] == ' ':
            if upper == True:
                res += s[i].upper()
                upper = False
            else:
                res += s[i].lower()
                upper = True
        else:
            res += s[i]
            
    print(res)
    

while 1: 
    try: 
        solucao(input())         
    except EOFError: 
        break
