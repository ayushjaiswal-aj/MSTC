.section .rodata
	msgP1:
	.string "Hello"

.section .data
	i:
	.int	i, 4, 4

.section .text
.global	main
main:
	# prologue
	pushl	%ebp
	movl	%esp, %ebp

# i = 0;
	movl	$0, i
	
	jmp	while_condition
	
while_body:
	pushl	$msgP1
	call	puts
	addl	$4, %esp

	addl	$1, i

while_condition:
	movl	i, %eax
	cmpl	$5, %eax
	jl	while_body
	
# exit (0)
	pushl	$0
	call	exit
