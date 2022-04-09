;João Lucas Lima de Melo

%include "io.inc"

section .data
Result: resd 0
Bla: dd 5
Ble: dd 10
Bli: dd 15

section .text
global CMAIN
CMAIN:
    mov ebp, esp; for correct debugging

    xor eax, eax
    xor ebx, ebx
    
    mov eax, [Bla]  ;eax = Bla
    mov ebx, [Ble]  ;eax = Ble
    
    sub eax, ebx    ;eax = Bla - Ble
    push eax        ;"armazena" valor
    
    mov eax, [Bli]  ;eax = Bli
    mov ebx, [Bla]  ;ebx = Bla
    add eax, ebx    ;eax = Bli + Bla
    
    pop ebx         ;"recupera" valor em ebx
    add eax, ebx    ;eax = Bli + Bla + Bla - Ble
    
    mov [Result], eax
    
    ret