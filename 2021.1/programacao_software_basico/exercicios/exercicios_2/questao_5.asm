;João Lucas Lima de Melo
%include "io.inc"

section .bss
array: resd 100

section .text
global CMAIN
CMAIN:
    mov ebp, esp; for correct debugging
    
    xor edi, edi    ;destiny
    xor eax, eax
    xor ebx, ebx
    xor ecx, ecx
    
    cld
    
    mov edi, array  ;ponteiro para começo do vetor
    mov ecx, 100    ;numero de elementos
    mov eax, 12     ;numero para buscar
    
    search:
    scasd           ;scan destination string (double word)
    je found
    loop search
    mov ebx, 1      ;caso não seja encontrado
    jmp fim
    
    found:
    sub edi, 4      ;edi agora aponta para 12 no array
    mov ebx, 2
    
    fim:
    ret