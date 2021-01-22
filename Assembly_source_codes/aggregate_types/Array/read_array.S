.section .rodata
	msgP1:
	.string	"current element A[%d]: %d\n"

.section .data
	A:
	.int	1, 2, 3, 4, 5, 6, 7, 8, 9, 0

.section .bss
	.comm	i, 4, 4
	.comm	current_element, 4, 4

.section .text
.global main
main:
	# Prologue
	pushl	%ebp
	movl	%esp, %ebp

	movl	$0, i
	jmp	for_condition

for_body:
	movl	i, %eax
	movl	A(, %eax, 4), %edx
	movl	%edx, current_element

	pushl	current_element
	pushl	i
	pushl	$msgP1
	call	printf
	addl	$12, %esp

	addl	$1, i

for_condition: 
	movl	i, %eax
	cmpl	$10, %eax
	jl	for_body

	#exit(0)
	pushl	$0
	call	exit	
