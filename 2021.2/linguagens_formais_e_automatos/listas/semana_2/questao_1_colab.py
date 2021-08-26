def prod(a, b):
    if b == 0:
        return 0
    return a + prod(a, b-1)

a = int(input())
b = int(input())

print(prod(a,b))