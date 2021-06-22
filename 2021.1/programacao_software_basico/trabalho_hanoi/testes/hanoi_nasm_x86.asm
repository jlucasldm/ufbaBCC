%include "io.inc"
default rel

extern printf, scanf

section .text
    global CMAIN
    global hanoi
CMAIN:
    mov rbp, rsp; for correct debugging
    ;sub     rsp, 56
    ;lea     rcx, [prompt]
    ;call    printf
    ;lea     rdx, [rsp+32]
    ;lea     rcx, [scan_fmt]
    ;call    scanf
    ;cmp     eax, 1
    ;jz      .call_hanoi
    ;lea     rcx, [scan_fail]
    ;call    printf
    mov     eax, 1                      ; return 1
.end:
    add     rsp, 56
    ret
.call_hanoi:
    ;mov     ecx, dword [rsp+32]         ; ecx = num_disks
    mov     ecx, 3;
    mov     r9, 3                      ; r9d = tmp
    mov     r8, 2                      ; r8d = dst
    mov     edx, 1                      ; edx = src
    call    hanoi                       ; hanoi(num_disks, src, dst, tmp)
    xor     eax, eax                    ; return 0
    jmp     .end
hanoi:
    cmp     ecx, 1                      ; if num_disks == 1
    je      .skip_recursive_move

    push    rbx
    push    rsi
    push    rdi
    push    r12

    mov     ebx, ecx                    ; ECX=2+
    mov     esi, edx                    ; esi = edx = src
    mov     edi, r9                    ; edi = r9d = tmp
    mov     r12, r8                   ; r12d = r8d = dst

.move_disk:
    mov     r9, r12                   ; dst
    mov     r8, edi                    ; tmp
    mov     edx, esi                    ; src
    ;lea     ecx, [rbx-1]              ; num_disks - 1
    mov     ecx, rbx
    sub     ecx, 1
    call    hanoi                       ; tmp & dst are swapped for this call

    mov     r9, r12                   ; the 'to' peg
    mov     r8, esi                    ; the 'from' peg
    mov     edx, ebx                    ; num_disks
    lea     rcx, [prompt_move_disk]
    sub     rsp, 32                     ;shadow space
    call    printf
    add     rsp, 32

    mov     eax, esi
    mov     esi, edi
    mov     edi, eax                    ; swaps tmp and src (esi and edi)

    dec     ebx                         ; num_disks - 1
    cmp     ebx, 1                      ; if num_disks == 1
    jne     .move_disk

    mov     r8, r12                   ; the 'to' peg
    mov     edx, esi                    ; the 'from' peg

    pop     r12
    pop     rdi
    pop     rsi
    pop     rbx

.skip_recursive_move:
    lea     rcx, [prompt_move_one_disk]
    sub     rsp, 32                     ;shadow space
    call    printf
    add     rsp, 32
    ret

%macro str 2
    %2: db %1, 0
%endmacro

section .rdata
    str "How many disks do you want to play with? ", prompt
    str "%u", scan_fmt
    str {"Uh-oh, I couldn't understand that...  No towers of Hanoi for you!", 10}, scan_fail
    str {"Move disk 1 from peg %d to peg %d", 10}, prompt_move_one_disk
    str {"Move disk %d from peg %d to peg %d", 10}, prompt_move_disk