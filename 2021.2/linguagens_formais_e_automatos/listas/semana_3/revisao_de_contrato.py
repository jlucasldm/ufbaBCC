#funcao principal
def solution():
    while True:
        #entrada de dados
        #d == digito a ser removida
        #n == string a ser iterada
        d, n = input().split()
        
        #condicao de parada do laco. enquanto as entradas
        #forem diferentes de 0, as linhas de entrada serao
        #lidas
        if int(d) == 0 and int(n) == 0:
            return
        
        #substituir todas as ocorrencias do caracter d
        #na string n por '', uma string vazia
        n = n.replace(d, '')

        #certificando que, caso todos os digitos de n
        #forem removidos, a string ainda tera valor numerico
        if len(n) == 0:
            n = '0'
        
        #printando o valor numerico da string resultante
        print(str(int(n)))

solution()