# Directive to an assembler to create a read only data section
.section .rodata
	msgP1:
	.string "result = %d\n"
	
	q_msg:
	.string "Quotient = %d\n"
	
	r_msg:
	.string "Remainder = %d\n"
	
# Create BSS section -> BSS -> Block of memory started by symbol
# whose initial value is 0. (i.e. no explicit value is provided
# Future hint -> global UNinitialized data defination statement 
# they are allocated as BSS variables in assembly.
	
.section .bss
	.comm	n1, 4, 4
	.comm	n2, 4, 4
	.comm	rs, 4, 4
	.comm	qnt, 4, 4
	.comm	rmd, 4, 4
	
.section .text
.global main
.type main, @function
main: 
	pushl	%ebp
	movl	%esp, %ebp
	
	movl	$10, n1
	movl	$20, n2
	
# Addition
	movl	n1, %eax
	movl	n2, %edx
	addl	%edx, %eax
	movl	%eax, rs
	
	pushl	rs
	pushl	$msgP1
	call	printf
	addl	$8, %esp
	
# Subtraction
	movl	n1, %eax
	movl	n2, %edx
	subl	%edx, %eax
	movl	%eax, rs
	
	pushl	rs
	pushl	$msgP1
	call	printf
	addl	$8, %esp
	
# Unsigned Multiplication
	movl	$10, n1
	movl	$3, n2
	
	movl	n1, %eax
	movl	n2, %ebx
	movl	$0, %edx
	mull	%ebx
	
	pushl	%eax
	pushl	$msgP1
	call	printf
	addl	$8, %esp
	
# Signed Multiplication
	movl	$20, n1
	movl	$-6, n2
	
	movl	n1, %eax
	movl	n2, %ebx	
	movl	$0, %edx
	imull	%ebx
	
	pushl	%eax
	pushl	$msgP1
	call	printf
	addl	$8, %esp
	
# Unsigned Division
	movl	$20, n1
	movl	$6, n2
	
	movl	n1, %eax
	movl	n2, %ebx
	movl	$0, %edx
	
	divl	%ebx
	movl	%eax, qnt
	movl	%edx, rmd
	
	pushl	qnt
	pushl	$q_msg
	call	printf
	addl	$8, %esp
	
	pushl	rmd
	pushl	$r_msg
	call	printf
	addl	$8, %esp
	
# Signed Division
	movl	$-20, n1
	movl	$6, n2

	movl	n1, %eax
	movl	n2, %ebx
	cdq
	idivl	%ebx
	movl	%eax, qnt
	movl	%edx, rmd
	
	pushl	qnt
	pushl	$q_msg
	call	printf
	addl	$8, %esp
	
	pushl	rmd
	pushl	$r_msg
	call	printf
	addl	$8, %esp

	
# exit function call
	pushl	$0
	call	exit
	
	
	
	
	
