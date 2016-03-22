; demoprogramma dag6_D:
; De waarden van 200 (= 0xC8) bytes, 
; die in het datageheugen staan vanaf adres 0x0500 (t/m 0x05c7),
; kopiëren naar geheugenplaatsen vanaf adres 0x0c00
;
.INCLUDE "m128def.inc"
;
.CSEG
.ORG 	$0000
		rjmp main
;
.CSEG
.ORG	$0200
;
main:
; initialisatie data geheugen

		ldi	  	xh, $05		; X is source adres, high byte = 05H
		ldi	  	xl, 00		; X low byte = 00H
		ldi	  	yh, $0c		; Y is destination adres, high byte = 0cH
		ldi	  	yl, 00		; Y low byte = 00H
		ldi	  	r16, 200	; lusteller, r16 = 200

lus:	ld	  	r8, X+		; laad waarde met pointer X in R8
		inc		r8			; one’s complement
		st	  	Y+, r8		; en schrijf weg naar plaats met pntr 
		cp		xl,	r16		; vergelijk zl met 200, sets Z if zero
		brne	lus			; branch indien niet nul (Zero)
;
		
no_end:   					; unlimited loop, when done
		rjmp no_end			
		
.DSEG
.ORG	$0c00
		.BYTE	200			
