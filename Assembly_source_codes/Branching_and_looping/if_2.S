.section .rodata
	msgP1: 
	.string "U: Enter n1:"

	msgP2: 
	.string "U: Enter n2:"

	msgP3: 
	.string "C: n1 is less than or equal to n2"

	msgP4:
	.string "End of program"

	msgS1:
	.string "%d"

.section .bss
	.comm n1, 4, 4
	.comm n2, 4, 4

.section .text
.global main
main:
	# Prologue
	pushl	%ebp
	movl	%esp, %ebp

# printf 
	pushl	$msgP1
	call	printf
	addl	$4, %esp

# scanf
	pushl	$n1
	pushl	$msgS1
	call	scanf
	addl	$8, %esp

# printf 
	pushl	$msgP2
	call	printf
	addl	$4, %esp
	
# scanf
	pushl	$n2
	pushl	$msgS1
	call	scanf
	addl	$8, %esp

	movl	n1, %eax	# n1 <- %eax
	movl	n2, %edx	# n2 <- %edx
	cmpl	%edx, %eax	# edx comparing with eax
	
	jnle	out
	
	pushl	$msgP3
	call	puts
	addl	$4, %esp

out: 	
	pushl	$msgP4
	call	puts
	addl	$4, %esp
	
	pushl	$0
	call	exit

