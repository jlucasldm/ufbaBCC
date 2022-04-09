def solucao(arr):
    hashf = 0

    for i in range(len(arr)):
        for char in range(len(arr[i])):
            hashf += ord(arr[i][char]) - 65 + i + char
    return hashf


n = int(input())
for i in range(n):
    arr = []
    m = int(input())
    for j in range(m):
        arr.append(input())
    print(solucao(arr))