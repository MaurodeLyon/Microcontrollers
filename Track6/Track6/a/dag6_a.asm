; demoprogramma 6_A: 8 bits optelling
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
main:						;
; 8 bits optelling: r9 = r8 + r7  (23 + 48 = 6  /  ab + 98 = 43 + carry)
 
			ldi		r20,$01
			ldi		r21,$03
			mov		r8,r20
			mov		r7,r21
forever:	
			add		r4, r8		; R4 <- R8 		
			add		r4, r7		; R4 <- R4+R7 		 misschien Carry gezet 
			mov		r9, r4		; R9 <- R4 
			   					; unlimited loop, when done
			rjmp 	forever		;				
