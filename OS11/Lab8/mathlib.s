; Tianze Ren, tr2bx, 10/31/2022, mathlib.s
    global product
    global power

    section .text

product:
    xor rax, rax
    xor r10, r10
start:
    cmp r10, rsi
    je  done
    add rax, rdi
    inc r10
    jmp start
done:
    ret

power:
    xor rax, rax
    mov rax, 1
    mov rdx, 1
recursion:
    cmp rsi, 0
    je  finish
    push rsi
    mov rsi, rdx
    call product
    mov rdx, rax
    pop rsi
    dec rsi
    call recursion
finish:
    ret


