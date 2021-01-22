.section .rodata
	msgP1:
	.string "i=%d, j=%d\n"

.section .bss
	.comm	i, 4, 4
	.comm	j, 4, 4

.section .text
.global	main
main:
	# prologue
	pushl	%ebp
	movl	%esp, %ebp

	movl	$0, i

	jmp	while_1_condition

while_1_body:
	movl	$0, j

	jmp	while_2_condition

while_2_body:
	pushl	j
	pushl	i
	pushl	$msgP1
	call	printf
	addl	$12, %esp

	addl	$1, j

while_2_condition:
	movl	j, %eax
	cmpl	$6, %eax
	jl	while_2_body
	
	addl	$1, i

while_1_condition:
	movl	i, %eax
	cmpl	$5, %eax
	jl	while_1_body

	pushl	$0
	call 	exit
