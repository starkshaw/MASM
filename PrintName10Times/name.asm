.MODEL medium
.STACK
.DATA
	msg1 BYTE "Zhenbang Xiao 'Stark'",10,13,"$"
.CODE
.STARTUP
	mov cx,0	
	start: mov bx,OFFSET msg1
	back: mov dx,[bx] ;dl=letters
	cmp dl,'$'
	jz done
	mov ah,02h
	int 021h
	inc bx
	jmp back
	
	done: nop
	inc cx
	cmp cx,10
	jnz start
.EXIT
END