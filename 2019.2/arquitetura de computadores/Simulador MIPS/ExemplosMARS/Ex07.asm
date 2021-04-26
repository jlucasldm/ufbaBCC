# UFBA - MATA48 - 2019.1

# vetor[10] = {1,2,3,4,5,6,7,8,9,10}
# indice = 0
#
# while (indice < 10)
# do begin
#   vetor[indice] = vetor[indice] + 100
#   indice = indice + 1
# end

.data
vetor :   .word 1 2 3 4 5 6 7 8 9 10	# vetor de 10 elementos
indice :  .word 0

.text
.globl  main            
        
main:	la $t0, vetor	 # carrega em $t0 o endereco do vetor 	
	la $t1, indice 	 # carrega em $t1 o indice do vetor
        lw $t1, 0($t1)
	li $t2, 100	 # carrega em $t2 o valor escalar a ser somado no vetor
	li $t3, 10       # carrega em $t3 o tamanho do vetor (escalar 10)

lwhile:	slt $s0, $t1, $t3 	  # testa se indice < 10 ($t1 < $t3). Se for, $s0 recebe 0.	
	bne $s0, $zero, somavetor # se $s0 = 0, desvia para somavetor
	j saida		  	  # senao desvia para saida -> fim do laco

somavetor:	add $t4, $t1, $t1	# $t4 recebe indice * 2
		add $t4, $t4, $t4 	# $t4 recebe indice * 4 -> alinhamento de memoria
		add $t4, $t4, $t0 	# $t4 recebe o endereço de vetor[indice]
		lw  $t5, 0($t4) 	# $t5 recebe o valor de vetor[indice]
		addi $t5, $t5, 100	# $t5 recebe vetor[indice] + 100
		sw $t5, 0($t4)		# vetor[indice] = vetor[indice] + 100 -> novo valor		
		addi $t1, $t1, 1	# indice = indice + 1
		j lwhile		# volta para o laço while

# Finalização do programa
saida: 	li	$v0,10	    # system call for exit
	syscall		    # Exit!
