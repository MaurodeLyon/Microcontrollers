; demoprogramma dag6_D
;
.INCLUDE "m128def.inc"
;
.CSEG
.ORG 	$0000
		rjmp main
;
.equ	number = 10		; 
.equ	source = $0500			; startadres source bytes
.equ	dest = $1000			; startaders destination bytes
.equ	sourceL = LOW(source)
.equ	sourceH = HIGH(source)
.equ	destL = LOW(dest)
.equ	destH = HIGH(dest)
.equ	value = $55				; memory value
 
.CSEG
.ORG	$0200
;
main:						;
		ldi	  	xh, sourceH	; X is source adres, high byte = 05H
		ldi	  	xl, sourceL	; X low byte = 00H
		ldi	  	r16,number	; r16=200

		ldi		r17, value	; load memory value
fill:	st	  	X+, r17		; and write it to memory position with pntr X
		dec		r16			; decrement teller, sets flag if zero
		brne	fill		; branch if not zero

		ldi	  	xh, sourceH	; X is source adres, high byte = 05H
		ldi	  	xl, sourceL	; X low byte = 00H
		ldi	  	yh, destH	; Y is destination adres, high byte = 10H
		ldi	  	yl, destL	; Y low byte = 00H
		ldi	  	r16,number	; r16=200

loop:	ld	  	r8, X+		; load memory position with pointer X in R8
		st	  	Y+, r8		; and write it down to memory position with pntr Y
		dec		r16			; decrement teller, sets Z if zero
		brne	loop		; branch is not zero
		
no_end:   					; unlimited loop, when done
		rjmp no_end				
