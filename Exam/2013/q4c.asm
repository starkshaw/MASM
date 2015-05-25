		.MODEL small
		.DATA
		.STACK
		.CODE
		.STARTUP
main:	mov ax, 40000
		call delay
		.EXIT
delay:	push ax
		pop cx	; Use pop
bk:		loop bk
		ret
		END