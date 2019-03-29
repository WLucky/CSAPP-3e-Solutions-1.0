	.file	"Ex65.c"
	.text
	.globl	transpose
	.type	transpose, @function
transpose:
.LFB0:
	.cfi_startproc
	leaq	120(%rdi), %r10
	leaq	8(%rdi), %r9
	subq	$-128, %rdi
	movl	$0, %r8d
	jmp	.L2
.L6:
	movq	%r9, %rdx
	movq	%r10, %rax
.L3:
	movq	(%rax), %rcx
	movq	(%rdx), %rsi
	movq	%rsi, (%rax)
	movq	%rcx, (%rdx)
	addq	$8, %rax
	addq	$120, %rdx
	cmpq	%rdi, %rax
	jne	.L3
.L5:
	addq	$120, %r10
	addq	$8, %r9
	subq	$-128, %rdi
.L2:
	addq	$1, %r8
	cmpq	$15, %r8
	je	.L1
	testq	%r8, %r8
	jg	.L6
	jmp	.L5
.L1:
	rep ret
	.cfi_endproc
.LFE0:
	.size	transpose, .-transpose
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.10) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
