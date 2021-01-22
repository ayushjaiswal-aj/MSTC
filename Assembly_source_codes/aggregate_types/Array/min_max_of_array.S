.section .rodata
	msgP1:
	.string "A[%d]: "
	
	msgP2:
	.string "Max index: %d\n"

	msgP3:
	.string "Max value: %d\n"

	msgP4:
	.string "min index: %d\n"
	
	msgP5:
	.string "min value: %d\n"

	msgS1:
	.string "%d"
.section .bss
	.comm	current_element, 4, 4
	.comm	A, 20, 4
	.comm	i, 4 ,4
	.comm	max_index, 4, 4
	.comm	max_value, 4, 4
	.comm	min_index, 4, 4
	.comm	min_value, 4, 4

.section .text
.global	main
main:
	pushl	%ebp
	movl	%esp, %ebp

	movl	$0, i
	jmp	array_filling_loop_condition

array_filling_loop_body:
	
	pushl	i
	pushl	$msgP1
	call	printf
	addl	$8, %esp

	pushl	$current_element
	pushl	$msgS1
	call	scanf
	addl	$8, %esp

	movl	i, %eax
	movl	current_element, %edx
	movl	%edx, A(, %eax, 4)
	
	addl	$1, i

array_filling_loop_condition:
	
	movl	i, %eax
	cmpl	$5, %eax
	jl	array_filling_loop_body

# finding max and min in array

	movl	$0, %eax
	movl	A(, %eax, 4), %edx
	movl	%edx, min_value			#setting 0th as minimum value
	movl	$0, min_index			#setting 0 minimum index	

	movl	$0, %eax
	movl	A(, %eax, 4), %edx
	movl	%edx, max_value			#setting 0th as max value
	movl	$0, max_index			#setting 0 as maximum index

	movl	$1, i
	jmp	loop_max_min_condition

loop_max_min_body:

	movl	i, %eax
	movl	A(, %eax, 4), %edx
	movl	min_value, %eax

	jmp 	min_if_condition

min_if_body:
	movl	%edx, min_value
	movl	i, %eax
	movl	%eax, min_index

	jmp	end_of_min_max_loop

min_if_condition:

	cmpl	%eax, %edx
	jl	min_if_body
	
	jmp	max_if_condition

max_if_body:

	movl	%edx, max_value
	movl	i, %eax
	movl	%eax, max_index

	jmp	end_of_min_max_loop

max_if_condition:

	movl	i, %eax
	movl	A(, %eax, 4), %edx
	movl	max_value, %eax
	
	cmpl	%eax, %edx
	jg	max_if_body	

end_of_min_max_loop:
	
	addl	$1, i	

loop_max_min_condition:
	
	movl	i, %eax
	cmpl	$5, %eax
	jl	loop_max_min_body

# printing min max values and indexes

	pushl	max_index
	pushl	$msgP2
	call	printf
	addl	$8, %esp

	pushl	max_value
	pushl	$msgP3
	call	printf
	addl	$8, %esp
	
	pushl	min_index
	pushl	$msgP4
	call	printf
	addl	$8, %esp
	
	pushl	min_value
	pushl	$msgP5
	call	printf
	addl	$8, %esp

	pushl	$0
	call	exit

