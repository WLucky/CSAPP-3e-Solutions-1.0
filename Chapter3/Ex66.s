	.file	"Ex66.c"
	.text
	.globl	sum_col
	.type	sum_col, @function
sum_col:
.LFB0:
	.cfi_startproc
	leaq	1(,%rdi,4), %r9
	movl	$0, %eax
	movl	$0, %ecx
	jmp	.L2
.L3:
	movq	%rcx, %r8
	imulq	%r9, %r8
	leaq	(%rsi,%r8,8), %r8
	addq	(%r8,%rdx,8), %rax
	addq	$1, %rcx
.L2:
	leaq	(%rdi,%rdi,2), %r8
	cmpq	%r8, %rcx
	jl	.L3
	rep ret
	.cfi_endproc
.LFE0:
	.size	sum_col, .-sum_col
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.10) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
