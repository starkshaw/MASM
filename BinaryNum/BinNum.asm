		.MODEL small
		.STACK
		.DATA
		string1 db 'Enter A: ', 10, 13, '$'
		string2 db 'Enter B: ', 10, 13, '$'
		string3 db 'Enter C: ', 10, 13, '$'
		.CODE
		.STARTUP
		mov dx, OFFSET string1	;Print Enter A
		mov ah, 09h
		int 021h
		mov dx, OFFSET string2
		mov ah, 09h
		int 021h
		mov dx, OFFSET string3
		mov ah, 09h
		int 021h
		.EXIT
		END