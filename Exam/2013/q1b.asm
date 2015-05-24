.MODEL small
.DATA
.STACK
.CODE
.STARTUP
cmp AH, 30	; Compare 30 to AH
sub AH, 30
shr AH, 1
mov AX, 20
mov BH, AH
push AX
mov dl, al
mov ah, 9h
int 21h
.EXIT
END