	section	.data
tmplbl:	db 0		;

	section	.text
	global	printRAX

printRAX:

	mov	rbx, 10
	cqo			; sign extend rax
	idiv	rbx		;remainder in rdx is char to print

	mov	[tmplbl], dl

;;;  print out 1 character string starting at tmplbl
	


	ret
