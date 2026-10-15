.intel_syntax noprefix

.text

.global zbir_apsolutnih

# int zbir_apsolutnih(int*, int)
#	eax									rdi		esi

zbir_apsolutnih:

enter 0,0

xor eax, eax
mov r8, 0 #r8 je i
mov r10, 0 #r10 je suma

petlja:
cmp esi, 0
je kraj

dec esi

mov r9, [rdi+ 4*r8]

cmp r9, 0
ja suma

imul r9, -1

suma:

add r10, r9
jmp petlja


kraj:
leave
ret
