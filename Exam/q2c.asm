		.MODEL small
		.STACK
		.DATA
		.CODE
		.STARTUP
		mov cx, 3
next:	push cx
		loop next
		pop cx
		RET
		.EXIT
		END