.section .rodata
	
	msgP1:
	.string "Enter a: "

	msgP2:
	.string "Enter b: "
	
	msgP3:
	.string "Enter c: "
	
	msgP4:
	.string "Enter d: "

	msgP5:
	.string "True"
	
	msgP6:
	.string "False"

	msgS1:
	.string "%d"

	msgS2:
	.string "%u"
	
.section .bss
	.comm	a, 4, 4
	.comm	b, 4, 4
	.comm	c, 4, 4
	.comm	d, 4, 4

.section .text
.global	main
main:
	# prologue
	pushl	%ebp
	movl	%esp, %ebp

# printf / scanf a
	pushl	$msgP1
	call	printf
	addl	$4, %esp
	
	pushl	$a
	pushl	$msgS1
	call	scanf
	addl	$8, %esp
	
# printf / scanf b
	pushl	$msgP2
	call	printf
	addl	$4, %esp
	
	pushl	$b
	pushl	$msgS1
	call	scanf
	addl	$8, %esp
	
# printf / scanf c
	pushl	$msgP3
	call	printf
	addl	$4, %esp
	
	pushl	$c
	pushl	$msgS2
	call	scanf
	addl	$8, %esp
	
# printf / scanf d
	pushl	$msgP4
	call	printf
	addl	$4, %esp
	
	pushl	$d
	pushl	$msgS2
	call	scanf
	addl	$8, %esp

# execution of if condition a>b || c<d
	movl	a, %eax
	movl	b, %edx
	cmpl	%edx, %eax
	
	jg	if_block

	movl	c, %eax
	movl	d, %edx
	cmpl	%edx, %eax

	jnb	else_block

if_block:	

# puts("True");
	pushl	$msgP5
	call	puts
	addl	$4, %esp

	jmp	end_of_else

else_block:

# puts("False")
	pushl	$msgP6
	call	puts
	addl	$4, %esp

end_of_else:

# exit (0)
	pushl	$0
	call	exit
	
