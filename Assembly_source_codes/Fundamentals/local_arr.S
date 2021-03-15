.section .rodata
	msgP1:
	.string "a[%d] = %d\n"

.section .text
.global	main
.type	main, @function

main:

	pushl	%ebp
	movl	%esp, %ebp

	subl	$24, %esp

	movl	$100, -24(%ebp)
	movl	$200, -20(%ebp)
	movl	$300, -16(%ebp)
	movl	$400, -12(%ebp)
	movl	$500, -8(%ebp)

	movl	$0, -4(%ebp)
	jmp	print_condition

print_body:

	movl	-24(%ebp, %eax, 4), %edx
	
	pushl	%edx
	pushl	%eax
	pushl	$msgP1
	call	printf
	addl	$1, -4(%ebp)

print_condition:
	
	movl	-4(%ebp), %eax
	cmpl	$5, %eax
	jl	print_body

	pushl	$0
	call	exit
