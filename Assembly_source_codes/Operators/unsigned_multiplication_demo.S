.section .rodata
	msg:
	.string "rs = %u\n"
	
.section .data
	n1:
	.int	50
	
	n2:
	.int	5
	
.section .bss
	.comm	rs, 4, 4
	
.section .text
.globl main
main:
	# Prologue
	pushl	%ebp
	movl	%esp, %ebx
	
	# rs = n1*n2
	movl	n1, %eax
	movl	n2, %ebx
	
	mull	%ebx
	movl	%eax, rs
	
	# printf("rs = %u\n", rs);
	pushl 	rs
	pushl	$msg
	call	printf
	addl	$8, %esp
	
	# exit(0)
	pushl	$0
	call	exit
