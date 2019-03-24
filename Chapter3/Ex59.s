	.file	"Ex59.c"
	.text
	.globl	store_prod
	.type	store_prod, @function
store_prod:
.LFB0:
	.cfi_startproc
	movq	%rsi, %rax
	movq	%rdx, %rsi
	movq	%rdx, %rcx
	sarq	$63, %rcx
	cqto
	imulq	%rsi, %rdx
	imulq	%rax, %rcx
	addq	%rdx, %rcx
	mulq	%rsi
	addq	%rcx, %rdx
	movq	%rax, (%rdi)
	movq	%rdx, 8(%rdi)
	ret
	.cfi_endproc
.LFE0:
	.size	store_prod, .-store_prod
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.10) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
