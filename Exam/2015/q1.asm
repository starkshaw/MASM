		.MODEL medium
		.DATA
		.STACK
		.CODE
		.STARTUP
		mov cl, '9'
next:	mov dl, '1'

print:	mov ah, 2h
		int 21h
		
		inc dl
		cmp dl, cl
		jnz print
		
		mov dl, 10
		mov ah, 2h
		int 21h
		
		dec cl
		cmp cl, '1'
		jnz next
		
		.EXIT
		END