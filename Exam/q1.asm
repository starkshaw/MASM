		.MODEL small
		.STACK
		.DATA
text	BYTE	"?sesu sti sah msa"
textend	BYTE	"*"

		.CODE
		.STARTUP
		mov cx, 0
start:	mov bx, OFFSET textend
back:	dec bx
		mov dx, [bx]
		cmp dl, '?'
		jz done
		sub dl, 'a'-'A'
		mov ah, 02h
		int 021h
		jmp back
		
done:	inc cx
		cmp cx, 10
		jnz start
		.EXIT
		END