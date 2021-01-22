.section .rodata
	msgP1:
	.string "True"
	
	msgP2:
	.string "False"

.section .data
	a:
	.int	100

	b:
	.int	50
	
	c:
	.int	20
	
	d:
	.int 	10

.section .text
.global main
main:
	# prologue
	pushl	%ebp
	movl	%esp, %ebp

	movl	a, %eax
	movl	b, %edx
	cmpl	%edx, %eax
	jng	else_block

	movl	c, %eax
	movl	d, %edx
	cmpl	%edx, %eax
	jnl	else_block	
	
# if-block of code executed when a>b and c<d
	
	pushl	$msgP1
	call	puts
	addl	$4, %esp
	
	jmp	end_of_else
	
# else-block of code executed when if condition fails
else_block:
	
	pushl	$msP2
	call	puts
	addl	$4, %esp

end_of_else:
#exit(0)
	pushl	$0
	call	exit

