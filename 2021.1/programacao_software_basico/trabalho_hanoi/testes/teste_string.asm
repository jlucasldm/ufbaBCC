%include "io.inc"

section .text
global CMAIN
CMAIN:
    mov ebp, esp; for correct debugging
    ;write your code here
    xor eax, eax
    
    ;Assembly equivalent of C: printf("The integers are %d %d\n",10 17);
    push 17 ; integer to print
    push 10
    push myPrintString ; string to print it with
    extern printf
    call printf
    pop eax
    pop ebx
    pop ecx
    ret

myPrintString:
       db "The integers are %d %d",0xa,0 ; 0xa = newline, 0 = end of a C string.