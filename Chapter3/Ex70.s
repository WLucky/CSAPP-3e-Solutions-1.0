	.file	"Ex70.c"
	.text
	.globl	proc
	.type	proc, @function
proc:
.LFB0:
	.cfi_startproc
	movq	8(%rdi), %rdx
	movq	(%rdx), %rax
	movq	(%rax), %rax
	subq	8(%rdx), %rax
	movq	%rax, (%rdi)
	ret
	.cfi_endproc
.LFE0:
	.size	proc, .-proc
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.10) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
