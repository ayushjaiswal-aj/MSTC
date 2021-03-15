.section .rodata
	msgP1:
	.string	"arr[%d]: %d\n"

.section .data
	.global	arr
	.type	arr, @object
	.size	arr, 20
	.align	4
	arr:
	.int	100, 200, 300, 400, 500

.section .bss
	.comm	cnt, 4, 4

.section .text

.global	main
.type	main, @function

main:
	pushl	%ebp
	movl	%esp, %ebp

	movl	$0, cnt
	jmp	for_condition

for_body:
	movl	cnt, %eax
	movl	arr(, %eax, 4), %edx
	
	pushl	%edx
	pushl	%eax
	pushl	$msgP1
	call	printf
	addl	$12, %esp

	addl	$1, cnt

for_condition:
	movl	cnt, %eax
	cmpl	$5, %eax
	jl	for_body

	pushl	$0
	call	exit
