def espelho(init, end):
    number = ''
    for i in range(init, end + 1):
        number += str(i)
    inverse = number[::-1]
    number += inverse
    return number

n = int(input())
for i in range(n):
    init, end = input().split()
    print(espelho(int(init), int(end)))