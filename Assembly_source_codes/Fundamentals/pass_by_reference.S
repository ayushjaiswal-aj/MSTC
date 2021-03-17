.section .rodata
	msgP1:
	.string	"Before call : n = %d\n"

	msgP2:
	.string	"After call : n = %d\n"

.section .text

.global	main
.type	main, @function

main:

	pushl	%ebp
	movl	%esp, %ebp

	subl	$4, %esp

	movl	$500, -4(%ebp)

	movl	-4(%ebp), %eax

	pushl	%eax
	pushl	$msgP1
	call	printf
	addl	$8, %esp

	leal	-4(%ebp), %eax

	pushl	%eax
	call	test_function
	addl	$4, %esp

	leal	-4(%ebp), %eax
	
	pushl	%eax
	call	test_function	
	addl	$4, %esp

	movl	-4(%ebp), %eax
	
	pushl	%eax
	pushl	$msgP2
	call	printf
	addl	$8, %esp

	pushl	$0
	call	exit

test_function:
	
	pushl	%ebp
	movl	%esp, %ebp

	movl	8(%ebp), %eax
	movl	$1000, (%eax)

	movl	%ebp, %esp
	popl	%ebp
	ret
