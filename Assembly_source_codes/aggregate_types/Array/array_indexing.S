.section .rodata
	msgP1:
	.string "index A[%d]: %d\n"

.section .data
	A:
	.int	10, 20, 30, 40, 50

.section .bss
	.comm	i, 4, 4
	.comm	current_element, 4, 4

.section .text
.global	main
main:
	pushl	%ebp
	movl	%esp, %ebp

	movl	$0, i
	movl	$A, %eax
	
	pushl	0(%eax)
	pushl	i
	pushl	$msgP1
	call	printf
	addl	$12, %esp

	addl	$1, i

	movl	$A, %eax
	pushl	4(%eax)
	pushl	i
	pushl	$msgP1
	call	printf
	addl	$12, %esp

	addl	$1, i

	movl	$A, %eax
	pushl	8(%eax)
	pushl	i
	pushl	$msgP1
	call	printf
	addl	$12, %esp	

	addl	$1, i

	movl	$A, %eax		
	pushl	12(%eax)
	pushl	i
	pushl	$msgP1
	call	printf
	addl	$12, %esp

	addl	$1, i
	
	movl	$A, %eax
	pushl	16(%eax)
	pushl	i
	pushl	$msgP1
	call	printf
	addl	$12, %esp
	
	pushl	$0
	call	exit
