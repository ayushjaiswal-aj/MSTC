.section .rodata
	msgP1:
	.string	"Enter an integer:\n"

	msgP2:
	.string "gnum = %d\n"

	msgS1:
	.string "%d"

.section .bss
	.comm	gnum, 4, 4

.section .text
.global main
.type	main, @function

main:
	pushl	%ebp
	movl	%esp, %ebp

	pushl	$msgP1
	call	printf
	addl	$4, %esp

	pushl	$gnum
	pushl	$msgS1
	call	scanf
	addl	$8, %esp

	pushl	gnum
	pushl	$msgP2
	call	printf
	addl	$8, %esp

	pushl	$0
	call	exit
