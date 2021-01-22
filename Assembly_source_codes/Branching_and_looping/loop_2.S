.section .rodata
	msgP1:
	.string "i = %d, j = %d \n"

.section .bss
	.comm	i, 4, 4
	.comm	j, 4, 4

.section .text
.global	main
main:
	# prologue
	pushl	%ebp
	movl	%esp, %ebp

# i = 0, j = 1
	movl	$0, i
	movl	$1, j

	jmp	mn_while_condition
# while body
mn_while_body:
	pushl	j
	pushl	i
	pushl	$msgP1
	call	printf
	
	movl	i, %eax
	addl	$1, %eax
	movl	%eax, i

	movl	j, %eax
	addl	$3, %eax
	movl	%eax, j

mn_while_condition:
	movl	i, %eax
	cmpl	$10, %eax
	jl	mn_while_body

	movl	j, %eax
	cmpl	$21, %eax
	jl	mn_while_body

# exit
	pushl	$0
	call	exit
