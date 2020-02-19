# UFBA - MATA48 - 2019.1
# Exemplo de soma de dois numeros inteiros

.data
A:	.word	40		# declaracao de variavel inteiro (word)
B:	.word	30
C:	.word	0

.text   
.globl  main            
        
main:   la	$t0,A		# load address - carrega endereço de A em $t0
	lw	$t0,0($t0)	# load word - lê valor de A para $t0
	la	$t1,B		# carrega endereço de B em $t1
	lw	$t1,0($t1)	# lê valor de B para $t1
	add	$t0,$t0,$t1	# $t0 recebe A + B
	la	$t2,C		# carrega endereço de C em $t2
	sw	$t0,0($t2)	# C recebe A+B
	
# Finalização do programa.
	li	$v0,10		# chamada de sistema para encerrar o programa (código 10 em $v0)
	syscall		
