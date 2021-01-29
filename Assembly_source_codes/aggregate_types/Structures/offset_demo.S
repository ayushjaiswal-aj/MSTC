.section .rodata
	msgP1:
	.string "%d-%d-%d\n"
	
.section .bss
	.comm	d, 12, 4

.section .text
.global	main
main:
	pushl	%ebp
	movl	%esp, %ebp

	movl	$d, %eax		# eax <- base address of d
	movl	$29, 0(%eax)		# 0 = offset (day)
	movl	$2, 4(%eax)		# 4 = offset (month)
	movl	$2019, 8(%eax)		# 8 = offset (year)

	movl	$d, %eax
	movl	0(%eax), %ebx
	movl	4(%eax), %ecx
	movl	8(%eax), %edx

	pushl	%edx
	pushl	%ecx
	pushl	%ebx
	pushl	$msgP1
	call	printf
	addl	$16, %esp

	movl	$d, %eax
	movl	$11, 0(%eax)
	movl	$3, 4(%eax)	
	movl	$2020, 8(%eax)
	
	movl	$d, %eax
	movl	0(%eax), %ebx
	movl	4(%eax), %ecx
	movl	8(%eax), %edx

	pushl	%edx
	pushl	%ecx
	pushl	%ebx
	pushl	$msgP1
	call	printf
	addl	$16, %esp

	pushl	$0
	call	exit
