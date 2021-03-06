.section .rodata
	msgP1:
	.string	"enter cnt:"
	
	msgP2:
	.string	"cnt = %d\n"

	msgS1:
	.string "%d"

.section .text
.global	main
.type	main, @function

main:
	pushl	%ebp
	movl	%esp, %ebp

	subl	$4, %esp

	pushl	$msgP1
	call	printf
	addl	$4, %esp

	leal	-4(%ebp), %eax
	
	pushl	%eax
	pushl	$msgS1
	call	scanf
	addl	$8, %esp
	
	movl	-4(%ebp), %eax
		
	pushl	%eax
	pushl	$msgP2
	call	printf
	addl	$8, %esp

	pushl	$0
	call	exit
