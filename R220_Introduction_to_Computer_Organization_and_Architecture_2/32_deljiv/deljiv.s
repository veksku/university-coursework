.intel_syntax noprefix

.text

.global deljiv

# int deljiv(int, int)
# eax				 edi	esi

deljiv:

enter 0,0

mov eax, edi

cdq

div esi

cmp edx,0
jz jeste

mov eax, 0

leave
ret

jeste:

mov eax,1

leave
ret
