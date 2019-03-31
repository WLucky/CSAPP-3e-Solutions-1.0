	.file	"Ex68.c"
	.section	.text.unlikely,"ax",@progbits
.LCOLDB0:
	.text
.LHOTB0:
	.p2align 4,,15
	.globl	setVal
	.type	setVal, @function
setVal:
.LFB0:
	.cfi_startproc
	movslq	8(%rsi), %rax
	addq	32(%rsi), %rax
	movq	%rax, 184(%rdi)
	ret
	.cfi_endproc
.LFE0:
	.size	setVal, .-setVal
	.section	.text.unlikely
.LCOLDE0:
	.text
.LHOTE0:
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.10) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
