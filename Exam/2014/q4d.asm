		.MODEL small
		.DATA
		msg1 db 'AX is bigger.', 13, 10, '$'
		msg2 db 'BX is bigger.', 13, 10, '$'
		.STACK
		.CODE
		.STARTUP
		mov ax, 10				; Load 10 to ax
		mov bx, 20				; Load 20 to bx
		cmp ax, bx				; Compare ax to bx
		jle less				; Jump if ax is less, to less label
		mov cx, bx				; Then move bx to cx
		mov ax, @data			; Load data to ax
		mov ds, ax				; Load ax to ds (display) register
		mov dx, OFFSET msg1		; Load OFFSET msg1
		jmp exit				; Jump to exit
less:	mov cx, ax				; Move ax to cx
		mov ax, @data
		mov ds, ax
		mov dx, OFFSET msg2
exit:	mov ah, 9h				; String output
		int 21h					; Display and interrupt
		mov ax, 4c00h			; String output (change line)
		int 21h					; Display and interrupt
		.EXIT
		END