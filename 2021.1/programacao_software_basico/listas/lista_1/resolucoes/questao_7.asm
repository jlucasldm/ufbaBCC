;João Lucas Lima de Melo

%include "io.inc"

section .text
global CMAIN
CMAIN:
    mov ebp, esp; for correct debugging
    
    xor eax, eax
    xor ebx, ebx
    xor ecx, ecx
    xor edx, edx
    
    mov eax, 15     ;eax = 15
    mov ecx, 13     ;ecx = 10
    mov ebx, 10      ;ebx = 5
    
    laco:
    sub eax, 1      ;eax--
    cmp eax, ecx
    je cond1        ;eax = ecx
    mov edx, 20     ;"else" => edx = 20
    
    condicao:
    cmp eax, ebx
    jg laco         ;eax > ebx, entao volta ao laco
    jmp end
    
    cond1:
    mov edx, 10
    jmp condicao
    
    end:
    ret