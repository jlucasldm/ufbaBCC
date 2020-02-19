# UFBA - MATA48 - 2019.1
# Exemplo de soma de dois numeros reais

.data
A:	.float	40.0		# declaracao de variavel float
B:	.float	30.0

.text   
.globl  main            	
        
main:   l.s $f0, A		# carrega valor float para $f0
	l.s $f1, B		# carrega valor float para $f1
	add.s $f2, $f0, $f1	# soma de valores float, com resultado em $f2
	
# Finalização do programa.
	li	$v0,10		# chamada de sistema para encerrar o programa (código 10 em $v0)
	syscall		
