	.file	"Ex69.c"
	.section	.text.unlikely,"ax",@progbits
.LCOLDB0:
	.text
.LHOTB0:
	.p2align 4,,15
	.globl	test
	.type	test, @function
test:
.LFB0:
	.cfi_startproc
	leaq	(%rdi,%rdi,4), %rdx
	movslq	8(%rsi,%rdx,8), %rax
	addq	%rax, %rdx
	movl	288(%rsi), %eax
	addl	(%rsi), %eax
	cltq
	movq	%rax, 16(%rsi,%rdx,8)
	ret
	.cfi_endproc
.LFE0:
	.size	test, .-test
	.section	.text.unlikely
.LCOLDE0:
	.text
.LHOTE0:
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.10) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
