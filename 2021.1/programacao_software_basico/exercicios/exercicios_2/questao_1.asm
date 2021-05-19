;João Lucas Lima de Melo

%include "io.inc"

section .data
msg1 db 'Hello World'
msg2 db 'AB'    

section .text
global CMAIN
CMAIN:
    mov ebp, esp; for correct debugging
    
    xor esi, esi    ;fonte
    xor edi, edi    ;destino
    
    mov esi, msg2
    mov edi, msg1
    
    cld             ;zera o Direction Flag DF
    
    movsb           ;msg1 = "Aello World"
    
    ret