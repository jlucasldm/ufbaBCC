# UFBA - MATA48 - 2019.1
###############################################################################################
# Exemplo de programa em linguagem de montagem do MIPS : Manipulando vetores
# Autor: Ney Calazans
# Funcao: Este programa soma o valor de uma constante (const) a cada elemento do vetor array
###############################################################################################

.data                           # Diretiva para o montador - adiciona o que vem abaixo
        			# a memoria de dados do processador
array:  .word   0x12 0xff 0x3 0x14 0x878 0x31  0x62 0x10 0x5 0x16 0x20 # o vetor
                                # A diretiva .word carrega a lista de inteiros em posicoes successivas
                                # da memoria de dados
size:   .word   11              # Variavel que armazena o tamanho do vetor
const:  .word   0x100           # Constante a somar a cada elemento do vetor                
                                
        .text                   # Diretiva para o montador - adiciona o que vem abaixo
        			# a memoria de programa do processador
        .globl  main            # Declare o rotulo main Como sendo global
        			# e o ponto a partir de onde se inicia a execucao
main:
        la      $t0,array       # o registrador $t0 contem o endereco do vetor
        la      $t1,size        # obtem o endereco da posicao da memoria de dados onde se guarda
        			# o tamanho do vetor
        lw      $t1,0($t1)      # o registrador $t1 contem o tamanho do vetor
        la      $t2,const       # obtem o endereco da constante const
        lw      $t2,0($t2)      # o registrador $t2 contem a constante a somar
loop:   blez    $t1,end         # se o tamanho chega a 0, fim do processamento
        lw      $t3,0($t0)      # obtem um elemento do vetor
        addu    $t3,$t3,$t2     # soma a constante
        sw      $t3,0($t0)      # atualiza o vetor
        addiu   $t0,$t0,4       # atualiza o apontadoe do vetor
        			# lembrar que 1 palavra no MIPS ocupa 4 enderecos consecutivos de memoria
        addiu   $t1,$t1,-1      # decrementa o contador de tamanho do vetor
        j       loop            # continua a execucao
        
        # Agora volta para o programa monitor
end:    li	$v0,10		# prepara chamada do sistema para finalizar programa
	syscall			# fim do programa

