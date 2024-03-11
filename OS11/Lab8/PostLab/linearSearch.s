;Tianze Ren, tr2bx, 11/03/2022, linearSearch.s
global  linearSearch

section .text

linearSearch:
    xor rax, rax
    xor r8, r8
    xor r9, r9
loop:
    cmp r8, rsi
    je  false
    mov r9, r8
    imul r9, 4
    add rdi, r9
    mov rcx, [rdi]
    cmp ecx, edx
    je  true
    inc r8
    sub rdi, r9
    jmp loop
false:
    mov rax, -1
    ret
true:
    mov rax, r8
    ret
