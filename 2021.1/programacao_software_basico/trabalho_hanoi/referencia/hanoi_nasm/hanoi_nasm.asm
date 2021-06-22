;; bits 64
default rel

extern printf, scanf

section .text
    global main
    global hanoi
main:
    sub     rsp, 56
    lea     rcx, [prompt]
    call    printf
    lea     rdx, [rsp+32]
    lea     rcx, [scan_fmt]
    call    scanf
    cmp     eax, 1
    jz      .call_hanoi
    lea     rcx, [scan_fail]
    call    printf
    mov     eax, 1                      ; return 1
.end:
    add     rsp, 56
    ret
.call_hanoi:
    mov     ecx, dword [rsp+32]         ; ecx = num_disks
    mov     r9d, 3                      ; r9d = tmp
    mov     r8d, 2                      ; r8d = dst
    mov     edx, 1                      ; edx = src
    call    hanoi                       ; hanoi(num_disks, src, dst, tmp)
    xor     eax, eax                    ; return 0
    jmp     .end
hanoi:
    push    r12
    mov     r12d, r8d                   ; r12d = r8d = dst
    push    rbp
    push    rdi
    push    rsi
    mov     esi, edx                    ; esi = edx = src
    push    rbx
    sub     rsp, 40
    cmp     ecx, 1                      ; if num_disks == 1
    jz      .skip_recursive_move
    mov     ebx, ecx
    mov     edi, r9d                    ; edi = r9d = tmp
.move_disk:
    lea     ebp, [rbx-1H]               ; ebp = num_disks - 1
    mov     r9d, r12d                   ; r9d = r12d = dst
    mov     r8d, edi                    ; r8d = edi = tmp
    mov     edx, esi                    ; edx = esi = src
    mov     ecx, ebp                    ; ecx = edp = num_disks - 1
    call    hanoi                       ; tmp & dst are swapped for this call
    mov     edx, ebx                    ; edx = ebx = num_disks
    mov     r9d, r12d                   ; update r9d after hanoi call
    mov     r8d, esi                    ; update r8d after hanoi call
    lea     rcx, [prompt_move_disk]
    mov     ebx, ebp                    ; ebx = ebp = num_disks - 1
    call    printf
    cmp     ebp, 1                      ; if num_disks == 1
    jz      .move_one_disk
    mov     eax, esi
    mov     esi, edi
    mov     edi, eax                    ; swaps tmp and src (esi and edi)
    jmp     .move_disk
.skip_recursive_move:
    mov     edi, edx                    ; edi = edx = src
.move_one_disk:
    add     rsp, 40
    mov     r8d, r12d
    mov     edx, edi
    pop     rbx
    lea     rcx, [prompt_move_one_disk]
    pop     rsi
    pop     rdi
    pop     rbp
    pop     r12
    jmp     printf

%macro str 2
    %2: db %1, 0
%endmacro

section .rdata
    str "How many disks do you want to play with? ", prompt
    str "%u", scan_fmt
    str {"Uh-oh, I couldn't understand that...  No towers of Hanoi for you!", 10}, scan_fail
    str {"Move disk 1 from %d to %d", 10}, prompt_move_one_disk
    str {"Move disk %d from %d to %d", 10}, prompt_move_disk