.intel_syntax noprefix

.text

.global izdvoji_deljive

## void izdvoji_deljive(int*, int, int*)
##											rdi		esi	 rdx
##rdi je prvi niz
##esi je velicina niza
##rdx je drugi niz
##rcx je kraj drugog niza


izdvoji_deljive:

mov r8, 7

mov r9d, 0 #brojac za prvi niz
mov r10d, 0 #brojac za drugi niz

petlja:

cmp r9d, esi
jae kraj

mov r8, [rdi + 4*r9d]

push [rdi + 4*r9d]
push 7

call deljiv

pop r8
pop [rdi + 4*r9d]

cmp eax, 1
je jeste

inc r9d

jmp petlja


jeste:

mov r11, [rdi+4*r9d]
mov [rdx+4*r10d], r11

inc r10d
inc r9d

jmp petlja

kraj:

mov r11, [rdx+4*r10d]
mov [rcx], r11

leave
ret
