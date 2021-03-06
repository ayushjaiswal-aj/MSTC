.section .rodata
	msgP1:
	.string	"cnt = %d\n"

.section .text

.global main
.type 	main, @function

main:
	pushl	%ebp
	movl	%esp, %ebp
	
	subl	$4, %esp
	movl	$100, -4(%ebp)
	
	movl	-4(%ebp), %eax

	pushl	%eax
	pushl	$msgP1
	call	printf
	addl	$8, %esp

	pushl	$0
	call	exit
