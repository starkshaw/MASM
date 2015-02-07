.MODEL medium
.STACK
.DATA
.CODE
.STARTUP
nextc: mov ah,8
int 021h	;al character pressed
mov dl,al
mov ah,02h ;print dl
int 021h
cmp dl,'q'
jnz nextc
.EXIT
END