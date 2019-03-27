	.file	"Ex64.c"
	.text
	.globl	store_ele
	.type	store_ele, @function
store_ele:
.LFB0:
	.cfi_startproc
	leaq	(%rsi,%rsi,2), %rax
	leaq	(%rsi,%rax,4), %rax
	movq	%rdi, %rsi
	salq	$6, %rsi
	addq	%rsi, %rdi
	addq	%rax, %rdi
	addq	%rdx, %rdi
	movq	A(,%rdi,8), %rax
	movq	%rax, (%rcx)
	movl	$3640, %eax
	ret
	.cfi_endproc
.LFE0:
	.size	store_ele, .-store_ele
	.comm	A,3640,32
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.10) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
