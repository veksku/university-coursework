.intel_syntax noprefix

.text

.global izbaci_neparne

# void izbaci_neparne(long*, unsigned*)
# 										rdi,	 rsi

izbaci_neparne:

enter 0,0

mov r8, 0 #brojac i
mov r9, 0 #brojac j

petlja:

cmp r8, [rsi]
je kraj

mov r11, [rdi + 8*r8]
and r11, 1
jnz dalje

mov r11, [rdi + 8*r8]
mov [rdi + 8*r9], r11
inc r9

dalje:

inc r8
jmp petlja


kraj:

mov [rsi], r9
leave
ret
