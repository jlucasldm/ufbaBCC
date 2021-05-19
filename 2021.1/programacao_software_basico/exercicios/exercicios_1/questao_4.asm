;João Lucas Lima de Melo

%include "io.inc"

section .text
global CMAIN
CMAIN:
    mov ebp, esp; for correct debugging
    
    xor eax, eax
    xor ebx, ebx
    mov eax, 2
    
    cmp eax, 0
    je cond1
    jne cond2

    cond1:
    mov ebx, 1
    jmp end
    
    cond2:
    mov ebx, 2
    jmp end
    
    end:
    ret