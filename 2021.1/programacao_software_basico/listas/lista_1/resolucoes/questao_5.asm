;João Lucas Lima de Melo

%include "io.inc"

section .text
global CMAIN
CMAIN:
    mov ebp, esp; for correct debugging
    
    xor eax, eax
    xor ebx, ebx
    
    mov eax, 6          ;eax = 6
    
    cmp eax, 5          ;compara 6 e 5
    jge maioriIgual     ;se eax = 6 >= 5, pula para "maiorIgual"
    mov ebx, 2          ;ebx = 2 (condicao para else)
    jmp end
    
    maioriIgual:
    mov ebx, 1          ;ebx = 1
    
    end:
    ret