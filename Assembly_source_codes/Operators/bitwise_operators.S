.section .rodata
	msg:
	.string	"rs = %x\n"
	
.section .data
	n1:
	.int	0x0f0f0f0f
	
	n2:
	.int	0xf0f0f0f0
	
.section .bss
	.comm	rs, 4, 4
	
.section .text
.global main
main:
	pushl	%ebp
	movl	%esp, %ebp
	
# bitwise NOT:
# rs = ~n1
	movl	n1, %eax		# eax <- n1
	negl	%eax			# eax <- 2's complement of eax
	subl	$1, %eax		# eax <- 1's complement of eax
	movl	%eax, rs		# rs <- eax
	
# print rs
	pushl	rs
	pushl	$msg
	call	printf
	addl	$12, %esp
	
# bitwise AND
# rs = n1 & n2
	movl	n1, %eax
	movl	n2, %edx
	andl	%edx, %eax
	movl	%eax, rs
	
# print rs
	pushl	rs
	pushl	$msg
	call	printf
	addl	$8, %esp
	
# bitwise OR
# rs = n1 | n2
	movl	n1, %eax
	movl	n2, %edx
	orl		%edx, %eax
	movl	%eax, rs
	
# print rs
	pushl	rs
	pushl	$msg
	call	printf
	addl	$8, %esp
	
# bitwise XOR
# rs = n1 (+) n2
	movl	n1, %eax
	movl	n2, %edx
	xorl	%edx, %eax
	movl	%eax, rs
	
# print rs
	pushl	rs
	pushl	$msg
	call	printf
	addl	$8, %esp
	
# exit (0)
	pushl	$0
	call	exit
