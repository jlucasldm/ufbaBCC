# UFBA - MATA48 - 2019.1
# Descobre e imprime o menor de 2 números
# Usuario deve digitar os 2 numeros, separados por um ENTER

.data
  num1 : .word 0
  num2 : .word 0
  msg  : .asciiz "Digite um numero: "
  msg2 : .asciiz "Digite outro numero: "
  msg3 : .asciiz "O menor numero eh: "
  
.text
  la $s0, num1		# carrega em $s0 o endereço da variável num1
  la $s1, num2		# carrega em $s0 o endereço da variável num1

  la $a0, msg		# carrega em $a0 o endereço da mensagem a ser impressa
  li $v0, 4		# serviço 4 - print string
  syscall
    
  li $v0,5		# serviço 5 - read integer
  syscall		# chama o sistema para ler do teclado. Valor lido é colocado em $v0
  move $s0, $v0		# copia o primeiro valor lido para $s0

  la $a0, msg2		# carrega em $a0 o endereço da mensagem a ser impressa
  li $v0, 4		# serviço 4 - print string
  syscall
  
  li $v0,5		# serviço 5 - read integer	
  syscall		# chama o sistema para ler do teclado. Valor lido é colocado em $v0
  move $s1, $v0		# copia o segundo valor lido para $s0

  la $a0, msg3		# carrega em $a0 o endereço da mensagem a ser impressa
  li $v0, 4		# serviço 4 - print string
  syscall
  
  slt $t0, $s0, $s1	# compara se num1 ($s0) é menor do que num2 ($s1). Se for, $t0 será igual a 0.
  bne $t0, $zero, Menor	# se num1 < num2, salta para Menor.
  li $v0, 1		# senão imprime o num2 como sendo o menor. Serviço 1 (print integer)
  la $a0, 0($s1)	# $a0 recebe o num2 a ser impresso
  syscall
  j Exit		# salta para Exit para encerrar o programa
 
Menor: 			# se num1 for menor, imprime.
  li $v0, 1		# serviço 1 (print integer)
  la $a0, 0($s0)	# $a0 recebe o num1 a ser impresso
  syscall
 
# Finalização do programa
Exit:
    li $v0, 10
    syscall
  
