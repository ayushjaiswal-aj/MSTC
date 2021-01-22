.section .rodata
	msg:
	.string "rs = %d\n"
	
	proof:
	.string "Proof of assembly source"
	
.section .data
	n1:
	.int	10
	
	n2:
	.int	20
	
.section .bss
	.comm	rs, 4, 4
	
.section .text
.globl main
main:
	#porlogue
	pushl	%ebp
	movl	%esp, %ebp
	
# Body Start
# start rs = n1+n2;
	movl	n1, %eax
	movl	n2, %edx
	addl	%edx, %eax
	movl	%eax, rs
# end rs = n1+n2

# start printf("proof of assembly source");
	pushl	rs			# S1
	pushl	$msg		# S1
	call	printf		# S2
	addl	$8, %esp	# S3

# start puts("proof of assembly source");
	pushl	$proof
	call	puts
	addl	$4, %esp
# end of puts("proof of assembly source");
# end of printf("rs = %d\n", rs);
# exit
	push	$0
	call	exit


