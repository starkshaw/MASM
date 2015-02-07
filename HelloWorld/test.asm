.MODEL medium
.STACK
.DATA
msg1 BYTE "Hello, world.$"
.CODE
.STARTUP
mov bx,OFFSET msg1
back: mov dx,[bx] ;dl=letters
cmp dl,'$'
jz done
mov ah,02h
int 021h
inc bx
jmp back
done: nop
.EXIT
END