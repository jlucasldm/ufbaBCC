def solution():
    while True:
        d, n = input().split()

        if int(d) == 0 and int(n) == 0:
            return

        n = n.replace(d, '')

        if len(n) == 0:
            n = '0'
        
        print(str(int(n)))

solution()