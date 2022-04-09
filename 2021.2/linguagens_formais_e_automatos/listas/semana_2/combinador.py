n = int(input())
strings = []
string = ""
output = []

for i in range(n):
    strings.append(input().split())

for i in range(n):
    if len(strings[i][0]) > len(strings[i][1]):
        max_len = len(strings[i][0])
    else:
        max_len = len(strings[i][1])
    
    for j in range(max_len):
        if j < len(strings[i][0]):
            string += str(strings[i][0][j])
        if j < len(strings[i][1]):
            string += str(strings[i][1][j])
    
    output.append(string)
    string = ""

#print(strings)
#print(output)

for i in range(n):
    print(str(output[i]))