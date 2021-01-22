# Anonymous strings
.section .rodata
	msgP1: 
	.string "This is the start of the program"
	
	msgP2:
	.string "Enter n1:"
	
	msgP3:
	.string "Enter n2:"

	msgP4:
	.string "sum = %d\n"

	msgP5:
	.string "This is the end of the program"

	msgS1:
	.string "%d"

.section .bss
	.comm n1, 4, 4
	.comm n2, 4, 4
	.comm sum, 4 ,4

.section .text
.global	main
main:
	# Prologue
	pushl	%ebp
	movl	%esp, %ebp

# puts("This is a start of the program");
	pushl	$msgP1
	call	puts
	addl	$4, %esp

# printf("Enter n1: ");
	pushl	$msgP2
	call	printf
	addl	$4, %esp

# scanf ("%d", &n1);
	pushl	$n1
	pushl	$msgS1
	call	scanf
	addl	$8, %esp

# printf("Enter n2:");
	pushl	$msgP3
	call	printf
	addl	$4, %esp

# scanf("%d", &n2);
	pushl	$n2
	pushl	$msgS1
	call	scanf
	addl	$8, %esp

# checking if-else
	movl	n1, %eax
	movl	n2, %edx
	cmpl	%edx, %eax	# comparing n2 with n1
	jng	else_block

# execution of if block  if n1 > n2 => sum = n1 - n2

	movl	n1, %eax
	movl	n2, %edx
	subl	%edx, %eax
	movl	%eax, sum

	jmp	end_of_else

else_block:

# execution of else block if n1 !> n2 => sum = n1 + n2
	movl	n1, %eax
	movl	n2, %edx
	addl	%edx, %eax
	movl	%eax, sum

end_of_else:

# printf("sum = %d\n", sum);
	pushl	sum
	pushl	$msgP4
	call	printf
	addl	$8, %esp

# puts("End of program");
	pushl	$msgP5
	call	puts
	addl	$4, %esp

# exit(0)
	pushl	$0
	call	exit
 
