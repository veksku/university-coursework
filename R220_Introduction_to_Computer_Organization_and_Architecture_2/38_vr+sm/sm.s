.intel_syntax noprefix

.text

.global smesti

#void smesti(int*, int, int*, int*)
#						 rdi	 rsi	rdx		rcx

smesti:

#rdi je pok na x
#rsi duzina x
#rdx pok na y
#rcx duzina y

enter 0,0

xor r8, r8 #i, brojac x
xor r9, r9 #j, brojac y

petlja:

cmp r8, rsi
je kraj

mov r10, [rdi+4*r8] #x[i]
and r10, 1
jz paran

inc r8
jmp petlja

paran:

mov rdi, [rdi+4*r8]

push rdi
push [rdx + 4*r9]

call vrednost

pop [rdx + 4*r9]
pop rdi

mov r9,rax
mov [rdx + 4*r9], r9

inc r9
inc r8
add rdx, 4
jmp petlja

kraj:

mov [rcx], r9
leave
ret
