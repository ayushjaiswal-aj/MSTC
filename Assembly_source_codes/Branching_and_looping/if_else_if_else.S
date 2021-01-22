.section .rodata
	msgP1:
	.string "Enter a:"
	
	msgP2:
	.string "Enter b:"
	
	msgP3:
	.string "Enter c:"
	
	msgP4:
	.string "Enter d:"
	
	msgP5:
	.string "Enter e:"
	
	msgP6:
	.string "Enter f:"

	msgP7:
	.string "if block is executed"
	
	msgP8:
	.string "else if block 1 is executed"
	
	msgP9:
	.string "else if block 2 is executed"

	msgP10:
	.string "All conditions have been false"

	msgS1:
	.string "%d"

.section .bss
	.comm	a, 4, 4
	.comm	b, 4, 4
	.comm	c, 4, 4
	.comm	d, 4, 4
	.comm	e, 4, 4
	.comm	f, 4, 4

.section .text
.global main
main:
	# progolue
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
	pushl	$msgS1
	call	scanf
	addl	$8, %esp

# printf / scanf d
	pushl	$msgP4
	call	printf
	addl	$4, %esp
	
	pushl	$d
	pushl	$msgS1
	call	scanf
	addl	$8, %esp

# printf / scanf e
	pushl	$msgP5
	call	printf
	addl	$4, %esp
	
	pushl	$e
	pushl	$msgS1
	call	scanf
	addl	$8, %esp

# printf / scanf f
	pushl	$msgP6
	call	printf
	addl	$4, %esp
	
	pushl	$f
	pushl	$msgS1
	call	scanf
	addl	$8, %esp

# checking condition for if_block if true then execute if_block

	movl	a, %eax
	movl	b, %edx
	cmpl	%edx, %eax
	jle	if_block

# check condition for if_else_blocl_1

	movl	c, %eax
	movl	d, %edx
	cmpl	%edx, %eax
	jge	if_else_block_1

#check condition for if_else_block_2
	
	movl	e, %eax
	movl	f, %edx
	cmpl	%edx, %eax
	je	else_block

#execution of condition blocks

if_block:
	pushl	$msgP7
	call	puts
	addl	$4, %esp
	jmp	end_of_else

if_else_block_1:
	pushl	$msgP8
	call	puts
	addl	$4, %esp
	jmp	end_of_else
	
if_else_block_2:
	pushl	$msgP9
	call	puts
	addl	$4, %esp
	jmp	end_of_else
	
else_block:
	pushl	$msgP10
	call	puts
	addl	$4, %esp
	
end_of_else:
	pushl	$0
	call	exit

	
