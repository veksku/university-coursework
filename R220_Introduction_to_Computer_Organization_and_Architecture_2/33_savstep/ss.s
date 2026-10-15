.intel_syntax noprefix

.text

.global savrsen_stepen

## int savrsen_stepen(unsigned n, unsigned* m, unsigned* k)
## eax								rdi					rsi					 rdx

savrsen_stepen:

enter 0,0

#r11 je m
mov r11, 2 

petlja:

cmp r11, rdi
jae nema_stepen

#r10d je k
mov r10d, 1 

jmp stepenovanje

poredi:

cmp rdi, rax
je ima_stepen

cmp rdi, rax
ja stepenovanje ##novi poziv gde ce k++

inc r11
jmp petlja


stepenovanje:

mov r8, 1 ##brojac stepena
mov rax, r11 ##baza jednaka m
inc r10 ##k je stepen

koraci:

cmp r8, r10
jae poredi

mul r11
inc r8
jmp koraci



ima_stepen:

mov rax, 1
leave
ret

nema_stepen:

mov eax, 0
leave
ret
