;João Lucas Lima de Melo

%include "io.inc"

section .data
Result: RESW 0
Bla: DW  5
Bli: DW  10
Ble: DW  15

section .text
global CMAIN
CMAIN:
    mov ebp, esp; for correct debugging
    
    xor eax, eax
    xor ebx, ebx
    
    mov eax, [Bli]      ;eax = Bli
    mov ebx, [Ble]      ;ebx = Ble
    
    add ebx, eax        ;ebx = ebx + eax
    neg ebx             ;ebx = -ebx
    
    mov eax, [Bla]      ;eax = Bla
    sub eax, ebx        ;eax = Bla - (-(Ble + Bli))
    
    mov [Result], eax   ;Result = eax
    
    ret