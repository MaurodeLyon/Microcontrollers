;
; One.asm
;
; Created: 6-4-2016 12:15:55
; Author : Arthur
;


; Replace with your application code
start:
    //inc r16
	ldi r20, $55
	STS $540, r20
	STS $541, r20
	STS $542, r20
	STS $543, r20
	STS $544, r20
	STS $545, r20
	STS $546, r20
	STS $547, r20
    rjmp start
