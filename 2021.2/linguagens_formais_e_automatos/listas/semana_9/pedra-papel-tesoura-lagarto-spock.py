def jogo(mao1, mao2):
    if mao1 == 'tesoura' and mao2 == 'papel' or mao2 == 'tesoura' and mao1 == 'papel':
        return 'tesoura'
    elif mao1 == 'papel' and mao2 == 'pedra' or mao2 == 'papel' and mao1 == 'pedra':
        return 'papel'
    elif mao1 == 'pedra' and mao2 == 'lagarto' or mao2 == 'pedra' and mao1 == 'lagarto':
        return 'pedra'
    elif mao1 == 'lagarto' and mao2 == 'spock' or mao2 == 'lagarto' and mao1 == 'spock':
        return 'lagarto'
    elif mao1 == 'spock' and mao2 == 'tesoura' or mao2 == 'spock' and mao1 == 'tesoura':
        return 'spock'
    elif mao1 == 'tesoura' and mao2 == 'lagarto' or mao2 == 'tesoura' and mao1 == 'lagarto':
        return 'tesoura'
    elif mao1 == 'lagarto' and mao2 == 'papel' or mao2 == 'lagarto' and mao1 == 'papel':
        return 'lagarto'
    elif mao1 == 'papel' and mao2 == 'spock' or mao2 == 'papel' and mao1 == 'spock':
        return 'papel'
    elif mao1 == 'spock' and mao2 == 'pedra' or mao2 == 'spock' and mao1 == 'pedra':
        return 'spock'
    elif mao1 == 'pedra' and mao2 == 'tesoura' or mao2 == 'pedra' and mao1 == 'tesoura':
        return 'pedra'

def solucao(mao1, mao2):
    if mao1 == mao2:
        return 'empate'
    elif jogo(mao1, mao2) == mao1:
        return 'rajesh'
    elif jogo(mao1, mao2) == mao2:
        return 'sheldon'

n = int(input())

for i in range(n):
    a,b = input().split()
    print(solucao(a,b))