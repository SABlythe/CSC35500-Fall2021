	section	.text
	global	_start
	extern	printRAX

_start:
	mov	rax, -513
	call 	printRAX
	
	; return control to Linux 
	mov	rax, 1
	mov	rbx, 0
	int	0x80
