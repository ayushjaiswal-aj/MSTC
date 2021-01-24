.section .rodata
	msgP1:
	.string "Value of n: %d\n"

	msgP2:
	.string "Address of n: %d\n"

.section .data
	n:
	.int	10

.section .bss
	.comm	p, 4, 4

.section .text
.global main

main:
	#prologue
	pushl	%ebp
	movl	%esp, %ebp

	pushl	n
	pushl	$msgP1
	call	printf
	addl	$8, %esp

	pushl	$n
	pushl	$msgP2
	call	printf
	addl	$8, %esp

	movl	$n, %eax
	movl	%eax, p

	pushl	p
	pushl	$msgP2
	call	printf
	addl	$8, %esp

	pushl	$0
	call	exit
