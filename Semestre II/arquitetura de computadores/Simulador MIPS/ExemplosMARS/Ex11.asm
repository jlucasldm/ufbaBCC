# UFBA - MATA48 - 2019.1
# Exemplo de fatorial - adaptado de MORAES - 23/agosto/2006
# Programa que calcula o fatorial de um numero inteiro sem sinal.

# Chama a funcao fact().
# O argumento para fact() eh passado via o registrador de argumento $a0.
# fact() retorna o resultado no registrador de valor $v0.

# main() {
#   int num = 3;
#   int result = 0;
#   result = fact(num);
# }
# int fact (int n) {
#   if(n<1)
#     return 1;
#   return (n * fact (n - 1));
# }

.data
  num: 		.word 0x0a
  result:	.word 0

.text
.globl main

main:	la 	$t0,num		# Carrega o endereço de num em $t0
	lw 	$a0,0($t0)	# $a0 contem o numero cujo fatorial deve ser calculado
      	addiu	$sp,$sp,-4	# Aloca espaco na pilha para 1 palavra (4 bytes)
	sw	$ra,0($sp)	# Salva o $ra no topo da pilha
	jal	fact		# Chama a funcao recursiva fact(num)
				# Resultado do fatorial deve retornar em $v0
	lw	$ra,0($sp)	# Recupera o endereco de retorno
	addiu	$sp,$sp, 4
	la	$t0,result	# escreve resultado na variavel result
	sw	$v0,0($t0)	

# Finalizacao do programa
	li 	$v0, 10		# system call for exit
	syscall			# Exit!

# Funcao fatorial
fact:	addiu 	$sp,$sp,-8	# Inicio da funcao fact. Aloca 8 bytes na pilha
	sw	$ra,0($sp)	# Salva o endereco de retorno na pilha
	sw	$a0,4($sp)	# Salva o numero cujo fatorial se quer calcular na pilha
	sltiu	$t0,$a0, 1	# $t0=1 se num<1
	beq	$t0,$zero,rec	# Se num>=1 ($t0=0), continua recursao
	addiu	$v0,$zero,1	# Se esta no fim da recursao retorne fact(1)=1
	lw	$ra, 0($sp)	# Recupera o endereco de retorno
	addiu	$sp,$sp,8	# esvazia a pilha
	jr	$ra		# retorna por aqui na folha da recursao.

# Parte recursiva da funcao fatorial
rec:	addiu	$a0 $a0,-1	# Se nao esta na folha da recursao, decrementa n
	jal	fact		# chama fact(num-1), recursivamente
	lw	$a0,4($sp)	# Na volta da recursao, recupera num
	lw	$ra,0($sp)	# recupera endereco de retorno
	addiu	$sp,$sp,8	# restaura a pilha
	multu	$v0, $a0	# multiplica  fact(num-1) ($v0) por num ($a0)
				# lembrar que resultado da multiplicacao vai para
				# registradores hi e lo. Aqui, despreza-se parte alta
	mflo	$v0		# Assume-se que hi=0 e usa-se apena lo como resultado
				# Assim, $v0 e lo contem fact(num)
	jr	$ra		# Retorna ao programa que chamou
