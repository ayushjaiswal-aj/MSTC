.section .rodata
	msgP1:
	.string "address of a = %p\n"
	
	msgP2:
	.string "address of b = %p\n"

	msgP3:
	.string "value of a = %d\n"

	msgP4:
	.string "value of b = %d\n"

	msgP5:
	.string "address of n1 = %p\n"

	msgP6: 
	.string "address of n2 = %p\n"

	msgP7:
	.string "value of n1 = %d\n"

	msgP8:
	.string "value of n2 = %d\n"

.section .text

.global	main
.type	main, @function

main:

	pushl	%ebp
	movl	%esp, %ebp

	subl	$8, %esp

	movl	$1000, -4(%ebp)
	movl	$2000, -8(%ebp)

	pushl	$200
	pushl	$100
	call	test_function
	addl	$8, %esp

	leal	-4(%ebp), %eax

	pushl	%eax
	pushl	$msgP1
	call	printf
	addl	$8, %esp

	leal	-8(%ebp), %eax
	
	pushl	%eax
	pushl	$msgP2
	call	printf
	addl	$8, %esp

	movl	-4(%ebp), %eax

	pushl	%eax
	pushl	$msgP3
	call	printf
	addl	$8, %esp
	
	movl	-8(%ebp), %eax

	pushl	%eax
	pushl	$msgP4
	call	printf
	addl	$8, %esp

	movl	-4(%ebp), %eax
	movl	-8(%ebp), %ebx

	pushl	%ebx
	pushl	%eax
	call	test_function
	addl	$8, %esp

	pushl	$0
	call	exit

.global	test_function
.type	test_function, @function

test_function:

	pushl	%ebp
	movl	%esp, %ebp

	leal	8(%ebp), %eax
	
	pushl	%eax
	pushl	$msgP5
	call	printf
	addl	$8, %esp

	leal	12(%ebp), %eax
	
	pushl	%eax
	pushl	$msgP6
	call	printf
	addl	$8, %esp

	movl	8(%ebp), %eax

	pushl	%eax
	pushl	$msgP7
	call	printf
	addl	$8, %esp

	movl	12(%ebp), %eax
	
	pushl	%eax
	pushl	$msgP8
	call	printf
	addl	$8, %esp

	movl	%ebp, %esp
	popl	%ebp
	ret
	
