;João Lucas Lima de Melo

%include "io.inc"

section .data
block1: dd 'string1'
block2: dd 'string2'
size:   dd 6 

section .text
global CMAIN
CMAIN:
    mov ebp, esp; for correct debugging
    
    xor esi, esi    ;source
    xor edi, edi    ;destiny
    xor ecx, ecx
    
    xor eax, eax    ;teste controle
    
    cld             ;zera o Direction Flag (DF)
    
    mov esi, block1 ;endereço do primeiro bloco
    mov edi, block2 ;endereço do segundo bloco
    mov ecx, [size] ;tamanho dos blocos em bytes
    
    repe cmpsb      ;repetir enquanto a flag Z está definida
    je equal        ;se Z está definida, pula para equal
    mov eax, 1     ;caso os blocos forem diferentes
    jmp end
    
    equal:
    mov eax, 2      ;caso os blocos sejam iguais
    
    end:
    ret