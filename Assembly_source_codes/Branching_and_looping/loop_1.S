.section .rodata
	msgP1:
	.string "i = %d, j = %d\n"

.section .data
	i:
	.int	0

	j:
	.int	1

.section .text
.global	main
main:
	# prologue
	pushl	%ebp
	movl	%esp, %ebp

	jmp mn_while_condition

mn_while_body:
	pushl	j
	pushl	i
	pushl	$msgP1
	call	printf
	addl	$12, %esp

	addl	$1, i
	addl	$3, j

mn_while_condition:
	movl	i, %eax
	cmpl	$10, %eax
	jnl	mn_while_out
	movl	j, %eax
	cmpl	$21, %eax
	jl	mn_while_body

mn_while_out:
	pushl	$0
	call	exit

