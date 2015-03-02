		; 3^2 + 4^2 = 5^2
		; 5 is equal 101 in binary
		.MODEL medium
		.STACK 100h
		.DATA
		SX dd 3.0
		SY dd 4.0
		HY dd 0.0	; Will equal 5
		cntrl dw 03FFh
		stat dw 0
		.CODE
		.STARTUP
		FINIT ; Set FPU to default state
		FLDCW cntrl ; Round even, Mask Interrupts
		FLD SX ; Push SX onto FP stack
		FMUL ST,ST(0) ; Multiply ST*ST result on ST
		FLD SY ; Push SY onto FP stack
		FMUL ST,ST(0) ; Multiply ST*ST
		FADD ST,ST(1) ; ADD top two numbers on stack
		FSQRT ; Square root number on stack
		FSTSW stat ; Load FPU status into [stat]
		;mov ax,stat ; Copy [stat] into ax
		;and al,0BFh ; Check all 6 status bits
		;jnz pass ; If any bit set then jump
		FSTP HY ; Copy result from stack into HY
pass:	nop
		mov bx, OFFSET HY
		inc bx
		inc bx
		mov ax, [bx]
		mov bx, ax
		
		mov cx, 16
back:	rol bx, 1	; Rotate bx
		jc set		; Check MSB first
		mov dl, '0'	; If carry set to 0
		jmp over
set:	mov dl, '1'	; If not carry set to 1
over:	mov ah, 02h	; Print
		int 021h
skip:	loop back
		
		
		mov bx, OFFSET HY
		mov ax, [bx]
		mov bx, ax
		
		mov cx, 16
back1:	rol bx, 1
		jc set1
		mov dl, '0'
		jmp over1
set1:	mov dl, '1'
over1:	mov ah, 02h
		int 021h
skip1:	loop back1

		.EXIT
		END