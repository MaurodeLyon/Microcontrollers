; demoprogramma dag6_C: 16 bits optelling met opslag in data memory
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
;						;
	ldi		yh, $04		; Y <- $0400		adres in data memory
	ldi		yl, $00		;
;	ldi		yh, HIGH(a)	;
;	ldi		yl, LOW(a)	;

	ldd		r8, Y+0		; Haal waarden op uit data memory
	ldd		r9, Y+1		;
	ldd		r6, Y+2		;
	ldd		r7, Y+3		;

; 16 bits optelling: r5/r4 = r9/r8 + r7/r6  (23 ab + 44 98 = 68 43)
						; Stap 1: 	tel de LSB’s op: r4 = r6+r8 
	MOV		r4, r8		; 		r4 <- r8 		
	ADD		r4, r6		; 		r4 <- r4+r6 		 misschien Carry gezet 
						; Stap 2: 	tel de MSB’s op met 
						;			de (eventuele) carry uit LSB’s:
						;			r3 = r5+r6+C
	MOV		r5, r9		; 		r5 <- r9 
	ADC		r5, r7		; 		r5 <- r5+r7+C 
;
; Opslag resultaat
;
	STD		Y+4,r4		; Sla resultaat op in data memory
	STD		Y+5,r5		; 
		
no_end:   					; unlimited loop, when done
		rjmp no_end			
		
.DSEG
.ORG	$0400
	a:	.BYTE	2
	b:	.BYTE	2
	c:	.BYTE	2
