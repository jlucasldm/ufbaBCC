;João Lucas Lima de Melo

%include "io.inc"

section .data
array1: dd 1,2,3,4,5
array2: dd 6,7,8,9,10

section .text
global CMAIN
CMAIN:
    mov ebp, esp; for correct debugging
    
    xor esi, esi    ;source
    xor edi, edi    ;destiny
    xor ecx, ecx
    
    mov esi, array1 ;esi = array1
    mov edi, array2 ;edi = array2
    mov ecx, 5      ;ecx = 5
    
    rep movsd       ;array2 = 1,2,3,4,5
    
    ret