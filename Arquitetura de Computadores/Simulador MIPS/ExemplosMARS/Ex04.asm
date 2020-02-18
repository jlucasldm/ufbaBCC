# UFBA - MATA48 - 2019.1
# Implementa calculo de media aritmetica de tres notas

.data
   n1: .float
   n2: .float
   n3: .float
   resultado: .float
   divisor: .float 3.0		# divisor da media
   nota: .float 7.0		# comparador da media
   msg1: .asciiz "Informe a primeira nota: "
   msg2: .asciiz "Informe a segunda nota: "
   msg3: .asciiz "Informe a terceira nota: "
   msg4: .asciiz "Media: "
   msg5: .asciiz " - Aluno aprovado! Parabens!\n"
   msg6: .asciiz " - Aluno reprovado! Estude mais!\n"

.text

  li $v0, 4      # servico print string
  la $a0, msg1   # string a ser impressa em $a0
  syscall

  li $v0, 6      # servico read float, retorno em $f0
  syscall
  movf.s $f1, $f0	# $f1 contem n1

  li $v0, 4      # servico print string
  la $a0, msg2   # string a ser impressa em $a0
  syscall

  li $v0, 6      # read float, retorno em $f0
  syscall
  movf.s $f2, $f0	# $f2 contem n2

  li $v0, 4      # servico print string
  la $a0, msg3   # string a ser impressa em $a0
  syscall

  li $v0, 6      # read float, retorno em $f0
  syscall
  movf.s $f3, $f0	# $f3 contem n3

  # resultado = (n1 + n2 + n3) / 3;

  add.s $f4, $f1, $f2   # $f1 - n1; $f2 - n2
  add.s $f5, $f4, $f3   # $f3 - n3
  lwc1  $f7, divisor    # $f7 mapeia o divisor
  div.s $f12, $f5, $f7  # $f5 - somatorio das notas

  # comando IF - THEN - ELSE
  # if (resultado >= 7.0)

  lwc1 $f6, nota     # mapeia variavel nota para $f6

  c.lt.s 4 $f6, $f12  # if 7.0 < resultado, flag=4
  bc1t 4 ELSE         # if flag=4, pula para THEN

  # implementar bloco then
  # tarefa de casa

  # IMPORTANTE: pula por cima do THEN
  j SAIDA

ELSE:
  li $v0, 4   # servico print string
  la $a0, msg4  # imprime "Media"
  syscall
  li $v0, 2  # print float, argumento em $f12
  syscall
  li $v0, 4   # servico print string
  la $a0, msg6  # imprime "Aluno reprovado"
  syscall

SAIDA:
  li $v0, 10   # servico Exit
  syscall
