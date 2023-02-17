.text
.arm
.global Retardo

Retardo:

loop:    cmp		r0,#0
		 BEQ		salir
		
		 SUBNE	R0,R0,#1
		 B		loop
		
salir:	 MOV		PC,LR
