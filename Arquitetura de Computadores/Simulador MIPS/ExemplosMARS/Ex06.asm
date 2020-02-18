# UFBA - MATA48 - 2019.1
# Exemplo do uso de chamadas de sistema
# Escreve strings na tela e conta regressivamente de 100 a 0

.data
valor:  .word   100
space:  .asciiz " "
nl:     .asciiz "\n"
tb:     .asciiz "\t"
msg1:   .asciiz "Hello, World\n"
msg2:   .asciiz "Meu nome é XXXXXXXXX\n"
msg3:   .asciiz "\nMeu nome ainda é XXXXXXXXX !\n"

.text
.globl  main

main:   la      $a0, msg1	# carrega em $a0 a string a ser impressa (msg1)
        li      $v0, 4  	# carrega em $v0 o número do serviço (4 para "print string")
        syscall			# chamada ao sistema
        
        la      $a0, msg2       # carrega em $a0 a string a ser impressa (msg2)
        li      $v0, 4  	# carrega em $v0 o número do serviço (4 para "print string")
        syscall			# chamada ao sistema
        
        # Preparacao para o laco de contagem de 100 ate 0
        
        lw      $a0, valor	# carrega em $a0 o valor inicial (100)
        la      $a1, space      # carrega em $a1 o caractere de espaço em branco
        
Loop:   beq     $zero, $a0, Exit # laço: se valor ($a0) igual a 0, encerra o laço (salta para Exit)
        add     $a0, $a0, -1	 # decrementa o valor
        li      $v0, 1           # carrega em $v0 o número do serviço (1 para "print integer")
        syscall
        move    $t0,  $a0	 # move o valor de $a0 para um registrador temporário $t0
        move    $a0,  $a1	 # carrega em $a0 o caractere em branco
        li      $v0,  4		 # carrega em $v0 o número do serviço (4 para "print string")
        syscall
        move    $a0,  $t0	 # restaura o valor de $a0 a partir do registrador temporário $t0
        j       Loop		 # volta para Loop

Exit:   la      $a0,  msg3       # carrega em $a0 a string a ser impressa (msg3)
        li      $v0,  4          # carrega em $v0 o número do serviço (4 para "print string")
        syscall                  # chamada ao sistema

## Finalização do programa
        li      $v0,  10         # carrega em $v0 o número do serviço (10 para "exit")
        syscall
