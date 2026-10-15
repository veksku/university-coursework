.intel_syntax noprefix

.text

.global bitovska_aritmetika

###bitovska(unsigned, unsigned, unsigned*, unsigned*, unsigned*, unsigned*)
###					edi				esi				rdx				 rcx				r8				 r9			

bitovska_aritmetika:

enter 0,0

mov r12d, edi
and r12d, esi
mov [rdx], r12d

mov r12d, edi
or r12d, esi
mov [rcx], r12d

mov r12d, edi
xor r12d, esi
mov [r8], r12d

not edi
mov [r9], edi

leave
ret
