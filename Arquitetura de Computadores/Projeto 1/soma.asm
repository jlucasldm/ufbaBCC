.data
	x: 	.float
	y: 	.float
	res: 	.float
	const: 	.float 6.5
	prod:	.float 1.34
	msg1:	.asciiz "Informe o primeiro numero: "
	msg2:	.asciiz "Informe o segundo numero: "
	msg3:	.asciiz "Soma: "
	msg4:	.asciiz "Resultado descartado!\n"
	msg5: 	.asciiz "\n"
	
.text
	li $v0, 4      # servico print string
  	la $a0, msg1   # string a ser impressa em $a0
  	syscall
  	
  	li $v0, 6      	# servico read float, retorno em $f0
  	syscall
  	movf.s $f1, $f0	# $f1 contem x
  	
  	li $v0, 4      # servico print string
  	la $a0, msg2   # string a ser impressa em $a0
  	syscall
  	
  	li $v0, 6      	# read float, retorno em $f0
  	syscall
  	movf.s $f2, $f0	# $f2 contem y
  	
  	jal soma
  	
  	l.s $f6, const
  	c.lt.s $f3, $f6	#avalia desigualdade entre valores de registradores
  	bc1t else
  	
  	li $v0, 4      # servico print string
  	la $a0, msg3   # string a ser impressa em $a0
  	syscall
  	
  	li $v0, 2	# servico print float
  	mov.s $f12, $f3	#move o float para registrador responsavel pela exibicao
  	syscall
  	
  	li $v0, 4      # servico print string
  	la $a0, msg5   # string a ser impressa em $a0
  	syscall
  	
  	
  	li $v0, 10
  	syscall
  	
  	soma:
  	add.s $f3, $f2, $f1 #joga em $f3 o resultado de x+y
  	l.s $f4, prod       #$f4 recebe o valor de prod
  	mul.s $f3, $f3, $f4 #$f3 recebe o valor de (x+y)*prod
  	jr $ra 		    #volta para o lugar em que foi chamado
  	
  	else:
  	li $v0, 4      # servico print string
  	la $a0, msg4   # string a ser impressa em $a0
  	syscall
  	
  	li $v0, 10
  	syscall 
