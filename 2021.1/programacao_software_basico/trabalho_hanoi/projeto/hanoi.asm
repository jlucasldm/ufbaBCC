SECTION .data
n_discos db 4

SECTION .text
extern printf
global  _start
 
; Pseudocódigo da resolução da torre de hanói por recursão

; X - número de discos
; S - coluna de sáida
; D - coluna de destino
; T - coluna temporária

;   hanoi(X, S, D, T):
;		IF X == 1, THEN:
;    		print move X from S to D
;    		return
;		ELSE:
;    		hanoi(X - 1, S, T, D)   
;    		print move X from S to D 
;    		hanoi(X - 1, T, D, S) 
;    		return



_start:  
    xor al, al ; AL - armazena coluna de saída  (S)
    xor ah, ah ; AH - armazena coluna de destino (D)
    xor bl, bl ; BL - armazena coluna temporária (T)
    xor bh, bh ; BH - armazena número de discos (X)

    ; Inicializando os registradores com os valores iniciais
    ; Colunas: S = 1, T = 2, D = 3
    mov bh, [n_discos]
    mov al, 1 ; S
    mov bl, 2 ; T
    mov ah, 3 ; D
    

    ; Executando a função recursiva
    push ax
    push bx
    call _print_inicio
    pop bx
    pop ax
    call _hanoi    
    call _print_final
    call _quit
    


_hanoi: ; hanoi(X, S, D, T) = hanoi(bh, al, ah, bl)
    cmp bh, 1 ; Compara o número de discos para verificar se há apenas um disco.
    je _if

    ;----------------------hanoi(X - 1, S, T, D) -----------------
    
    ; Salvando contexto AL, AH, BL e BH
    push ax
    push bx
    
    ; Preparando parâmetros hanoi(X - 1, S, T, D) 
    dec bh      ; bh = X - 1
    xchg ah, bl ; swap T e D
    
    call _hanoi ; hanoi(X - 1, S, T, D) 
    
    ; Retomando contexto AL, AH, BL e BH
    pop bx
    pop ax

    ;--------------------print move X from S to D ----------------
    push ax
    push bx
    movzx ecx, ah; coluna de destino
    movzx edx, al ; coluna de saída
    movzx edi, bh ; tamanho do disco
    call _print_mover ; Printa o movimento do disco
    pop bx
    pop ax
    
    ;----------------------hanoi(X - 1, T, D, S) -----------------
    ; Salvando contexto AL, AH, BL e BH
    push ax
    push bx
    
    ; Preparando parâmetros hanoi(X - 1, T, D, S)
    dec bh      ; bh = X - 1
    xchg al, bl ; swap T e S
    
    call _hanoi ; hanoi(X - 1, T, D, S) 
    
    ; Retomando contexto AL, AH, BL e BH
    pop bx
    pop ax
    ;--------------------------------------------------------------    

    jmp _ret
_if: ; Se número de discos é igual a 1. 
    ;--------------------print move X from S to D ----------------
    push ax
    push bx
    movzx ecx, ah; coluna de destino
    movzx edx, al ; coluna de saída
    movzx edi, bh ; tamanho do disco
    pop bx
    pop ax
    call _print_mover ; Printa o movimento do disco
_ret:
    ret


_print_inicio:
    push string_inicio  ;inserindo à pilha a string a ser impressa
    call printf         ;itera sobre o topo da pilha e imprime a string
    add esp, 4          ;move o ponteiro 4 bytes para apontar ao valor anterior da pilha
    ret

string_inicio:
    db "Torre de Hanoi com três discos", 0xa, 0 ; 0xa = newline, 0 = end of a C string.

_print_mover:
    add ecx, 64
    add edx, 64
    push ecx
    push edx
    push edi
    push string_mover  ;inserindo à pilha a string a ser impressa
    call printf        ;itera sobre o topo da pilha e imprime a string
    add esp, 16        ;move o ponteiro 4 * 4 bytes para apontar ao valor anterior da pilha 
    ret

string_mover:
    db "Movendo o disco %d da torre %c para a torre %c.",0xa,0 ; 0xa = newline, 0 = end of a C string.

_print_final:
    push string_final  ;inserindo à pilha a string a ser impressa
    call printf         ;itera sobre o topo da pilha e imprime a string
    add esp, 4          ;move o ponteiro 4 bytes para apontar ao valor anterior da pilha
    ret

string_final:
    db "Procedimento solucionado.", 0xa, 0 ; 0xa = newline, 0 = end of a C string.


_quit:
    mov       eax, 1                
    mov       ebx, 2                
    syscall 