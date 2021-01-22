# goal of this progra is to demonstrate 
# arithmatic shift operators in C in assembly 

.section .rodata
	msg:
	.string "b1 = %u\n"
	
.section .data
	b1:
	.int	0x0a
	
.section .text
.global main
main:
	# prologue
	pushl	%ebp
	movl	%esp, %ebp
	
# shift arithmatic left operator
# printf b1
	pushl	b1
	pushl	$msg
	call	printf
	addl	$8, %esp
	
# b1 = b1 << 1
	movl	b1, %eax
	sall	$1, %eax
	movl	%eax, b1
	
# print b1
	pushl	b1
	pushl	$msg
	call	printf
	addl	$8, %esp
	
# b1 = b1 << 2
	movl	b1, %eax
	sall	$2, %eax
	movl	%eax, b1
	
# print b1
	pushl	b1
	pushl	$msg
	call	printf
	addl	$8, %esp

# shift arithmatic right operator
	movl	$0x18, b1
# print b1
	pushl	b1
	pushl	$msg
	call	printf
	addl	$8, %esp

# b1 = b1 >> 1	
	movl	b1, %eax
	sarl	$1, %eax
	movl	%eax, b1
	
# print b1
	pushl	b1
	pushl	$msg
	call	printf
	addl	$8, %esp

# b1 = b1 >> 2
	movl	b1, %eax
	sarl	$2, %eax
	movl	%eax, b1
	
# print b1
	pushl	b1
	pushl	$msg
	call	printf
	addl	$8, %esp

# exit (0)
	pushl	$0
	call	exit
