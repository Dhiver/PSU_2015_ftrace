[BITS 64]

global _start:function

toto:
	mov  rax, 1
	mov  rdi, 1
	mov  rsi, toto_str
	mov  rdx, toto_len
	syscall
	ret
tutu:
	mov  rax, 1
	mov  rdi, 1
	mov  rsi, tutu_str
	mov  rdx, tutu_len
	syscall
	ret

_start:
	call toto
	call tutu
	mov  rax, 60
	xor  rdi, rdi
	syscall

toto_str	db "Je suis dans toto", 0x0A, 0x00
toto_len	equ $ - toto_str

tutu_str	db "Je suis dans tutu", 0x0A, 0x00
tutu_len	equ $ - tutu_str
