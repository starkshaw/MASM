		.MODEL small
		.STACK
		.DATA
		.CODE
		.STARTUP
		mov ax, 1
		mov dl, [ax]
		add dl, '0'
		mov ah, 02h
		int 21h
		dec ax
		mov dl, [ax]
		add dl, '0'
		mov ah, 02h
		int 21h
		push ax
		mov dl, [ax]
		add dl, '0'
		mov ah, 02h
		int 21h
		pop ax
		mov dl, [ax]
		add dl, '0'
		mov ah, 02h
		int 21h
		.EXIT
		END