n = int(input())
output = ""
strings = []

for j in range(n):
    s1, s2 = input().split()

    for i in range(min(len(s1), len(s2))):
        output += s1[i] + s2[i]
    
    output += s1[i+1:] + s2[i+1:]
    strings.append(output)
    output = ""

for i in range(n):
    print(strings[i])