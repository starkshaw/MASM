		.MODEL medium
		.STACK
		.DATA
		.CODE
		.STARTUP
		mov ah, 02
		mov dl, 'S'
		int 021h
		
		mov bx, 10000 ;4
		; Inner loop: 4+2000(20)-12=39,992
		; Outer loop: 4+10000(399992+2+16)-12=400,099,992
		; Time: 13 sec
		; Speed: 30776922.46 Hz
		;		 31 MHz
back2:	mov cx, 2000 ;4
back1:	nop ;3
		loop back1 ;17 or 5
		
		dec bx
		jnz back2
		
		mov ah, 02
		mov dl, 'F'
		int 021h
		.EXIT
		END