# UFBA - MATA48 - 2019.1
# Calcula a série de Fibonacci a partir de um valor lido do teclado.
# Os números são colocados num vetor e depois são impressos.

.data
fibs:	 .word   0 : 19     # vetor de words com 20 posições
tamanho: .word  19          # tamanho do vetor
msg:  	 .asciiz "Quantos números de Fibonacci devem ser gerados (2 <= x <= 19)? "
.text
      la   $s0, fibs        # carrega endereço do vetor em $s0
      la   $s5, tamanho     # carrega endereço da variável de tamanho em $s5
      lw   $s5, 0($s5)      # carrega tamanho do vetor em $s5

# Bloco para ler um valor inteiro do teclado => quantidade de números a serem gerados
pr:   la   $a0, msg      # carrega mensagem em $a0
      li   $v0, 4        # serviço 4 (print string)
      syscall
      li   $v0, 5	 # serviço 5 (read integer)
      syscall            # chama o sistema. O valor lido é colocado em $v0.
      bgt  $v0, $s5, pr     # verifica se valor lido é maior que 19 -- se for, retorna para pr
      ble  $v0, $zero, pr   # verifica se valor lido é menor ou igual a 0 -- se for, retorna para pr
      add  $s5, $v0, $zero  # carrega valor lido em $s5

      li   $s2, 1           # 1 é o valor do primeiro e do segundo termo da série de Fibonacci
      sw   $s2, 0($s0)      # F[0] = 1
      sw   $s2, 4($s0)      # F[1] = F[0] = 1
      addi $s1, $s5, -2     # contador do laço. Executa (tamanho-2) vezes

# Laço para calcular a série de Fibonacci a partir dos dois primeiros valores (F[0] e F[1])
loop: lw   $s3, 0($s0)      # lê valor de F[n-2]
      lw   $s4, 4($s0)      # lê valor de F[n-1]
      add  $s2, $s3, $s4    # F[n] = F[n-1] + F[n-2]
      sw   $s2, 8($s0)      # armazena o valor calculado F[n] no vetor
      addi $s0, $s0, 4      # incrementa o endereço para o próximo número da série
      addi $s1, $s1, -1     # decrementa o contador do laço
      bgtz $s1, loop        # salta para loop

# Imprime os números de Fibonacci armazenados no vetor. Usa a função print.
      la   $a0, fibs        # primeiro argumento para a função print (vetor fibs)
      add  $a1, $zero, $s5  # primeiro argumento para a função print  (tamanho)
      jal  print            # chama a rotina print

# Finalização do programa
      li   $v0, 10          # serviço 10 (exit)
      syscall               # Exit!

###############################################################
# Subroutina para imprimir os valores
.data
space:	.asciiz  " "          # espaço entre números
head: 	.asciiz  "Os números de Fibonacci são:\n"

.text
print:	add  $t0, $zero, $a0  # endereço inicial do vetor de números a serem impressos
      	add  $t1, $zero, $a1  # inicializa o contador do laço com o tamanho do vetor
      	la   $a0, head        # mensagem a ser impressa
     	li   $v0, 4           # serviço 4 (print string)
      	syscall

out:  lw   $a0, 0($t0)      # carrega o valor (número da série de Fibonacci) a ser impresso
      li   $v0, 1           # serviço print integer
      syscall
      la   $a0, space       # carrega caractere de espaço
      li   $v0, 4           # serviço print string
      syscall
      addi $t0, $t0, 4      # incrementa o endereço para o próximo número a ser impresso
      addi $t1, $t1, -1     # decrementa contador de laço
      bgtz $t1, out         # salta para out
      jr   $ra              # quando imprimir todos os números, retorna da subrotina para o programa principal
###############################################################
