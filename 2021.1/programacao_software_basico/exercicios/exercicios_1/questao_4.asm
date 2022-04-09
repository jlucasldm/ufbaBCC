;João Lucas Lima de Melo

%include "io.inc"

section .text
global CMAIN
CMAIN:
    ;if (EAX == 0)
    ;   EBX = 1
    ;ELSE
    ;   EBX = 2
    
    mov ebp, esp; for correct debugging
    
    xor eax, eax
    xor ebx, ebx
    
    mov eax, 0
    
    cmp eax, 0
    je cond1    ;jump (to cond1) equal
    jne cond2   ;jump (to cond2) not equal

    cond1:
    mov ebx, 1
    jmp end
    
    cond2:
    mov ebx, 2
    jmp end
    
    end:
    ret