.equ	SIZE, 10
.section .rodata
	msgP1:
	.string	"Enter a[%d]:"

	msgP2:
	.string "before sort:"
	
	msgP3:
	.string "a[%d]: %d\n"

	msgP4:
	.string "After sort:"

	msgS1:
	.string "%d"

	proof:	
	.string "Through assembly!"

.section .text

.global main
.type	main, @function

main:

	pushl	%ebp
	movl	%esp, %ebp

	subl	$52, %esp

	movl	$0, -44(%ebp)
	jmp	scan_arr_condition

scan_arr_body:

	movl	-44(%ebp), %eax

	pushl	%eax
	pushl	$msgP1
	call	printf
	addl	$8, %esp

	movl	-44(%ebp), %eax
	leal	-40(%ebp, %eax, 4), %edx
	
	pushl	%edx
	pushl	$msgS1
	call	scanf
	addl	$8, %esp

	addl	$1, -44(%ebp)

scan_arr_condition:

	movl	-44(%ebp), %eax
	cmpl	$SIZE, %eax
	jl	scan_arr_body

	pushl	$msgP2
	call	puts
	addl	$4, %esp
	
	movl	$0, -44(%ebp)
	jmp	print_arr_1_condition

print_arr_1_body:
	
	movl	-44(%ebp), %eax
	movl	-40(%ebp, %eax, 4), %edx

	pushl	%edx
	pushl	%eax
	pushl	$msgP3
	call	printf
	addl	$12, %esp

	addl	$1, -44(%ebp)

print_arr_1_condition:

	movl	-44(%ebp), %eax
	cmpl	$SIZE, %eax
	jl	print_arr_1_body
	
	movl	$1, -48(%ebp)
	jmp	sort_outer_condition

sort_outer_body:

	movl	-40(%ebp, %eax, 4), %edx
	movl	%edx, -52(%ebp)
	
	movl	%eax, %edx
	subl	$1, %edx
	movl	%edx, -44(%ebp)

	jmp	sort_inner_condition

	sort_inner_body:
		
		movl	-44(%ebp), %eax
		movl	-40(%ebp, %eax, 4), %edx
		addl	$1, %eax
		movl	%edx, -40(%ebp, %eax, 4)

		subl	$1, -44(%ebp)

	sort_inner_condition:
		
		movl	-44(%ebp), %eax
		cmpl	$-1, %eax
		jng	sort_inner_out

		movl	-40(%ebp, %eax, 4), %edx
		cmpl	-52(%ebp), %edx
		jg	sort_inner_body

sort_inner_out:
	
	movl	-52(%ebp), %edx
	movl	-44(%ebp), %eax
	addl	$1, %eax
	movl	%edx, -40(%ebp, %eax, 4)

	addl	$1, -48(%ebp)

sort_outer_condition:

	movl	-48(%ebp), %eax
	cmpl	$SIZE, %eax
	jl	sort_outer_body

	pushl	$msgP4
	call	puts
	addl	$4, %esp

	movl	$0, -44(%ebp)
	jmp	print_arr_2_condition

print_arr_2_body:

	movl	-40(%ebp, %eax, 4), %edx	
	pushl	%edx
	pushl	%eax
	pushl	$msgP3
	call	printf
	addl	$12, %esp

	addl	$1, -44(%ebp)

print_arr_2_condition:
	movl	-44(%ebp), %eax
	cmpl	$SIZE, %eax
	jl	print_arr_2_body

	pushl	$proof
	call	puts
	addl	$4, %esp
	
	pushl	$0
	call	exit
