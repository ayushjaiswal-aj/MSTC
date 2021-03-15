.section .rodata
	msgP1:
	.string	"Enter a[%d]:"

	msgP2:
	.string	"a[%d]: %d\n"

	msgS1:
	.string	"%d"

.section .text

.global	main
.type	main, @function

main:

	pushl	%ebp
	movl	%esp, %ebp

	subl	$24, %esp
	
	movl	$0, -4(%ebp)
	jmp	arr_scan_condition

arr_scan_body:

	movl	-4(%ebp), %eax

	pushl	%eax
	pushl	$msgP1
	call	printf
	addl	$8, %esp

	movl	-4(%ebp), %eax
	leal	-24(%ebp, %eax, 4), %edx	
	pushl	%edx
	pushl	$msgS1
	call	scanf
	addl	$8, %esp

	addl	$1, -4(%ebp)

arr_scan_condition:
	
	movl	-4(%ebp), %eax
	cmpl	$5, %eax
	jl	arr_scan_body

	movl	$0, -4(%ebp)
	jmp	arr_print_condition

arr_print_body:

	movl	-4(%ebp), %eax

	movl	-24(%ebp, %eax, 4), %edx	
	pushl	%edx
	pushl	%eax
	pushl	$msgP2
	call	printf
	addl	$12, %esp

	addl	$1, -4(%ebp)

arr_print_condition:

	movl	-4(%ebp), %eax
	cmpl	$5, %eax
	jl	arr_print_body

	pushl	$0
	call	exit
