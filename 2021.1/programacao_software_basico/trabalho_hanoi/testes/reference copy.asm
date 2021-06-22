%include "io.inc"

section .data
  space: .ascii " "
  newline: .ascii "\n"

section .text

global CMAIN
CMAIN:
    mov ebp, esp; for correct debugging
    ;write your code here
    xor eax, eax
    
    ;  zero the memory in a tower
    init_tower:
    xor rax, rax                ; zero %rax
    mov ecx, $64
    rep stosb
    ret

    ;;;  peek the top of the tower
    peek_tower:
    mov %ecx, (%rdi)
    cmp %ecx, $0
    jz .peek_empty
    dec %ecx
    movq 4(%rdi, %rcx, 4), %rax
    ret
    .peek_empty:
    mov %eax, $100000
    ret

    ;;; like peek tower, but remove the value
    pop_tower:
    mov %ebx, (%rdi)
    dec %ebx
    mov %eax, 4(%rdi, %rbx, 4)    ; copy the value to %rax
    mov 4(%rdi, %rbx, 4), $0,     ; zero the value
    mov %ebx, (%rdi)              ; decrease count
    ret

    ;;; the tower in %rdi, the val in %rsi
    push_tower:
    mov %ecx, (%rdi)
    mov %rsi, 4(%rdi, %rcx, 4)
    inc %ecx
    mov %ecx, (%rdi)
    ret

    print_one:
    mov %rdi, %rsi
    mov %eax, $1                 ; SYS_write
    mov %edi, %eax               ; fd = 1
    mov %edx, %eax               ; n = 1
    syscall
    ret

    print_space:
    push %rcx                     ; save %rcx thru syscall
    call print_one
    mov $space, %rdi
    call print_one
    pop %rcx
    ret

    print_newline:
    mov $newline, %rdi
    call print_one
    ret

    print_tower:
    mov %ecx, (%rdi)             ; prepare to loop
    cmp %ecx, $0
    jz .finish_print_tower
    add $4, %rdi                  ; point %rdi to data array
    sub $8, %rsp                  ; allocate stack space
    .print_tower_loop:
    mov %eax, (%rdi)             ; copy int to %rax
    add %eax, $'0'               ; turn %rax into ascii
    mov %rax, (%rsp)              ; copy the int to the stack
    mov %rdi, %rbx                ; save rdi to rbx
    mov %rsp, %rdi                ; copy our into location to %rdi
    call print_space
    add $4, %rbx
    mov %rbx, %rdi
    loop .print_tower_loop
    add $8, %rsp                  ; deallocate stack space
    .finish_print_tower:
    call print_newline
    ret

    print_all:
    mov (%rbp), %rax
    and %eax, $1
    jz print_even
    lea -64(%rbp), %rdi
    call print_tower
    lea -128(%rbp), %rdi
    call print_tower
    lea -192(%rbp), %rdi
    call print_tower
    call print_newline
    ret
    print_even:
    lea -64(%rbp), %rdi
    call print_tower
    lea -196(%rbp), %rdi
    call print_tower
    lea -128(%rbp), %rdi
    call print_tower
    call print_newline
    ret

    ;;; rdi and rsi should be towers to move between
    move_tower:
    ;; compare the top rings in the two towers
    mov %rdi, %r9
    call peek_tower
    mov %rax, %r10
    mov %rsi, %rdi
    call peek_tower
    mov %r9, %rdi
    cmp %rax, %r10
    jl .less_branch
    .greater_branch:
    ;; swap rdi and rsi
    mov %rdi, %rax
    mov %rsi, %rdi
      mov %rax, %rsi
    .less_branch:
      ;; source is rdi, dest is rsi
      call pop_tower
      push %rdi
      push %rsi
      mov %rsi, %rdi
      mov %rax, %rsi
      call push_tower
      pop %rsi
      pop %rdi
      jmp print_all
    
    ;;; %rdi is the number of rings
    solve:
      push %rdi
      mov %rsp, %rbp
    
      ;; S tower
      sub $64, %rsp
      mov %rsp, %rdi
      call init_tower
    
      ;; A tower
      sub $64, %rsp
      mov %rsp, %rdi
      call init_tower
    
      ;; D tower
      sub $64, %rsp
      mov %rsp, %rdi
      call init_tower
    
      ;; initialize S tower
      lea -64(%rbp), %rax
      mov (%rbp),%rcx
      mov %rcx, (%rax)              ; set the size of the tower
      add $4, %rax
    
    .init_s:
      mov %rcx, (%rax)
      add $4, %rax
      loop .init_s
    
      call print_all                ; print them all
    
      mov (%rbp), %cl               ; copy N into %cl
      mov $1, %r14                  ; shift operand
      shl %cl, %r14                 ; 1 << N
      dec %r14                      ; now %r14 holds (1<<N)-1
      xor %r15,%r15                 ; the loop variable
    
    .solve_loop:
      lea -64(%rbp), %rdi           ; A tower
      lea -192(%rbp), %rsi          ; D tower
      call move_tower
    
      inc %r15                      ; increase loop counter
      cmp %r14, %r15                ; compare to loop end
      jge .leave_solve              ; leave if done
    
      lea -64(%rbp), %rdi
      lea -128(%rbp), %rsi
      call move_tower
    
      inc %r15
      cmp %r14, %r15
      jge .leave_solve
    
      lea -192(%rbp), %rdi
      lea -128(%rbp), %rsi
      call move_tower
    
      inc %r15
      cmp %r14, %r15
      jge .leave_solve
      jmp .solve_loop
    
    .leave_solve:
      lea 8(%rbp), %rsp             ; fix the stack
      ret
    
    _start:
      mov %edi, $3                 ; 3 rings by default
      cmp (%rsp), $1               ; compare argc, 1
      jle .solve
      mov 16(%rsp), %rax            ; store argv[1] into %rax
      movsb %edi, (%rax)            ; store argv[1][0] into %edi
      sub %edi, $'0'               ; convert to integer
    .solve:
      call solve
    
      mov $60, %rax                 ; SYS_exit
      xor %rdi, %rdi
      syscall
