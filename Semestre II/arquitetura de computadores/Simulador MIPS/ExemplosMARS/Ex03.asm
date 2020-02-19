# UFBA - MATA48 - 2019.1
# Implementa F = (G+H) - (I+J)

.data
F:	.word	0
G:	.word	35
H:	.word	20
I:	.word	200
J:	.word	100

.text   
.globl  main            
        
main:   la	$t0,G		# Carrega endereco de A em $t0
	lw	$t0,0($t0)	# Le valor de A para $t0
	la	$t1,H		# Carrega endereco de B em $t1
	lw	$t1,0($t1)	# Le valor de B para $t1
	la	$t3,I		# Carrega endereco de B em $t1
	lw	$t3,0($t3)	# Le valor de B para $t1
	la	$t4,J		# Carrega endereco de B em $t1
	lw	$t4,0($t4)	# Le valor de B para $t1
	add	$s0, $t0, $t1   # registrador $s0 contém g + h
        add	$s1, $t3, $t4   # registrador $s1 contém i + j
	sub 	$s2, $s0, $s1 

# Finalização do programa
	li	$v0,10		# system call for exit
	syscall			# Exit!
		
	
	
       
