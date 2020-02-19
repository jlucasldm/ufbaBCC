# UFBA - MATA48 - 2019.1
# Copia os 5 elementos do vetor para vetor2

.data
vetor :   .word 1 2 3 4 5 6 7 8 9 10	# vetor de 10 elementos
vetor2 :  .word 0 : 9  		  	# vetor de 10 elementos
tamanho : .word 10

.text
.globl  main            
        
main: 	li $t4, 0  	 # contador de quantos elementos foram copiados
	la $t2, tamanho  # tamanho do vetor (quantidade de elementos)
	lw $t2, 0($t2)

	la $t1, vetor   # carrega endereço do primeiro elemento do vetor em $t1
	la $t5, vetor2	# carrega endereço do primeiro elemento do vetor2 em $t5

loop:	lw $t3, 0($t1)	    # $t3 recebe vetor[$t1]
        addi $t3, $t3, 100  # vetor[i] += 100 => $t3 = $t3 + 100
	sw $t3, 0($t5)	    # vetor2[$t1] recebe vetor[$t1]
	addi $t1, $t1, 4    # incrementa para a próxima posição de vetor => 4 bytes
	addi $t5, $t5, 4    # incrementa para a próxima posição de vetor2 => 4 bytes
	addi $t4, $t4, 1    # incrementa o contador de elementos copiados
	bne $t4,$t2, loop   # se contador for diferente de 5, volta para loop

# Finalização do programa
	li $v0,10		# system call for exit
	syscall			# Exit!
