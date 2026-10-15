.intel_syntax noprefix

.text

.global vrednost

#int vrednost (int)
#eax					 edi

vrednost:

enter 0,0

mov eax, edi

mul edi

cmp eax, 24
jg min24

leave
ret

min24:

mov eax, 24
leave
ret
