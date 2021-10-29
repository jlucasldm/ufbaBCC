def corrige(palavra):
    if len(palavra) != 3:
        return palavra
    else:
        if palavra[:2] == "UR":
            return 'URI'
        elif palavra[:2] == "OB":
            return 'OBI'
        else:
            return palavra

n = int(input())
count = 0

resp = ''
for x in input().split():
    x = corrige(x)
    count += 1
    resp += str(x)

    if count != n:
        resp += " "

print(str(resp))
