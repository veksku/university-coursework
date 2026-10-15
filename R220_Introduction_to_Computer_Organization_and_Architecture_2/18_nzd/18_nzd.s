.intel_syntax noprefix

.text

.global nzd

# unsigned nzd(unsigned,unsigned)
# eax		edi	    esi

nzd:

enter 0,0

mov eax,edi
mov edx,esi

petlja:
cmp edx, 0
je kraj

mov esi,edx

cdq
div esi

mov eax,esi
jmp petlja

kraj:
leave
ret
