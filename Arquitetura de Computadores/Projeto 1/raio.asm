.data
	pi: 	.float 3.14159
	r:	.float
	raio:	.float
	msg1:	.asciiz "Digite o valor do raio do circulo, e ENTER\n"
	msg2: 	.asciiz "Raio digitado e'         "
	msg3:	.asciiz "Area do circulo com raio "
	endl:	.asciiz "\n"
	e:	.asciiz " e' "
	
.text 
	li $v0, 4      # servico print string
  	la $a0, msg1   # string a ser impressa em $a0
  	syscall
  	
  	li $v0, 6      	# servico read float, retorno em $f0
  	syscall
  	movf.s $f1, $f0	# $f1 contem raio
  	
  	li $v0, 4      # servico print string
  	la $a0, msg2   # string a ser impressa em $a0
  	syscall
  	
  	li $v0, 2	# servico print float
  	mov.s $f12, $f1 #move o float para registrador responsavel pela exibicao
  	syscall
  	
  	li $v0, 4      # servico print string
  	la $a0, endl   # string a ser impressa em $a0
  	syscall
  	
  	li $v0, 4      # servico print string
  	la $a0, msg3   # string a ser impressa em $a0
  	syscall
  	
  	li $v0, 2	# servico print float
  	mov.s $f12, $f1 #move o float para registrador responsavel pela exibicao
  	syscall
  	
  	li $v0, 4       # servico print string
  	la $a0, e   	# string a ser impressa em $a0
  	syscall
  	
  	jal area
  	
  	li $v0, 2	# servico print float
  	mov.s $f12, $f3 #move o float para registrador responsavel pela exibicao
  	syscall
  	
  	li $v0, 4       # servico print string
  	la $a0, endl   	# string a ser impressa em $a0
  	syscall
  	
  	li $v0, 10
  	syscall
  	
  	area:
  	mul.s $f3, $f1, $f1
  	l.s $f2, pi
  	mul.s $f3, $f3, $f2
  	jr $ra
