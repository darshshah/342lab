@Group No-13
@Anish Parikh(asp@andrew.cmu.edu)
@Darsh Shah(darshs@andrew.cmu.edu)
@Subramaniam Srisankaran (ssrisank@andrew.cmu.edu)





	.file	"part1-strTable.c"
	.text
	.align	2
	.global	strTable
	.type	strTable, %function
strTable:
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	stmfd	sp!, {r6}    @ eliminated the use of r4 and r5
	subs	r3, r3, #0   @ instead of mov r0, r3; mov r2, #0; and cmp r2,r3; 
	ble 	.L11	     @instead of bge, we used ble		
	sub 	r3, r3, #1   @ we added this inst. as we do a countdown loop. 

.L9:
	ldrb	r12, [r1, r3]	@ eliminated the use of temporary register
	mov	r6,r12          @ eliminated the use of a load instr.
	
.L7:
	sub	ip, ip, #23 
	cmp	ip, #22     
	bgt	.L7             @ Instead of using 2 branch instr, we used 1.
	
.L13:
	cmp	ip, r2			
	bgt	.L4		
	strb	r6, [r0, ip]	@ Eliminated the use of 2 load and 1 cmp inst by not checking for similar character.
.L4:
	subs	r3, r3, #1	@ Using countdown loop and so eliminated one cmp instr.
	bpl	.L9		@ To continue until r3 becomes -ve.
.L11:
	ldmfd	sp!, {r6}       @ eliminated the use of 2 registers. 
	mov pc, lr
	.size	strTable, .-strTable
	.ident	"GCC: (GNU) 3.4.5"
