def pokemons_faltantes(colecao):
    faltantes = 151 - int(len(colecao))
    return 'Falta(m) ' + str(faltantes) + ' pomekon(s).'

n = int(input())
colecao = []
for i in range(n):
    pokemon = input()
    if pokemon not in colecao:
        colecao.append(pokemon)
print(pokemons_faltantes(colecao))
