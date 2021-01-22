.section .rodata
	msg:
	.string "rs = %llu\n"
	
.section .data
	n2:
	.int	0x10203040
	
	n1:
	.int	0xa0b0c0d0
	
.section .bss
	.comm 	rs, 8, 4
	
.section .text
.global main
main:
	pushl	%ebp
	movl	%esp, %ebp
	
	movl	n1, %eax
	movl	n2, %ebx
	movl	$0, %edx
	mull	%ebx
	
	movl	%eax, rs
	movl	%edx, rs+4
	
	pushl	rs+4
	pushl	rs
	pushl	$msg
	call	printf
	addl	$12, %esp
	
	pushl	$0
	call	exit
