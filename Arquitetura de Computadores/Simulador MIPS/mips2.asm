.data

    const: .float 1.34

    ZERO: .float 0.0

    comp: .float 6.5

    res: .float

    

    msg1_firstnumber: .asciiz "Informe o primeiro numero: "

    msg2_secondnumber: .asciiz "Informe o segundo numero: "

    msg3_soma: .asciiz "Soma: "

    msg4_descartado: .asciiz "Resultado descartado!\n"

    msg5_pulalinha: .asciiz "\n"



.text

    l.s $f1, const

    l.s $f11, ZERO

    l.s $f10, comp



    li $v0, 4

    la $a0, msg1_firstnumber

    syscall



    li $v0, 6

    syscall

    movf.s $f2, $f0



    li $v0, 4

    la $a0, msg2_secondnumber

    syscall



    li $v0, 6

    syscall

    movf.s $f3, $f0



    jal SOMA

    add.s $f5, $f4, $f11



    c.lt.s $f5, $f10

    bc1t ELSE



    li $v0, 4

    la $a0, msg3_soma

    syscall



    li $v0, 2

    add.s $f12, $f5, $f11

    syscall



    li $v0, 10

    syscall



SOMA:

    add.s $f4, $f2, $f3

    mul.s $f4, $f4, $f1

    jr $ra



ELSE:

    li $v0, 4

    la $a0, msg4_descartado

    syscall



    li $v0, 10

    syscall