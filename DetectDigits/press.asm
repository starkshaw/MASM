	.MODEL small
	.STACK
	.DATA
	.CODE
	.STARTUP
nextc:	mov ah,8
		int 021h	;al character pressed
		mov dl,al
		cmp dl,48
		jc quit
		cmp dl,58
		jnc quit
		
		mov ah,02h
		int 021h
quit:	cmp dl,1Bh
		jnz nextc
		nop
	.EXIT
	END