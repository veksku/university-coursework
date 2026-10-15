.intel_syntax noprefix

.text

.global prost

# unsigned prost(unsigned)
# 		 eax	  edi

prost:

enter 0,0

mov r12d, 0
mov esi, 2

###esi je brojac
###edi je n

petlja:	#

cmp esi,edi
jae nesto

mov eax, edi

cdq
div eax, esi

### eax = kolicnik, edx = ostatak

cmp edx, 0
jz kraj

inc esi
jmp petlja

#

nesto:

mov r12d, 1

kraj:
mov eax, r12d
leave
ret
