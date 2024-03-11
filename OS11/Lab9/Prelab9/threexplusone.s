    global threexplusone
    section .text

threexplusone:
    xor rax, rax
    xor r11, r11
    cmp rdi, 1
    jle base
    mov r11, rdi
    and r11b, 1
    cmp r11, 1
    je  odd
    sar rdi, 1
    call threexplusone
    inc rax
    ret
base:
    mov rax, 0
    ret
odd:
    lea rdi, [rdi*3+1]
    call threexplusone
    inc rax
    ret

    
    
    
