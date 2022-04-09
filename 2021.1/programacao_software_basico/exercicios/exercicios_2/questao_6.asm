;João Lucas Lima de Melo

%include "io.inc"

section .bss
array2: resd 10

section .data
array1: dd 1,2,3,4,5,6,7,8,9,10

section .text
global CMAIN
CMAIN:
    mov ebp, esp; for correct debugging
    
    xor esi, esi    ;source
    xor edi, edi    ;destiny
    xor ecx, ecx   
    
    cld             ;zera o Direction Flag (DF)
    
    mov esi, array1 ;esi = array1
    mov edi, array2 ;edi = array2
    mov ecx, 10
    
    laco:
    lodsd
    stosd           ;armazena eax na string destino
    loop laco
    
    ret