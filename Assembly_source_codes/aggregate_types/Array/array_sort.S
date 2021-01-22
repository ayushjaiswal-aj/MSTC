.section .rodata
	msgP1:
	.string "Array before sort:\n"

	msgP2:	
	.string "Array after sort:\n"

	msgP3:
	.string "A[%d]: %d\n"

.section .data
	A:
	.int	12, 5, 65, 36, 72, 87, 30, 29

.section .bss
	.comm	i, 4, 4
	.comm	j, 4, 4
	.comm	temp, 4, 4
	.comm	min_index, 4, 4

.section .text
.global main

main:
	# Prologue
	pushl	%ebp
	movl	%esp, %ebp

	pushl	$msgP1
	call	printf
	addl	$4, %esp

	movl	$0, i
	jmp	array_before_sort_print_loop_condition

array_before_sort_print_loop_body:

	movl	i, %eax
	movl	A(, %eax, 4), %edx
	
	pushl	%edx
	pushl	i
	pushl	$msgP3
	call	printf
	addl	$12, %esp

	addl	$1, i

array_before_sort_print_loop_condition:
	
	movl	i, %eax
	cmpl	$8, %eax
	jl	array_before_sort_print_loop_body
	
	movl	$0, i
	jmp	outer_sort_loop_condition

outer_sort_loop_body:

	movl	i, %eax
	movl	%eax, j

	movl	%eax, min_index

	jmp	inner_sort_loop_condition

inner_sort_loop_body:

	# storing jth index value in current_element
	movl	j, %eax
	movl	A(, %eax, 4), %ebx

	# storing min_index th value in edx regi.
	movl	min_index, %eax
	movl	A(, %eax, 4), %edx

	# comparing values in ebx and edx registers
	
	cmpl	%edx, %ebx
	jnl	end_inner_loop

	# regi. is greater
	movl	j, %eax
	movl	%eax, min_index

end_inner_loop:
	
	addl	$1, j

inner_sort_loop_condition:

	movl	j, %eax
	cmpl	$8, %eax
	jl	inner_sort_loop_body
	
	# saving value of ith element in temp variable
	movl	i, %eax
	movl	A(, %eax, 4), %ebx
	movl	%ebx, temp

	# moving value of min_index th element in edx regi.
	movl	min_index, %eax
	movl	A(, %eax, 4), %edx
	
	# storing min_index th element value in i th index of array
	movl	i, %eax
	movl	%edx, A(, %eax, 4)

	# value from temp is stored in min_index th location of array
	movl	temp, %edx
	movl	min_index, %eax
	movl	%edx, A(, %eax, 4)

	addl	$1, i

outer_sort_loop_condition:

	movl	i, %eax
	cmpl	$7, %eax
	jl	outer_sort_loop_body

	pushl	$msgP2
	call	printf
	addl	$4, %esp

	movl	$0, i
	jmp	array_after_sort_print_loop_condition

array_after_sort_print_loop_body:

	movl	i, %eax
	movl	A(, %eax, 4), %edx

	pushl	%edx
	pushl	i
	pushl	$msgP3
	call	printf
	addl	$12, %esp

	addl	$1, i	

array_after_sort_print_loop_condition:

	movl 	i, %eax
	cmpl	$8, %eax
	jl	array_after_sort_print_loop_body

	pushl	$0
	call	exit
