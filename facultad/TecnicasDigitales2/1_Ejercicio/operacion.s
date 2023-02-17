@ Funcion externa que se encarga de realizar 4 operaciones basicas
@ Suma, Resta, Multiplico por 2, Divido por 2 
@ Variables a recibir a,b,c en donde R0 = a, R1 = b, R2 = c 
.text
.arm
.global operacion

operacion:

	cmp r2,#1 
	addeq r0,r0,r1
	moveq pc,lr
	
	cmp r2,#2 
	subeq r0,r0,r1
	moveq pc,lr
	
	cmp r2,#3 
	andeq r0,r0,r1
	moveq pc,lr
	
	cmp r2,#4 
	orreq r0,r0,r1
	moveq pc,lr

