# Goal of this program is to translate if_1.c

.section .rodata
	msg_p1:
	.string "U: this is a start of the program"

	msg_p2:
	.string "C: This will be printed if n1>n2"

	msg_p3:
	.string "U: This is a last statement of program"

.section .data
	n1:
	.int	10
	
	n2:
	.int	5

.section .text
.global	main
main:
	# Prologue
	pushl	%ebp
	movl	%esp, %ebp
	
# puts (msp_p1)
	pushl	$msg_p1
	call	puts
	addl	$4, %esp

# S1 : compare n1 and n2 and store the result
# in eflags register
	movl	n1, %eax	# eax <- n1
	movl	n2, %edx	# edx <- n2
	cmpl	%edx, %eax	# edx and eax comp | n2 and n1 comp 

	jng	out		# if n2 > n1 folling code will be executed
				# otherwise not

	pushl	$msg_p2
	call	puts
	addl	$4, %esp

out: 
	pushl	$msg_p3
	call	puts
	addl	$4, %esp

	pushl	$0
	call	exit
