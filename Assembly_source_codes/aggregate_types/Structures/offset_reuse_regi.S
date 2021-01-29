.section .rodata
	msgP1:
	.string	"%d, %d, %d, %d, %d, %d\n"

.section .bss
	.comm	x, 24, 4

.section .text
.global	main

main:
	pushl	%ebp
	movl	%esp, %ebp

	movl	$x, %eax
	movl	$10, 0(%eax)
	movl	$20, 4(%eax)
	movl	$30, 8(%eax)
	movl	$40, 12(%eax)
	movl	$50, 16(%eax)
	movl	$60, 20(%eax)

	movl	$x, %eax
	movl	20(%eax), %edx
	pushl	%edx
	
	movl	16(%eax), %edx
	pushl	%edx
	
	movl	12(%eax), %edx
	pushl	%edx
	
	movl	8(%eax), %edx
	pushl	%edx

	movl	4(%eax), %edx
	pushl	%edx
	
	movl	0(%eax), %edx
	pushl	%edx

	pushl	$msgP1
	call	printf
	addl	$28, %esp

	pushl	$0
	call	exit
