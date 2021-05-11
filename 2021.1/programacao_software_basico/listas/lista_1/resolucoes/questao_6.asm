;João Lucas Lima de Melo

%include "io.inc"

section .text
global CMAIN
CMAIN:
    mov ebp, esp; for correct debugging
    
    xor eax, eax
    xor ebx, ebx
    
    mov eax, 0      ;eax = 0
    mov ebx, 10     ;ebx = 10
    
    cmp eax, ebx
    jge cond1       ;para eax >= ebx
    
    cmp eax, 0
    jz cond2        ;para eax == 0
    jmp end
    
    cond1:
    mov eax, 1      ;eax = 1
    jmp end
    
    cond2:
    mov eax, -1     ;eax = -1
    jmp end
    
    end:
    ret