#int leaf_example (int g, int h, int i, int j)
#{
#  int f;
#  f = (g + h) - (i + j);
#  return f;
#}

.data
  F: .word 0
  G: .word 40
  H: .word 15
  I: .word 20
  J: .word 25

.text
  .globl main

main:	la $t0, G   # le endereco de G para $t0
	la $t1, H   # le endereco de H para $t1
	la $t2, I   # le endereco de I para $t2
	la $t3, J   # le endereco de J para $t3
	la $t4, F

	lw $a0, 0($t0) # le valor de G para $a0
	lw $a1, 0($t1) # le valor de H para $a1
	lw $a2, 0($t2) # le valor de I para $a2
	lw $a3, 0($t3) # le valor de j para $a3

	addiu $sp,$sp,-4	# Aloca espaço na pilha para 1 palavra (4 bytes)
	sw    $ra,0($sp)	# Salva o $ra no topo da pilha
	jal   leaf_example	# Chama a função leaf_example
	lw    $ra,0($sp)	# Recupera o endereço de retorno
	addiu $sp,$sp, 4
	add   $t4,$v0,$zero	# Escreve resultado na variável
	
	li $v0, 1
	move $a0, $t4
	syscall

	j Exit			# desvio incondicional para o final do programa

leaf_example:  	sub $sp, $sp, 12  # ajusta a pilha para abrir espaço para guardar 3 itens
		sw  $t1, 8($sp)   # salva o conteúdo do registrador $t1 para preservá-lo
		sw  $t0, 4($sp)   # salva o conteúdo do registrador $t0 para preservá-lo
		sw  $s0, 0($sp)   # salva o conteúdo do registrador $s0 para preservá-lo

		add $t0, $a0, $a1 # registrador $t0 contém g + h
	      	add $t1, $a2, $a3 # registrador $t1 contém i + j
              	sub $s0, $t0, $t1 # f recebe $t0 - $t1, resultado final

	        add $v0, $s0, $zero # retorna f ($v0 = $s0 + 0)

	        lw  $s0, 0($sp)    # restaura o valor de $s0 para o chamador
	        lw  $t0, 4($sp)    # restaura o valor de $t0 para o chamador
	        lw  $t1, 8($sp)    # restaura o valor de $t1 para o chamador
	        add $sp, $sp, 12   # ajusta a pilha de modo a remover 3 itens
	        jr $ra             # desvia de volta para o programa que chamou

Exit:	li $v0, 10		# chamada de sistema para encerrar o programa
	syscall			# Exit
