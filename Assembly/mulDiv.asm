	section		.data
hello:	db "Hello World!", 0xA
	
	section		.text		; this is a comment
	global		_start
_start:
	mov		eax, 956
	mov		ebx, 0xbb223344
	add		eax, ebx
	inc		eax
	dec		ebx
	mul		ebx

	mov		eax, 20
	mov		ebx, 20
	
	;; need to set edx before we divide by ebx
	cdq

	idiv 		ebx	
	
	mov		eax, 1
	mov		ebx, 0
	int		0x80
