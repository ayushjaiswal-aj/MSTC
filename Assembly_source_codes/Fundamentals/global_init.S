.section .rodata
	msgP1:
	.string	"gnum = %d\n"

	proof:
	.string "Through assembly\n"

.section .data
	.global	gnum
	.type	gnum, @object
	.size	gnum, 4
	.align	4
	gnum:
	.int 	100

.section .text
.global	main
.type	main, @function

main:
	pushl	%ebp
	movl	%esp, %ebp

	pushl	gnum
	pushl	$msgP1
	call	printf
	addl	$8, %esp

	pushl	$proof
	call	printf
	addl	$4, %esp

	pushl	$0
	call	exit
