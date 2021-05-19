;João Lucas Lima de Melo

%include "io.inc"

section .data
Rval: resd 0
Xval: dd 5
Yval: dd 10
Zval: dd 15

section .text
global CMAIN
CMAIN:
    mov ebp, esp; for correct debugging
    
    xor eax, eax
    xor ebx, ebx
    
    mov eax, [Yval] ;eax = Yval
    mov ebx, [Zval] ;eax = Zval
    
    neg eax         ;-Yval
    add eax, ebx    ;eax = -Yval + Zval
    
    mov ebx, eax
    mov eax, [Xval] ;eax = Xval
    sub eax, ebx
    
    mov [Rval], eax
    
    ret