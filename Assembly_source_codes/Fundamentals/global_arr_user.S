.section .rodata
	msgP1:
	.string "Enter arr[%d]:"

	msgP2:
	.string "arr[%d]: %d\n"

	msgS1:
	.string "%d"

.section .bss
	.comm	arr, 20, 4
	.comm	cnt, 4,	4

.section .text

.global main
.type main, @function

main:

	pushl	%ebp
	movl	%esp, %ebp

	movl	$0, cnt
	jmp	arr_scan_condition

arr_scan_body:
	movl	cnt, %eax
	
	pushl	%eax
	pushl	$msgP1
	call	printf
	addl	$8, %esp

	movl	cnt, %eax
	leal	arr(, %eax, 4), %edx

	pushl	%edx
	pushl	$msgS1
	call	scanf
	addl	$8, %esp

	addl	$1, cnt

arr_scan_condition:

	movl	cnt, %eax
	cmpl	$5, %eax
	jl	arr_scan_body

	movl	$0, cnt
	jmp	arr_print_condition

arr_print_body:
	
	movl	arr(, %eax, 4), %edx

	pushl	%edx
	pushl	%eax
	pushl	$msgP2
	call	printf
	addl	$12, %esp

	addl	$1, cnt

arr_print_condition:

	movl	cnt, %eax
	cmpl	$5, %eax
	jl	arr_print_body

	pushl	$0
	call	exit
