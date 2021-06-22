%include "io.inc"

section .text
global CMAIN
CMAIN:
    mov ebp, esp; for correct debugging
    ;write your code here
    xor eax, eax
    xor ebx, ebx
    xor ecx, ecx
    xor edx, edx
    
    mov ecx, 3      ;numero de discos
    mov eax, 'A'    ;fonte
    mov ebx, 'B'    ;auxiliar
    mov edx, 'C'    ;destino
    jmp hanoi
    
    hanoi:
    cmp ecx, 1;
    je print
    
    print:
    ret